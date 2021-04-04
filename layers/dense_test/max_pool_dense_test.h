// this file contains parmeters and functions that are used to test the dense layer after the final max pool layer

#ifndef MAX_POOL_DENSE_TEST_H
#define MAX_POOL_DENSE_TEST_H

#include <stdio.h>
#include "../dense/max_pool_dense_layer.h"
#include "../util/shared.h"

// First dense layer set, layer 1
#define MAX_POOL_DENSE_LAYER_1_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define MAX_POOL_DENSE_LAYER_1_TEST_OUTPUT_DATA "generated_outputs/max_pool_dense_1.txt"
#define MAX_POOL_DENSE_LAYER_1_TEST_WEIGHTS_BIAS "weights/dense_1_weights.txt"
#define MAX_POOL_DENSE_LAYER_1_TEST_GOLDEN_OUTPUT "golden_outputs/dense_1_output.txt"
#define MAX_POOL_DENSE_LAYER_1_NAME "Max_pool_dense_1"

// First dense layer set, layer 2
#define MAX_POOL_DENSE_LAYER_2_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define MAX_POOL_DENSE_LAYER_2_TEST_OUTPUT_DATA "generated_outputs/max_pool_dense_2.txt"
#define MAX_POOL_DENSE_LAYER_2_TEST_WEIGHTS_BIAS "weights/dense_3_weights.txt"
#define MAX_POOL_DENSE_LAYER_2_TEST_GOLDEN_OUTPUT "golden_outputs/dense_3_output.txt"
#define MAX_POOL_DENSE_LAYER_2_NAME "Max_pool_dense_2"

// First dense layer set, layer 3
#define MAX_POOL_DENSE_LAYER_3_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define MAX_POOL_DENSE_LAYER_3_TEST_OUTPUT_DATA "generated_outputs/max_pool_dense_3.txt"
#define MAX_POOL_DENSE_LAYER_3_TEST_WEIGHTS_BIAS "weights/dense_5_weights.txt"
#define MAX_POOL_DENSE_LAYER_3_TEST_GOLDEN_OUTPUT "golden_outputs/dense_5_output.txt"
#define MAX_POOL_DENSE_LAYER_3_NAME "Max_pool_dense_3"

// First dense layer set, layer 4
#define MAX_POOL_DENSE_LAYER_4_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define MAX_POOL_DENSE_LAYER_4_TEST_OUTPUT_DATA "generated_outputs/max_pool_dense_4.txt"
#define MAX_POOL_DENSE_LAYER_4_TEST_WEIGHTS_BIAS "weights/dense_7_weights.txt"
#define MAX_POOL_DENSE_LAYER_4_TEST_GOLDEN_OUTPUT "golden_outputs/dense_7_output.txt"
#define MAX_POOL_DENSE_LAYER_4_NAME "Max_pool_dense_4"

// First dense layer set, layer 5
#define MAX_POOL_DENSE_LAYER_5_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define MAX_POOL_DENSE_LAYER_5_TEST_OUTPUT_DATA "generated_outputs/max_pool_dense_5.txt"
#define MAX_POOL_DENSE_LAYER_5_TEST_WEIGHTS_BIAS "weights/dense_9_weights.txt"
#define MAX_POOL_DENSE_LAYER_5_TEST_GOLDEN_OUTPUT "golden_outputs/dense_9_output.txt"
#define MAX_POOL_DENSE_LAYER_5_NAME "Max_pool_dense_5"


void max_pool_dense_layer_test(const char* input_data, const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params max_pool_dense_layer_parameters);

#endif