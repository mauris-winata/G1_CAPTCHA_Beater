// this file contains the definition of the soft max layer within the CNN (occurs after the dense layer)

#include "soft_max_layer.h"

void soft_max_layer(result_t* input,  // pointer to the input data for the current layer
	result_t* output, // poimter to the output buffer for resulting data
	int b, // batch size of the input data
	int ix, // input data dimension (length after arriving from flatten layer, 1xid)
	int ox // output data dimension (length after leaving dense layer, 1xod)
)
{

	// start with the batches
	for (int b_ = 0; b_ < b; b_++)
	{
		float output_result_sum = 0;
		
		// update values based on the output dimension
		for (int o_x = 0; o_x < ox; o_x++)
		{
			float intermediate_result = (float)exp(input[b_ * ox + o_x]); // initial step of softmax operation
			output_result_sum += intermediate_result;
			output[b_ * ox + o_x] = intermediate_result;
		}

		// perform the final softmax layer calculation
		for (int o_x = 0; o_x < ox; o_x++)
		{
			output[b_ * ox + o_x] /= output_result_sum;
		}
	}

	return;
}