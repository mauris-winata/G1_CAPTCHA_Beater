#include "../util/fixed_point.h"
#include "../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>

void input_layer(image_t * input, 		// where to get inputs
				result_t * output,		// where to store outputs
                const int b,            // batch size
                const int ix,           // input width
                const int iy);           // input height