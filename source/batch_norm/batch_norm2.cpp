#include <float.h>
#include "../batch_norm_layer.h"
//#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "../../util/fixed_point.h"
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_utils.h"


#define b BATCH_NORM_2_BATCHES
#define id BATCH_NORM_2_INPUT_DIM
#define ix BATCH_NORM_2_INPUT_X
#define iy BATCH_NORM_2_INPUT_Y


void batch_norm2(hls::stream<result_t>& input, 		// where to get inputs
		         hls::stream<result_t>& output)		// where to store outputs
{
 
//#pragma HLS DATAFLOW
#pragma HLS INTERFACE ap_ctrl_none port=return //causes it to be always active
#pragma HLS INTERFACE axis port=input bundle=input_stream
#pragma HLS INTERFACE axis port=output bundle=output_stream

//	result_t input_array[b*id*ix*iy];
//
//
//	  for (int input_size=0; input_size<b*id*ix*iy; input_size++) {
//		      input_array[input_size] = input.read();
//	  }


	int num_input = b*id*ix*iy;
	int num_output = num_input;
	int offset = 0;

	result_t input_val;

	// Batch - most likely always 1
	for (int b_=0; b_< b; b_++)
//#pragma HLS UNROLL factor=1
{


		// Number of inputs - ie number of outputs produced by previous conv layer
		for (int i_d = 0; i_d < id; i_d++)
//#pragma HLS UNROLL factor=1
{
//#pragma HLS PIPELINE II=8

			//set gamma, beta, mean, variance - 4 different params for each "filter"
			gamma_t gamma = batchnorm_weights2[offset/sizeof(gamma_t) + b_*id*4 + i_d*4];
			beta_t beta = batchnorm_weights2[offset/sizeof(beta_t) + b_*id*4 + i_d*4 + 1];
			mean_t mean = batchnorm_weights2[offset/sizeof(mean_t) + b_*id*4 + i_d*4 + 2];
			var_t var = batchnorm_weights2[offset/sizeof(var_t) + b_*id*4 + i_d*4 + 3];
			
			// Input Y Dimension
			for (int i_y = 0; i_y < iy; i_y++)
//#pragma HLS UNROLL factor=1
{

				
				// Input X Dimension
				for (int i_x = 0; i_x < ix; i_x++)
//#pragma HLS UNROLL factor=2
{
//#pragma HLS PIPELINE II=4



						//input_val = input_array[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x];
					    input_val = input.read();
					    fixed_point_t numerator_1 = fixed_mult(gamma, input_val, NUM_FRAC_BITS);
					    fixed_point_t numerator_2 = fixed_mult(gamma, mean, NUM_FRAC_BITS);
					    fixed_point_t epsilon_fixed = float_to_fixed(EPSILON, NUM_FRAC_BITS);
					    fixed_point_t denominator = fixed_sqrt(var + epsilon_fixed, NUM_FRAC_BITS);
					    fixed_point_t output_result = fixed_div(numerator_1, denominator, NUM_FRAC_BITS) + beta - fixed_div(numerator_2, denominator, NUM_FRAC_BITS);
					    output.write(output_result);

				}
			}
		}	
	}


}
