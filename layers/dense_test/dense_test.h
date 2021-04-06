// this file contains parmeters and functions that are used to test the dense layer

#ifndef DENSE_TEST_H
#define DENSE_TEST_H

#include <stdio.h>
#include "../dense/dense_layer.h"
#include "../soft_max/soft_max_layer.h"
#include "../util/shared.h"


// Second dense layer set, layer 1 (follows layer 1 in previous set)
// #define DENSE_LAYER_1_TEST_INPUT_DATA "golden_outputs/dense_1_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_1_TEST_INPUT_DATA "generated_outputs/max_pool_dense_1.txt"
#define DENSE_LAYER_1_TEST_OUTPUT_DATA "generated_outputs/dense_1.txt"
#define DENSE_LAYER_1_TEST_WEIGHTS_BIAS "weights/dense_2_weights.txt"
#define DENSE_LAYER_1_TEST_GOLDEN_OUTPUT "golden_outputs/dense_2_output.txt"
#define DENSE_LAYER_1_NAME "Dense_1"

// Second dense layer set, layer 2 (follows layer 2 in previous set)
// #define DENSE_LAYER_2_TEST_INPUT_DATA "golden_outputs/dense_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_2_TEST_INPUT_DATA "generated_outputs/max_pool_dense_2.txt"
#define DENSE_LAYER_2_TEST_OUTPUT_DATA "generated_outputs/dense_2.txt"
#define DENSE_LAYER_2_TEST_WEIGHTS_BIAS "weights/dense_4_weights.txt"
#define DENSE_LAYER_2_TEST_GOLDEN_OUTPUT "golden_outputs/dense_4_output.txt"
#define DENSE_LAYER_2_NAME "Dense_2"

// Second dense layer set, layer 3 (follows layer 3 in previous set)
// #define DENSE_LAYER_3_TEST_INPUT_DATA "golden_outputs/dense_5_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_3_TEST_INPUT_DATA "generated_outputs/max_pool_dense_3.txt"
#define DENSE_LAYER_3_TEST_OUTPUT_DATA "generated_outputs/dense_3.txt"
#define DENSE_LAYER_3_TEST_WEIGHTS_BIAS "weights/dense_6_weights.txt"
#define DENSE_LAYER_3_TEST_GOLDEN_OUTPUT "golden_outputs/dense_6_output.txt"
#define DENSE_LAYER_3_NAME "Dense_3"

// Second dense layer set, layer 4 (follows layer 4 in previous set)
// #define DENSE_LAYER_4_TEST_INPUT_DATA "golden_outputs/dense_7_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_4_TEST_INPUT_DATA "generated_outputs/max_pool_dense_4.txt"
#define DENSE_LAYER_4_TEST_OUTPUT_DATA "generated_outputs/dense_4.txt"
#define DENSE_LAYER_4_TEST_WEIGHTS_BIAS "weights/dense_8_weights.txt"
#define DENSE_LAYER_4_TEST_GOLDEN_OUTPUT "golden_outputs/dense_8_output.txt"
#define DENSE_LAYER_4_NAME "Dense_4"

// Second dense layer set, layer 5 (follows layer 5 in previous set)
// #define DENSE_LAYER_5_TEST_INPUT_DATA "golden_outputs/dense_9_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_5_TEST_INPUT_DATA "generated_outputs/max_pool_dense_5.txt"
#define DENSE_LAYER_5_TEST_OUTPUT_DATA "generated_outputs/dense_5.txt"
#define DENSE_LAYER_5_TEST_WEIGHTS_BIAS "weights/dense_10_weights.txt"
#define DENSE_LAYER_5_TEST_GOLDEN_OUTPUT "golden_outputs/dense_10_output.txt"
#define DENSE_LAYER_5_NAME "Dense_5"


void dense_layer_test(const char* input_data, const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params dense_layer_parameters);

#endif