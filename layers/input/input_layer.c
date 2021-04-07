#include "input_layer.h"
#include "../util/fixed_point.h"
#include "../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>

// #define INPUT_DEBUG

void input_layer(image_t * input, 		// where to get inputs
				result_t * output,		// where to store outputs
                const int b,            // batch size
                const int ix,           // input width
                const int iy)           // input height

{
	int i; 
	
	for (int b_ = 0; b_ < b; b_++){
		for (i = 0; i < ix*iy; i++){
			float input_val = input[b_*ix*iy + i];
			int32_t temp = float_to_fixed(input_val, NUM_FRAC_BITS);
			output[b_*ix*iy + i] = temp;
			
			#ifdef INPUT_DEBUG
			if (i == 0){
				printf("Input value: %f (float), converted value: %d (fixed)\n", input_val, temp);
			}
			#endif
		}
	}	
}