// this file contains the definition of the dense layer within the CNN that comes
// immediately after the max pool layer

#include "max_pool_dense_layer.h"

void max_pool_dense_layer(weights_biases_t* mem, // global pointer to weights and biases
	result_t* input,  // pointer to the input data for the current layer
	result_t* output, // poimter to the output buffer for resulting data
	int offset, // location of the weights and biases for the current layer
	int b, // batch size of the input data
	int id, // dimensions of the input
	int ix, // input data x dimension (length after arriving from flatten layer, 1xid)
	int iy, // input data y dimension
	int ox // output data dimension (length after leaving dense layer, 1xod)
)
{

	// useful input data information
	int num_weights = id * ix * iy * ox; 

	// start with the batch size
	for (int b_ = 0; b_ < b; b_++)
	{
		// output dimension
		for (int o_x = 0; o_x < ox; o_x++)
		{
			float output_data = mem[offset / sizeof(float) + num_weights + o_x]; // handle bias here. (one bias per output)

			// input dimension
			for (int i_d = 0; i_d < id; i_d++)
			{

				// input y position
				for (int i_y = 0; i_y < iy; i_y++)
				{

					// input x dimension
					for (int i_x = 0; i_x < ix; i_x++)
					{
						output_data += input[b_*i_d*iy*ix + i_d*iy*ix + i_y*ix + i_x] * // indexing each output from the max pool layer
							mem[offset / sizeof(float) + (i_y*ix*id + i_x*id + i_d)*ox + o_x]; // accessing the approriate weight
					}	
				}
			}

			// default use of this layer would be RELu activation function
			output[b_ * ox + o_x] = MAX(0, output_data);
			
		}

	}

	return;
}