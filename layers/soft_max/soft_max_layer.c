// this file contains the definition of the soft max layer within the CNN (occurs after the dense layer)

#include "soft_max_layer.h"
#include "../util/fixed_point.h"
#include <stdio.h>
#include <stdlib.h>

void soft_max_layer(result_t* input,  // pointer to the input data for the current layer
	result_t* output, // poimter to the output buffer for resulting data
	int b, // batch size of the input data
	int ix, // input data dimension (length after arriving from flatten layer, 1xid)
	int ox // output data dimension (length after leaving dense layer, 1xod)
)
{

	float* intermediate_result = (float*)malloc(sizeof(float) * ox);

	// start with the batches
	for (int b_ = 0; b_ < b; b_++)
	{
		float output_result_sum = 0;
		
		// update values based on the output dimension
		for (int o_x = 0; o_x < ox; o_x++)
		{
			result_t input_val = input[b_ * ox + o_x];
			intermediate_result[o_x] = (float)exp(fixed_to_float(input_val, NUM_FRAC_BITS));
			
			output_result_sum += intermediate_result[o_x];
		}

		printf("\n\n");
		// perform the final softmax layer calculation
		for (int o_x = 0; o_x < ox; o_x++)
		{
			intermediate_result[o_x] /= output_result_sum;			
			output[b_ * ox + o_x] = (result_t) float_to_fixed(intermediate_result[o_x], NUM_FRAC_BITS);
		}
	}
	free(intermediate_result);
	return;
}