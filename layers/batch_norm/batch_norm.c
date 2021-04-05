#include <float.h>
#include "batch_norm_layer.h"
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "../util/fixed_point.h"

#define SW_TEST
// #define BATCH_NORM_DEBUG


void batch_norm(weights_biases_t * mem, // global memory pointer (stores params)
				result_t * input, 		// where to get inputs
				result_t * output,		// where to store outputs
				int offset, 			// offset for biases, weights
                const int b,            // number of batches
                const int id,           // number of inputs (number of outputs from previous conv layer)
                const int ix,           // input width
                const int iy)           // input height
				
{
 
	int num_input = b*id*ix*iy;
	int num_output = num_input;
	
	#ifdef SW_TEST
	int output_count = 0;
	#endif
	
	result_t input_val;
	
	#ifdef BATCH_NORM_DEBUG
	fixed_point_t temp_output;
	gamma_t temp_gamma;
	beta_t temp_beta;
	mean_t temp_mean;
	var_t temp_var;
	result_t temp_input;
	#endif

	// Batch - most likely always 1
	for (int b_=0; b_< b; b_++){
	
		// Number of inputs - ie number of outputs produced by previous conv layer
		for (int i_d = 0; i_d < id; i_d++){

			//set gamma, beta, mean, variance - 4 different params for each "filter"
			gamma_t gamma = mem[offset/sizeof(gamma_t) + b_*id*4 + i_d*4]; 	
			beta_t beta = mem[offset/sizeof(beta_t) + b_*id*4 + i_d*4 + 1];
			mean_t mean = mem[offset/sizeof(mean_t) + b_*id*4 + i_d*4 + 2];
			var_t var = mem[offset/sizeof(var_t) + b_*id*4 + i_d*4 + 3];
			
			#ifdef BATCH_NORM_DEBUG
			if (i_d == 0 && b_ == 0){
				temp_gamma = gamma;
				temp_beta = beta;
				temp_mean = mean;
				temp_var = var;
			}
			#endif
			
			// Input Y Dimension
			for (int i_y = 0; i_y < iy; i_y++){
				
				// Input X Dimension
				for (int i_x = 0; i_x < ix; i_x++){

					//access the input array; offset is: batch + current input + row + column
					input_val = input[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x];
					
					// Write output (one for every input)
					fixed_point_t numerator_1 = fixed_mult(gamma, input_val, NUM_FRAC_BITS);
					fixed_point_t numerator_2 = fixed_mult(gamma, mean, NUM_FRAC_BITS);
					fixed_point_t epsilon_fixed = float_to_fixed(EPSILON, NUM_FRAC_BITS);
					fixed_point_t denominator = fixed_sqrt(var + epsilon_fixed, NUM_FRAC_BITS); 
					output[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x] = fixed_div(numerator_1, denominator, NUM_FRAC_BITS) + beta - fixed_div(numerator_2, denominator, NUM_FRAC_BITS);
					// output[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x] = gamma*input_val/sqrt(var + EPSILON) + beta - gamma*mean/sqrt(var + EPSILON);

					#ifdef BATCH_NORM_DEBUG	
					if (i_d == 0 && b_ == 0){					
						temp_output = denominator; 
						temp_input = input_val;
					}
					#endif
					
					#ifdef SW_TEST
					output_count++;
					#endif
				}
			}
		}	
	}
	
	#ifdef BATCH_NORM_DEBUG
	// printf("Final output is: %f, final input is: %f\n", temp_output, temp_input);
	printf("Gamma: %d, beta: %d, mean: %d, var: %d\n", temp_gamma, temp_beta, temp_mean, temp_var);
	printf("Temp output is: %d, temp input is %d\n", temp_output, temp_input);
	#endif
	
	#ifdef SW_TEST
	assert(num_output == output_count);
	#endif
}