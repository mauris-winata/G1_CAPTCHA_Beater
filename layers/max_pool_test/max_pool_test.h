// this file contains parameters and functions that are used to test the batch normalization layer

#ifndef MAX_POOL_TEST_H
#define  MAX_POOL_TEST_H

#include <stdio.h>
#include "../max_pool/max_pool_layer.h"
#include "../util/shared.h"

//Max Pool Layer 1
#define MAX_POOL_LAYER_1_TEST_INPUT_DATA "generated_outputs/batch_norm_1.txt"
#define MAX_POOL_LAYER_1_TEST_OUTPUT_DATA "generated_outputs/max_pool_1.txt"
#define MAX_POOL_LAYER_1_DEBUG_OUTPUT_DATA "debug_outputs/max_pool_1_debug.txt"
#define MAX_POOL_LAYER_1_TEST_WEIGHTS_BIAS "N/A"
#define MAX_POOL_LAYER_1_TEST_GOLDEN_OUTPUT "golden_outputs/max_pooling2d_1_output.txt"
#define MAX_POOL_1_NAME "Max_Pooling_1"

//Max Pool Layer 2
#define MAX_POOL_LAYER_2_TEST_INPUT_DATA "generated_outputs/batch_norm_2.txt"
#define MAX_POOL_LAYER_2_TEST_OUTPUT_DATA "generated_outputs/max_pool_2.txt"
#define MAX_POOL_LAYER_2_TEST_WEIGHTS_BIAS "N/A"
#define MAX_POOL_LAYER_2_TEST_GOLDEN_OUTPUT "golden_outputs/max_pooling2d_2_output.txt"
#define MAX_POOL_2_NAME "Max_Pooling_2"

//Max Pool Layer 3
#define MAX_POOL_LAYER_3_TEST_INPUT_DATA "generated_outputs/batch_norm_3.txt"
#define MAX_POOL_LAYER_3_TEST_OUTPUT_DATA "generated_outputs/max_pool_3.txt"
#define MAX_POOL_LAYER_3_TEST_WEIGHTS_BIAS "N/A"
#define MAX_POOL_LAYER_3_TEST_GOLDEN_OUTPUT "golden_outputs/max_pooling2d_3_output.txt"
#define MAX_POOL_3_NAME "Max_Pooling_3"



void max_pool_layer_test(const char* input_data,const char* weights,const char* golden_output_data, const char* output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif 