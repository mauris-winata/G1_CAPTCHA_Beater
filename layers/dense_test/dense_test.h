// this file contains parmeters and functions that are used to test the dense layer

#ifndef DENSE_TEST_H
#define DENSE_TEST_H

#include <stdio.h>
#include "../dense/dense_layer.h"
#include "../util/shared.h"


// First dense layer set, layer 1
#define DENSE_LAYER_1_1_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_1_1_TEST_OUTPUT_DATA "generated_outputs/dense_1_1.txt"
#define DENSE_LAYER_1_1_TEST_WEIGHTS_BIAS "weights/dense_1_weights.txt"
#define DENSE_LAYER_1_1_TEST_GOLDEN_OUTPUT "golden_outputs/dense_1_output.txt"
#define DENSE_LAYER_1_1_NAME "Dense_1_1"

// First dense layer set, layer 2
#define DENSE_LAYER_1_2_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_1_2_TEST_OUTPUT_DATA "generated_outputs/dense_1_2.txt"
#define DENSE_LAYER_1_2_TEST_WEIGHTS_BIAS "weights/dense_3_weights.txt"
#define DENSE_LAYER_1_2_TEST_GOLDEN_OUTPUT "golden_outputs/dense_3_output.txt"
#define DENSE_LAYER_1_2_NAME "Dense_1_2"

// First dense layer set, layer 3
#define DENSE_LAYER_1_3_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_1_3_TEST_OUTPUT_DATA "generated_outputs/dense_1_3.txt"
#define DENSE_LAYER_1_3_TEST_WEIGHTS_BIAS "weights/dense_5_weights.txt"
#define DENSE_LAYER_1_3_TEST_GOLDEN_OUTPUT "golden_outputs/dense_5_output.txt"
#define DENSE_LAYER_1_3_NAME "Dense_1_3"

// First dense layer set, layer 4
#define DENSE_LAYER_1_4_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_1_4_TEST_OUTPUT_DATA "generated_outputs/dense_1_4.txt"
#define DENSE_LAYER_1_4_TEST_WEIGHTS_BIAS "weights/dense_7_weights.txt"
#define DENSE_LAYER_1_4_TEST_GOLDEN_OUTPUT "golden_outputs/dense_7_output.txt"
#define DENSE_LAYER_1_4_NAME "Dense_1_4"

// First dense layer set, layer 5
#define DENSE_LAYER_1_5_TEST_INPUT_DATA "golden_outputs/max_pooling2d_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_1_5_TEST_OUTPUT_DATA "generated_outputs/dense_1_5.txt"
#define DENSE_LAYER_1_5_TEST_WEIGHTS_BIAS "weights/dense_9_weights.txt"
#define DENSE_LAYER_1_5_TEST_GOLDEN_OUTPUT "golden_outputs/dense_9_output.txt"
#define DENSE_LAYER_1_5_NAME "Dense_1_5"

// Second dense layer set, layer 1 (follows layer 1 in previous set)
#define DENSE_LAYER_2_1_TEST_INPUT_DATA "golden_outputs/dense_1_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_2_1_TEST_OUTPUT_DATA "generated_outputs/dense_2_1.txt"
#define DENSE_LAYER_2_1_TEST_WEIGHTS_BIAS "weights/dense_2_weights.txt"
#define DENSE_LAYER_2_1_TEST_GOLDEN_OUTPUT "golden_outputs/dense_2_output.txt"
#define DENSE_LAYER_2_1_NAME "Dense_2_1"

// Second dense layer set, layer 2 (follows layer 2 in previous set)
#define DENSE_LAYER_2_2_TEST_INPUT_DATA "golden_outputs/dense_3_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_2_2_TEST_OUTPUT_DATA "generated_outputs/dense_2_2.txt"
#define DENSE_LAYER_2_2_TEST_WEIGHTS_BIAS "weights/dense_4_weights.txt"
#define DENSE_LAYER_2_2_TEST_GOLDEN_OUTPUT "golden_outputs/dense_4_output.txt"
#define DENSE_LAYER_2_2_NAME "Dense_2_2"

// Second dense layer set, layer 3 (follows layer 3 in previous set)
#define DENSE_LAYER_2_3_TEST_INPUT_DATA "golden_outputs/dense_5_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_2_3_TEST_OUTPUT_DATA "generated_outputs/dense_2_3.txt"
#define DENSE_LAYER_2_3_TEST_WEIGHTS_BIAS "weights/dense_6_weights.txt"
#define DENSE_LAYER_2_3_TEST_GOLDEN_OUTPUT "golden_outputs/dense_6_output.txt"
#define DENSE_LAYER_2_3_NAME "Dense_2_3"

// Second dense layer set, layer 4 (follows layer 4 in previous set)
#define DENSE_LAYER_2_4_TEST_INPUT_DATA "golden_outputs/dense_7_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_2_4_TEST_OUTPUT_DATA "generated_outputs/dense_2_4.txt"
#define DENSE_LAYER_2_4_TEST_WEIGHTS_BIAS "weights/dense_8_weights.txt"
#define DENSE_LAYER_2_4_TEST_GOLDEN_OUTPUT "golden_outputs/dense_8_output.txt"
#define DENSE_LAYER_2_4_NAME "Dense_2_4"

// Second dense layer set, layer 5 (follows layer 5 in previous set)
#define DENSE_LAYER_2_5_TEST_INPUT_DATA "golden_outputs/dense_9_output.txt" // will use previous layers output when tetsing entire model
#define DENSE_LAYER_2_5_TEST_OUTPUT_DATA "generated_outputs/dense_2_5.txt"
#define DENSE_LAYER_2_5_TEST_WEIGHTS_BIAS "weights/dense_10_weights.txt"
#define DENSE_LAYER_2_5_TEST_GOLDEN_OUTPUT "golden_outputs/dense_10_output.txt"
#define DENSE_LAYER_2_5_NAME "Dense_2_5"


void dense_layer_test(const char* input_data, const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params convolution_parameters, DENSE_LAYER_TYPE layer_type);

#endif