// this file contains the definition of the dense layer within the CNN

#include "dense_layer_hls.h"
#include "../util/fixed_point.h"


void dense_layer_four(
	hls::stream<result_t>& input,  // pointer to the input data for the current layer
	hls::stream<result_t>& output // pointer to the output buffer for resulting data
)
{

#pragma HLS DATAFLOW

// handling the hls stream interfaces
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=input bundle=input_stream
#pragma HLS INTERFACE axis port=output bundle=output_stream


// Bind all control ports to a single bundle

	// useful input data information
	result_t input_val;
	result_t out[19] = {};


// allocating the stored weights data dual port block ram
#pragma HLS resource variable=out core=RAM_T2P_BRAM latency=2
#pragma HLS resource variable=dense_weights_one core=ROM_2P_BRAM latency=2

	// start with the batch size
	for (int b_ = 0; b_ < 1; b_++)
	{
#pragma HLS loop_tripcount min=1 max=1 avg=1

		// process the input data
		for (int i_x = 0; i_x < 56; i_x++)
		{
#pragma HLS loop_tripcount min=56 max=56 avg=56


			input_val = input.read();


			for (int o_x = 0; o_x < 19; o_x++)
			{
#pragma HLS loop_tripcount min=19 max=19 avg=19
#pragma HLS pipeline II=1

				weights_biases_t weight = dense_weights_four[i_x * 19 + o_x];

				out[o_x] += fixed_mult(input_val, weight, NUM_FRAC_BITS);
			}
		}

		// write the output to the output axi stream

		input_val = input.read();


		for (int o_x = 0; o_x < 19; o_x++)
		{
#pragma HLS loop_tripcount min=19 max=19 avg=19
#pragma HLS pipeline II=1

			weights_biases_t weight = dense_weights_four[56 * 19 + o_x];
			weights_biases_t bias = dense_weights_four[1083 + o_x];

			out[o_x] += fixed_mult(input_val, weight, NUM_FRAC_BITS);
			out[o_x] += bias;

			output.write(out[o_x]);
		}

	}

	return;
}
