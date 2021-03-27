#include "../batch_norm/batch_norm_layer.h"
#include "../util/data_structs.h"

#define MAX_POOL_1_BATCHES 1
#define MAX_POOL_1_OUTPUT_DIM BATCH_NORM_1_INPUT_DIM
#define MAX_POOL_1_INPUT_X CONV1_OUTPUT_X
#define MAX_POOL_1_INPUT_Y CONV1_OUTPUT_Y
#define MAX_POOL_1_OUTPUT_X (CONV1_OUTPUT_X/2 + CONV1_OUTPUT_X%2)
#define MAX_POOL_1_OUTPUT_Y (CONV1_OUTPUT_Y/2 + CONV1_OUTPUT_Y%2)

#define MAX_POOL_2_BATCHES 1
#define MAX_POOL_2_OUTPUT_DIM BATCH_NORM_2_INPUT_DIM
#define MAX_POOL_2_INPUT_X CONV2_OUTPUT_X
#define MAX_POOL_2_INPUT_Y CONV2_OUTPUT_Y
#define MAX_POOL_2_OUTPUT_X (CONV2_OUTPUT_X/2 + CONV2_OUTPUT_X%2)
#define MAX_POOL_2_OUTPUT_Y (CONV2_OUTPUT_Y/2 + CONV2_OUTPUT_Y%2)

#define MAX_POOL_3_BATCHES 1
#define MAX_POOL_3_OUTPUT_DIM BATCH_NORM_3_INPUT_DIM
#define MAX_POOL_3_INPUT_X CONV3_OUTPUT_X
#define MAX_POOL_3_INPUT_Y CONV3_OUTPUT_Y
#define MAX_POOL_3_OUTPUT_X (CONV3_OUTPUT_X/2 + CONV3_OUTPUT_X%2)
#define MAX_POOL_3_OUTPUT_Y (CONV3_OUTPUT_Y/2 + CONV3_OUTPUT_Y%2)

void max_pool(result_t * input, 		// where to get inputs
				result_t * output,		// where to store outputs
                const int od,           // number of outputs
                const int ox,           // output width
                const int oy,           // output height
                const int ix,           // input width
                const int iy);           // input height