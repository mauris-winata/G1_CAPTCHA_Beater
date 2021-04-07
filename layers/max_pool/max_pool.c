#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "max_pool_layer.h"
#include "../util/data_structs.h"
#include <stdint.h>
#include <math.h>

// #define MAX_POOL_DEBUG

void max_pool(result_t * input, 		// where to get inputs
				result_t * output,		// where to store outputs
                const int od,           // number of outputs (same as input dimensions)
                const int ox,           // output width
                const int oy,           // output height
                const int ix,           // input width
                const int iy)           // input height
{
	#ifdef MAX_POOL_DEBUG
	int output_count = 0;
	#endif
	
	// Number of outputs
	for (int o_d = 0; o_d < od; o_d++)
	{
		// Output Y Dimension
		for (int o_y = 0; o_y < oy; o_y++)
		{
			// Output X Dimension
			for (int o_x = 0; o_x < ox; o_x++)
			{
				//2x2 filter with stride of 2
				result_t pixel_0 = input[o_d*ix*iy + 2*o_y*ix + 2*o_x]; //top left
				result_t pixel_1 = input[o_d*ix*iy + 2*o_y*ix + 2*o_x + 1]; //top right
				result_t pixel_2 = input[o_d*ix*iy + (2*o_y + 1)*ix + 2*o_x]; //bot left
				result_t pixel_3 = input[o_d*ix*iy + (2*o_y + 1)*ix + 2*o_x + 1]; //bot right

				#ifdef MAX_POOL_DEBUG
				if (o_d == 0 && o_y == 0 && o_x == 0){
				printf("p0: %d, p1: %d, p2: %d, p3: %d \n", pixel_0, pixel_1, pixel_2, pixel_3);
				}
				#endif

				//Checking if still in bounds of image
				if (2*o_y + 1 > iy - 1){
				  pixel_2 = -2147483648;
				  pixel_3 = -2147483648;
				}

				if (2*o_x + 1 > ix - 1){
				  pixel_1 = -2147483648;
				  pixel_3 = -2147483648;
				}

				// Write output
				output[o_d*ox*oy + o_y*ox + o_x] = MAX(MAX(pixel_0, pixel_1), MAX(pixel_2, pixel_3));
								
				#ifdef MAX_POOL_DEBUG
				output_count++;
				if (output_count == 30000){
					printf("Output is %d\n", MAX(MAX(pixel_0, pixel_1), MAX(pixel_2, pixel_3)));
					printf("Input dims: ix = %d, iy = %d\n", ix, iy);
					printf("Output coordinates: %d,%d at dim %d\n", o_x, o_y, o_d);
					printf("Inputs: %d, %d, %d, %d\n", pixel_0, pixel_1, pixel_2, pixel_3);
					printf("Input indexes: %d, %d, %d, %d\n", 
						o_d*ix*iy + 2*o_y*ix + 2*o_x, 
						o_d*ix*iy + 2*o_y*ix + 2*o_x + 1, 
						o_d*ix*iy + (2*o_y + 1)*ix + 2*o_x,
						o_d*ix*iy + (2*o_y + 1)*ix + 2*o_x + 1);
				}
				#endif				
			}
		}
	}
}
