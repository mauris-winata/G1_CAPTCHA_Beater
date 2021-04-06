#include <stdio.h>
#include <stdint.h>
#include "conv/conv_layer.h"
#include "dense/dense_layer.h"
#include "soft_max/soft_max_layer.h"
#include "max_pool/max_pool_layer.h"
#include "batch_norm/batch_norm_layer.h"
#include "util/shared.h"
#include "util/data_structs.h"
#include "convolution_test/convolution_test.h"
#include "batch_norm_test/batch_norm_test.h"
#include "max_pool_test/max_pool_test.h"
#include "dense_test/dense_test.h"
#include "output/output_layer.h"
#include "dense/max_pool_dense_layer.h"
#include "dense_test/max_pool_dense_test.h"
#include "input_test/input_test.h"
#include "input/input_layer.h"

/* Input Image */
#define IMG_WIDTH 150
#define IMG_HEIGHT 50

/* Layers (turn on if required) */
#define INPUT_LAYER
#define CONV_1_LAYER
#define BATCH_NORM_1_LAYER
#define MAX_POOL_1_LAYER
#define CONV_2_LAYER
// #define BATCH_NORM_2_LAYER
// #define MAX_POOL_2_LAYER
// #define CONV_3_LAYER
// #define BATCH_NORM_3_LAYER
// #define MAX_POOL_3_LAYER
 
/* Dense layer is divided into 2 sets*/

// first dense layer set below
// #define MAX_POOL_DENSE_1_LAYER
// #define MAX_POOL_DENSE_2_LAYER
// #define MAX_POOL_DENSE_3_LAYER
// #define MAX_POOL_DENSE_4_LAYER
// #define MAX_POOL_DENSE_5_LAYER

// second dense layer set below
// #define DENSE_1_LAYER
// #define DENSE_2_LAYER
// #define DENSE_3_LAYER
// #define DENSE_4_LAYER
// #define DENSE_5_LAYER

int main(){

	/* Input Layer */
    #ifdef INPUT_LAYER
    layer_params input_layer = { .batch_size = 1,
                                           .input_dim = -1,
                                           .input_height = IMG_HEIGHT,
                                           .input_width = IMG_WIDTH,
                                           .kernel_size = -1,
                                           .output_dim = -1,
                                           .output_height = -1,
                                           .output_width = -1,
                                           .stride = -1 };

    input_layer_test(INPUT_LAYER_INPUT_DATA, INPUT_LAYER_WEIGHTS_BIASES, INPUT_LAYER_GOLDEN_OUTPUT_DATA, 
	INPUT_LAYER_OUTPUT_DATA, 0, INPUT_LAYER_NAME, input_layer);
	#endif	

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
    layer_params max_pool_layer_1 = { .batch_size = MAX_POOL_1_BATCHES,
                                           .input_dim = -1,
                                           .input_height = MAX_POOL_1_INPUT_Y,
                                           .input_width = MAX_POOL_1_INPUT_X,
                                           .kernel_size = -1, //unused
                                           .output_dim = 16, //unused
                                           .output_height = MAX_POOL_1_OUTPUT_Y, 
                                           .output_width = MAX_POOL_1_OUTPUT_X, 
                                           .stride = -1 }; //unused
										   
    max_pool_layer_test(MAX_POOL_LAYER_1_TEST_INPUT_DATA, MAX_POOL_LAYER_1_TEST_WEIGHTS_BIAS, MAX_POOL_LAYER_1_TEST_GOLDEN_OUTPUT, 
	MAX_POOL_LAYER_1_TEST_OUTPUT_DATA, 0, MAX_POOL_1_NAME, max_pool_layer_1);
	#endif
	
	/* Conv Layer 2 */
	#ifdef CONV_2_LAYER
    layer_params convolution_layer_2 = { .batch_size = CONV2_BATCHES,
                                           .input_dim = CONV2_NUM_INPUTS,
                                           .input_height = CONV2_INPUT_Y,
                                           .input_width = CONV2_INPUT_X,
                                           .kernel_size = CONV2_KERNEL,
                                           .output_dim = CONV2_NUM_FILTERS,
                                           .output_height = CONV2_OUTPUT_Y,
                                           .output_width = CONV2_OUTPUT_X,
                                           .stride = CONV2_STRIDE };

    convolution_layer_test(CONVOLUTION_LAYER_2_TEST_INPUT_DATA, CONVOLUTION_LAYER_2_TEST_WEIGHTS_BIAS, CONVOLUTION_LAYER_2_TEST_GOLDEN_OUTPUT, 
	CONVOLUTION_LAYER_2_TEST_OUTPUT_DATA, 0, CONV_LAYER_2_NAME, convolution_layer_2);
	#endif

	/* Batch Norm Layer 2 */
	#ifdef BATCH_NORM_2_LAYER
	layer_params batch_norm_layer_2 = { .batch_size = BATCH_NORM_2_BATCHES,
                                           .input_dim = BATCH_NORM_2_INPUT_DIM,
                                           .input_height = BATCH_NORM_2_INPUT_Y,
                                           .input_width = BATCH_NORM_2_INPUT_X,
                                           .kernel_size = -1, //unused
                                           .output_dim = -1, //unused
                                           .output_height = -1, //unused
                                           .output_width = -1, //unused
                                           .stride = -1 }; //unused
										   
    batch_norm_layer_test(BATCH_NORM_LAYER_2_TEST_INPUT_DATA, BATCH_NORM_LAYER_2_TEST_WEIGHTS_BIAS, BATCH_NORM_LAYER_2_TEST_GOLDEN_OUTPUT, 
	BATCH_NORM_LAYER_2_TEST_OUTPUT_DATA, 0, BATCH_NORM_2_NAME, batch_norm_layer_2);
	#endif
	
	/* Max Pool Layer 2 */
	#ifdef MAX_POOL_2_LAYER
    layer_params max_pool_layer_2 = { .batch_size = MAX_POOL_2_BATCHES,
                                           .input_dim = -1,
                                           .input_height = MAX_POOL_2_INPUT_Y,
                                           .input_width = MAX_POOL_2_INPUT_X,
                                           .kernel_size = -1, //unused
                                           .output_dim = MAX_POOL_2_OUTPUT_DIM, //unused
                                           .output_height = MAX_POOL_2_OUTPUT_Y, 
                                           .output_width = MAX_POOL_2_OUTPUT_X, 
                                           .stride = -1 }; //unused
										   
    max_pool_layer_test(MAX_POOL_LAYER_2_TEST_INPUT_DATA, MAX_POOL_LAYER_2_TEST_WEIGHTS_BIAS, MAX_POOL_LAYER_2_TEST_GOLDEN_OUTPUT, 
	MAX_POOL_LAYER_2_TEST_OUTPUT_DATA, 0, MAX_POOL_2_NAME, max_pool_layer_2);
	#endif
	
	/* Conv Layer 3 */
	#ifdef CONV_3_LAYER
    layer_params convolution_layer_3 = { .batch_size = CONV3_BATCHES,
                                           .input_dim = CONV3_NUM_INPUTS,
                                           .input_height = CONV3_INPUT_Y,
                                           .input_width = CONV3_INPUT_X,
                                           .kernel_size = CONV3_KERNEL,
                                           .output_dim = CONV3_NUM_FILTERS,
                                           .output_height = CONV3_OUTPUT_Y,
                                           .output_width = CONV3_OUTPUT_X,
                                           .stride = CONV3_STRIDE };

    convolution_layer_test(CONVOLUTION_LAYER_3_TEST_INPUT_DATA, CONVOLUTION_LAYER_3_TEST_WEIGHTS_BIAS, CONVOLUTION_LAYER_3_TEST_GOLDEN_OUTPUT, 
	CONVOLUTION_LAYER_3_TEST_OUTPUT_DATA, 0, CONV_LAYER_3_NAME, convolution_layer_3);
	#endif

    /* Dense Layer set 1, layer 1 */
    #ifdef MAX_POOL_DENSE_1_LAYER
    layer_params max_pool_dense_layer_1 = { .batch_size = MAX_POOL_DENSE1_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_INPUTS,
                                           .input_height = MAX_POOL_DENSE1_INPUT_Y,
                                           .input_width = MAX_POOL_DENSE1_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = MAX_POOL_DENSE1_OUTPUT_Y,
                                           .output_width = MAX_POOL_DENSE1_OUTUPUT_X,
                                           .stride = -1 }; //unused

    max_pool_dense_layer_test(MAX_POOL_DENSE_LAYER_1_TEST_INPUT_DATA, MAX_POOL_DENSE_LAYER_1_TEST_WEIGHTS_BIAS, MAX_POOL_DENSE_LAYER_1_TEST_GOLDEN_OUTPUT,
        MAX_POOL_DENSE_LAYER_1_TEST_OUTPUT_DATA, 0, MAX_POOL_DENSE_LAYER_1_NAME, max_pool_dense_layer_1);
    #endif

    /* Dense Layer set 1, layer 2 */
    #ifdef MAX_POOL_DENSE_2_LAYER
    layer_params max_pool_dense_layer_2 = { .batch_size = MAX_POOL_DENSE1_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_INPUTS,
                                           .input_height = MAX_POOL_DENSE1_INPUT_Y,
                                           .input_width = MAX_POOL_DENSE1_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = MAX_POOL_DENSE1_OUTPUT_Y,
                                           .output_width = MAX_POOL_DENSE1_OUTUPUT_X,
                                           .stride = -1 }; //unused

    max_pool_dense_layer_test(MAX_POOL_DENSE_LAYER_2_TEST_INPUT_DATA, MAX_POOL_DENSE_LAYER_2_TEST_WEIGHTS_BIAS, MAX_POOL_DENSE_LAYER_2_TEST_GOLDEN_OUTPUT,
        MAX_POOL_DENSE_LAYER_2_TEST_OUTPUT_DATA, 0, MAX_POOL_DENSE_LAYER_2_NAME, max_pool_dense_layer_2);
    #endif

    /* Dense Layer set 1, layer 3 */
    #ifdef MAX_POOL_DENSE_3_LAYER
    layer_params max_pool_dense_layer_3 = { .batch_size = MAX_POOL_DENSE1_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_INPUTS,
                                           .input_height = MAX_POOL_DENSE1_INPUT_Y,
                                           .input_width = MAX_POOL_DENSE1_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = MAX_POOL_DENSE1_OUTPUT_Y,
                                           .output_width = MAX_POOL_DENSE1_OUTUPUT_X,
                                           .stride = -1 }; //unused

    max_pool_dense_layer_test(MAX_POOL_DENSE_LAYER_3_TEST_INPUT_DATA, MAX_POOL_DENSE_LAYER_3_TEST_WEIGHTS_BIAS, MAX_POOL_DENSE_LAYER_3_TEST_GOLDEN_OUTPUT,
        MAX_POOL_DENSE_LAYER_3_TEST_OUTPUT_DATA, 0, MAX_POOL_DENSE_LAYER_3_NAME, max_pool_dense_layer_3);
    #endif

    /* Dense Layer set 1, layer 4 */
    #ifdef MAX_POOL_DENSE_4_LAYER
    layer_params max_pool_dense_layer_4 = { .batch_size = MAX_POOL_DENSE1_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_INPUTS,
                                           .input_height = MAX_POOL_DENSE1_INPUT_Y,
                                           .input_width = MAX_POOL_DENSE1_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = MAX_POOL_DENSE1_OUTPUT_Y,
                                           .output_width = MAX_POOL_DENSE1_OUTUPUT_X,
                                           .stride = -1 }; //unused

    max_pool_dense_layer_test(MAX_POOL_DENSE_LAYER_4_TEST_INPUT_DATA, MAX_POOL_DENSE_LAYER_4_TEST_WEIGHTS_BIAS, MAX_POOL_DENSE_LAYER_4_TEST_GOLDEN_OUTPUT,
        MAX_POOL_DENSE_LAYER_4_TEST_OUTPUT_DATA, 0, MAX_POOL_DENSE_LAYER_4_NAME, max_pool_dense_layer_4);
    #endif

    /* Dense Layer set 1, layer 5 */
    #ifdef MAX_POOL_DENSE_5_LAYER
    layer_params max_pool_dense_layer_5 = { .batch_size = MAX_POOL_DENSE1_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_INPUTS,
                                           .input_height = MAX_POOL_DENSE1_INPUT_Y,
                                           .input_width = MAX_POOL_DENSE1_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = MAX_POOL_DENSE1_OUTPUT_Y,
                                           .output_width = MAX_POOL_DENSE1_OUTUPUT_X,
                                           .stride = -1 }; //unused

    max_pool_dense_layer_test(MAX_POOL_DENSE_LAYER_5_TEST_INPUT_DATA, MAX_POOL_DENSE_LAYER_5_TEST_WEIGHTS_BIAS, MAX_POOL_DENSE_LAYER_5_TEST_GOLDEN_OUTPUT,
        MAX_POOL_DENSE_LAYER_5_TEST_OUTPUT_DATA, 0, MAX_POOL_DENSE_LAYER_5_NAME, max_pool_dense_layer_5);
    #endif


    /* Dense Layer set 2, layer 1 and follows the layer immediately above */
    #ifdef DENSE_1_LAYER
    layer_params dense_layer_1 = { .batch_size = DENSE2_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .input_height = DENSE2_INPUT_Y,
                                           .input_width = DENSE2_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = DENSE2_OUTPUT_Y,
                                           .output_width = DENSE2_OUTUPUT_X,
                                           .stride = -1 }; //unused

    dense_layer_test(DENSE_LAYER_1_TEST_INPUT_DATA, DENSE_LAYER_1_TEST_WEIGHTS_BIAS, DENSE_LAYER_1_TEST_GOLDEN_OUTPUT,
        DENSE_LAYER_1_TEST_OUTPUT_DATA, 0, DENSE_LAYER_1_NAME, dense_layer_1);
    #endif
	
    /* Dense Layer set 2, layer 2 and follows the layer immediately above */
    #ifdef DENSE_2_LAYER
    layer_params dense_layer_2 = { .batch_size = DENSE2_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .input_height = DENSE2_INPUT_Y,
                                           .input_width = DENSE2_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = DENSE2_OUTPUT_Y,
                                           .output_width = DENSE2_OUTUPUT_X,
                                           .stride = -1 }; //unused

    dense_layer_test(DENSE_LAYER_2_TEST_INPUT_DATA, DENSE_LAYER_2_TEST_WEIGHTS_BIAS, DENSE_LAYER_2_TEST_GOLDEN_OUTPUT,
        DENSE_LAYER_2_TEST_OUTPUT_DATA, 0, DENSE_LAYER_2_NAME, dense_layer_2);
    #endif

    /* Dense Layer set 2, layer 3 and follows the layer immediately above */
    #ifdef DENSE_3_LAYER
    layer_params dense_layer_3 = { .batch_size = DENSE2_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .input_height = DENSE2_INPUT_Y,
                                           .input_width = DENSE2_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = DENSE2_OUTPUT_Y,
                                           .output_width = DENSE2_OUTUPUT_X,
                                           .stride = -1 }; //unused

    dense_layer_test(DENSE_LAYER_3_TEST_INPUT_DATA, DENSE_LAYER_3_TEST_WEIGHTS_BIAS, DENSE_LAYER_3_TEST_GOLDEN_OUTPUT,
        DENSE_LAYER_3_TEST_OUTPUT_DATA, 0, DENSE_LAYER_3_NAME, dense_layer_3);
    #endif

    /* Dense Layer set 2, layer 4 and follows the layer immediately above */
    #ifdef DENSE_4_LAYER
    layer_params dense_layer_4 = { .batch_size = DENSE2_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .input_height = DENSE2_INPUT_Y,
                                           .input_width = DENSE2_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = DENSE2_OUTPUT_Y,
                                           .output_width = DENSE2_OUTUPUT_X,
                                           .stride = -1 }; //unused

    dense_layer_test(DENSE_LAYER_4_TEST_INPUT_DATA, DENSE_LAYER_4_TEST_WEIGHTS_BIAS, DENSE_LAYER_4_TEST_GOLDEN_OUTPUT,
        DENSE_LAYER_4_TEST_OUTPUT_DATA, 0, DENSE_LAYER_4_NAME, dense_layer_4);
    #endif

    /* Dense Layer set 2, layer 5 and follows the layer immediately above */
    #ifdef DENSE_5_LAYER
    layer_params dense_layer_5 = { .batch_size = DENSE2_BATCHES,
                                           .input_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .input_height = DENSE2_INPUT_Y,
                                           .input_width = DENSE2_INPUT_X,
                                           .kernel_size = -1, // unused
                                           .output_dim = MAX_POOL_DENSE1_NUM_OUTPUTS,
                                           .output_height = DENSE2_OUTPUT_Y,
                                           .output_width = DENSE2_OUTUPUT_X,
                                           .stride = -1 }; //unused

    dense_layer_test(DENSE_LAYER_5_TEST_INPUT_DATA, DENSE_LAYER_5_TEST_WEIGHTS_BIAS, DENSE_LAYER_5_TEST_GOLDEN_OUTPUT,
        DENSE_LAYER_5_TEST_OUTPUT_DATA, 0, DENSE_LAYER_5_NAME, dense_layer_5);
    #endif

    return 0;
}