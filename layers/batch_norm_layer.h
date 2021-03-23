#include "conv_layer.h"

#define EPSILON 0.001

// Batch norm 1
#define BATCH_NORM_1_INPUT_X CONV1_OUTPUT_X
#define BATCH_NORM_1_INPUT_Y CONV1_OUTPUT_Y
#define BATCH_NORM_1_OUTPUT_X BATCH_NORM_1_INPUT_X
#define BATCH_NORM_1_OUTPUT_Y BATCH_NORM_1_INPUT_X

// Batch norm 2
#define BATCH_NORM_2_INPUT_X CONV2_OUTPUT_X
#define BATCH_NORM_2_INPUT_Y CONV2_OUTPUT_Y
#define BATCH_NORM_2_OUTPUT_X BATCH_NORM_2_INPUT_X
#define BATCH_NORM_2_OUTPUT_Y BATCH_NORM_2_INPUT_X

// Batch norm 3
#define BATCH_NORM_3_INPUT_X CONV3_OUTPUT_X
#define BATCH_NORM_3_INPUT_Y CONV3_OUTPUT_Y
#define BATCH_NORM_3_OUTPUT_X BATCH_NORM_3_INPUT_X
#define BATCH_NORM_3_OUTPUT_Y BATCH_NORM_3_INPUT_X

void batch_norm(float * mem,         // global memory pointer (stores params)
				float * input, 		// where to get inputs
				float * output,		// where to store outputs
				int offset, 			// offset for biases, weights
                const int b,            // number of batches
                const int id,           // number of inputs (number of outputs from previous conv layer)
                const int ix,           // input width
                const int iy);           // input height