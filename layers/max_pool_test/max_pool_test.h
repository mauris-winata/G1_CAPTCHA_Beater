// this file contains parameters and functions that are used to test the batch normalization layer

#ifndef MAX_POOL_TEST_H
#define  MAX_POOL_TEST_H

#include <stdio.h>
#include "../max_pool/max_pool_layer.h"
#include "../util/shared.h"

//Max Pool Layer 1
#define MAX_POOL_LAYER_1_TEST_INPUT_DATA "generated_outputs/batch_norm_1.txt"
// #define MAX_POOL_LAYER_1_TEST_INPUT_DATA "golden_outputs/batch_normalization_1_output.txt"
#define MAX_POOL_LAYER_1_TEST_OUTPUT_DATA "generated_outputs/max_pool_1.txt"
#define MAX_POOL_LAYER_1_TEST_WEIGHTS_BIAS "N/A"
#define MAX_POOL_LAYER_1_TEST_GOLDEN_OUTPUT "golden_outputs/max_pooling2d_1_output.txt"
#define MAX_POOL_1_NAME "Max_Pooling_1"


void max_pool_layer_test(const char* input_data,const char* weights,const char* golden_output_data, const char* output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif 