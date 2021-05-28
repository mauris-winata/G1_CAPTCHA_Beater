#include "../../util/fixed_point.h"
#include "../../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>

#define INPUT_BATCH_SIZE 1
#define INPUT_IMAGE_WIDTH 150
#define INPUT_IMAGE_HEIGHT 50

void input_layer(image_t * input_image,
		         result_t * output);		// where to store outputs
