#include "output_layer.h"
#include "../../util/fixed_point.h"
#include "../../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "ap_utils.h"
#include "hls_stream.h"
#include "ap_int.h"


void output_memory(hls::stream<float>&input_1,
		   hls::stream<float>&input_2,
		   hls::stream<float>&input_3,
	           hls::stream<float>&input_4,
                   hls::stream<float>&input_5,
                   float* output)
{
#pragma HLS DATAFLOW

// handling hls stream interfaces
#pragma HLS INTERFACE axis port=input_1 bundle=input_stream_1
#pragma HLS INTERFACE axis port=input_2 bundle=input_stream_2
#pragma HLS INTERFACE axis port=input_3 bundle=input_stream_3
#pragma HLS INTERFACE axis port=input_4 bundle=input_stream_4
#pragma HLS INTERFACE axis port=input_5 bundle=input_stream_5
#pragma HLS INTERFACE m_axi port=output bundle=output_stream depth=10
#pragma HLS INTERFACE ap_ctrl_none port=return

	// storage variables
	float i_1;
	float i_2;
	float i_3;
	float i_4;
	float i_5;

	for (int b_=0; b_<1; b_++)
	{
		//read in the first input
		i_1 = input_1.read();
		i_2 = input_2.read();
		i_3 = input_3.read();
		i_4 = input_4.read();
		i_5 = input_5.read();

		// write all these outputs 500 times
		for (int w_=0; w_ < 500; w_ += 5)
		{

			output[w_] = i_1;
			output[w_+1] = i_2;
			output[w_+2] = i_3;
			output[w_+3] = i_4;
			output[w_+4] = i_5;

		}

	}

	return;
}





