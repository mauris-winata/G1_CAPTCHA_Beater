// this file contains the definition of the dense layer within the CNN

#include "dense_layer.h"


void dense_layer(float* mem, // global pointer to weights and biases
	float* input,  // pointer to the input data for the current layer
	float* output, // poimter to the output buffer for resulting data
	int offset, // location of the weights and biases for the current layer
	int b, // batch size of the input data
	int ix, // input data size (length after arriving from flatten layer, 1xid)
	int ox // output data size (length after leaving dense layer, 1xod)
)
{
	// useful input data information
	int num_weights = ix * ox;

	// start with the batch size
	for (int b_ = 0; b_ < b; b_++)
	{
		// output dimension
		for (int o_x = 0; o_x < ox; o_x++)
		{
			float output_data = mem[offset / sizeof(float) + num_weights + o_x]; // handle bias here. (one bias per output)

			// handle the dot product per output
			for (int i_x = 0; i_x < ix; i_x++) 
			{
				output_data += input[b_ * ix + i_x] * mem[offset / sizeof(float) + i_x * ox + o_x]; 
			}

			output[b_*ox + o_x] = output_data;
		}
	}

	return;
}