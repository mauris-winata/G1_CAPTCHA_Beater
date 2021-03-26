#include <float.h>
#include "batch_norm_layer.h"
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define SW_TEST

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

	// Batch - most likely always 1
	for (int b_=0; b_< b; b_++){
	
		// Number of inputs - ie number of outputs produced by previous conv layer
		for (int i_d = 0; i_d < id; i_d++){

			//set gamma, beta, mean, variance - 4 different params for each "filter"
			float gamma = mem[offset/sizeof(float) + b_*id*4 + id*4]; 	
			float beta = mem[offset/sizeof(float) + b_*id*4 + id*4 + 1];
			float mean = mem[offset/sizeof(float) + b_*id*4 + id*4 + 2];
			float var = mem[offset/sizeof(float) + b_*id*4 + id*4 + 3];
			
			// Input Y Dimension
			for (int i_y = 0; i_y < iy; i_y++){
				
				// Input X Dimension
				for (int i_x = 0; i_x < ix; i_x++){

					//access the input array; offset is: batch + current input + row + column
					float input_val = input[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x];

					// Write output (one for every input)
					output[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x] = gamma*input_val/sqrt(var + EPSILON) + beta - gamma*mean/sqrt(var + EPSILON); 
					
					#ifdef SW_TEST
					output_count++;
					#endif
				}
			}
		}	
	}
	
	#ifdef SW_TEST
	// printf("Num output = %d, output_count = %d\n", num_output, output_count);
	assert(num_output == output_count);
	#endif
}