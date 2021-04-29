// this file contains the definition of the dense layer within the CNN that comes
// immediately after the max pool layer

#include "max_pool_dense_layer_hls.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"
#include "hls_stream.h"

void max_pool_dense_layer_one(
	hls::stream<result_t>& input,  // pointer to the input data for the current layer
	hls::stream<result_t>& output // pointer to the output buffer for resulting data
)
{
#pragma HLS DATAFLOW

// handling the hls stream interfaces
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=input bundle=input_stream
#pragma HLS INTERFACE axis port=output bundle=output_stream

	// useful input data information
	result_t read_input;
	weights_biases_t bias;

	result_t out[57] = {};

//#pragma HLS array_partition variable=out complete
#pragma HLS resource variable=out core=RAM_T2P_BRAM latency=2

#pragma HLS resource variable=max_pool_dense_weights_one core=ROM_2P_BRAM latency=1


	// start with the batch size
	for (int b_ = 0; b_ < 1; b_++)
	{
#pragma HLS loop_tripcount min=1 max=1

		// now we focus on the input image //
		// start with the input dimension
		for (int i_d = 0; i_d < 32; i_d++)
		{
#pragma HLS loop_tripcount min=32 max=32

			// looking at the input y position (row)
			for (int i_y = 0; i_y < 7; i_y++)
			{
#pragma HLS loop_tripcount min=7 max=7

				// now for each row we look at the x position (column)
				for (int i_x = 0; i_x < 19; i_x++)
				{
#pragma HLS loop_tripcount min=19 max=19

					// read the input from the previous layer
					read_input = input.read();

					// for each input, we need to do multiply it by the corresponding weight in each output dimension
					// do we iterate through each and every output dimension
					for (int o_x = 0; o_x < 57; o_x++)
					{
#pragma HLS loop_tripcount min=57 max=57
#pragma HLS pipeline II=1
						weights_biases_t weight = max_pool_dense_weights_one[(i_y*608 + i_x*32 + i_d)*57 + o_x];

						out[o_x] += fixed_mult(read_input, weight, NUM_FRAC_BITS);

					}
				}
			}
		}

		// write data to the output
		for (int o_b = 0; o_b < 57; o_b++)
		{
#pragma HLS pipeline II=1
			bias = max_pool_dense_weights_one[242592 + o_b];
			out[o_b] += bias;

			output.write(MAX(0, out[o_b]));
		}
	}

	return;
}
