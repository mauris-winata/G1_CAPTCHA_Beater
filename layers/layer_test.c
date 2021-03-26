#include <stdio.h>
#include <stdint.h>
#include "conv/conv_layer.h"
#include "dense/dense_layer.h"
#include "max_pool/max_pool_layer.h"
#include "batch_norm/batch_norm_layer.h"
#include "util/shared.h"
#include "util/data_structs.h"
#include "convolution_test/convolution_test.h"
#include "batch_norm_test/batch_norm_test.h"
#include "max_pool_test/max_pool_test.h"
#include "output/output_layer.h"

/* Input Image */
#define IMG_WIDTH 150
#define IMG_HEIGHT 50

/* Layers (turn on if required) */
#define CONV_1_LAYER
#define BATCH_NORM_1_LAYER
#define MAX_POOL_1_LAYER
// #define CONV_2_LAYER
// #define BATCH_NORM_2_LAYER
// #define MAX_POOL_2_LAYER
// #define CONV_3_LAYER
// #define BATCH_NORM_3_LAYER
// #define MAX_POOL_3_LAYER
// #define DENSE_1_LAYER
// #define DENSE_2_LAYER

int main(){
	
    int i,j;

	/* Conv Layer 1 */
    #ifdef CONV_1_LAYER

    layer_params convolution_layer_1 = { .batch_size = CONV1_BATCHES,
                                           .input_dim = CONV1_NUM_INPUTS,
                                           .input_height = CONV1_INPUT_Y,
                                           .input_width = CONV1_INPUT_X,
                                           .kernel_size = CONV1_KERNEL,
                                           .output_dim = CONV1_NUM_FILTERS,
                                           .output_height = CONV1_OUTPUT_Y,
                                           .output_width = CONV1_OUTPUT_X,
                                           .stride = CONV1_STRIDE };

    convolution_layer_test(CONVOLUTION_LAYER_1_TEST_INPUT_DATA, CONVOLUTION_LAYER_1_TEST_WEIGHTS_BIAS, CONVOLUTION_LAYER_1_TEST_GOLDEN_OUTPUT, 
	CONVOLUTION_LAYER_1_TEST_OUTPUT_DATA, 0, CONV_LAYER_1_NAME, convolution_layer_1);
	#endif
	
	/* Batch Norm Layer 1 */
	#ifdef BATCH_NORM_1_LAYER
    layer_params batch_norm_layer_1 = { .batch_size = BATCH_NORM_1_BATCHES,
                                           .input_dim = BATCH_NORM_1_INPUT_DIM,
                                           .input_height = BATCH_NORM_1_INPUT_Y,
                                           .input_width = BATCH_NORM_1_INPUT_X,
                                           .kernel_size = -1, //unused
                                           .output_dim = -1, //unused
                                           .output_height = -1, //unused
                                           .output_width = -1, //unused
                                           .stride = -1 }; //unused
										   
    batch_norm_layer_test(BATCH_NORM_LAYER_1_TEST_INPUT_DATA, BATCH_NORM_LAYER_1_TEST_WEIGHTS_BIAS, BATCH_NORM_LAYER_1_TEST_GOLDEN_OUTPUT, 
	BATCH_NORM_LAYER_1_TEST_OUTPUT_DATA, 0, BATCH_NORM_1_NAME, batch_norm_layer_1);
	#endif
	
	/* Max Pool Layer 1 */
	#ifdef MAX_POOL_1_LAYER
    layer_params max_pool_layer_1 = { .batch_size = BATCH_NORM_1_BATCHES,
                                           .input_dim = BATCH_NORM_1_INPUT_DIM,
                                           .input_height = BATCH_NORM_1_INPUT_Y,
                                           .input_width = BATCH_NORM_1_INPUT_X,
                                           .kernel_size = -1, //unused
                                           .output_dim = -1, //unused
                                           .output_height = -1, //unused
                                           .output_width = -1, //unused
                                           .stride = -1 }; //unused
										   
    max_pool_layer_test(MAX_POOL_LAYER_1_TEST_INPUT_DATA, MAX_POOL_LAYER_1_TEST_WEIGHTS_BIAS, MAX_POOL_LAYER_1_TEST_GOLDEN_OUTPUT, 
	MAX_POOL_LAYER_1_TEST_OUTPUT_DATA, 0, MAX_POOL_1_NAME, max_pool_layer_1);
	#endif
	
	/* Conv Layer 2 */
	#ifdef CONV_2_LAYER


	#endif


	
    return 0;
}