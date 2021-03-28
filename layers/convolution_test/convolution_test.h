// this file contains parameters and functions that are used to test the convolution layer

#ifndef CONVOLUTION_TEST_H
#define  CONVOLUTION_TEST_H

#include <stdio.h>
#include "../conv/conv_layer.h"
#include "../util/shared.h"

//Conv Layer 1
#define CONVOLUTION_LAYER_1_TEST_INPUT_DATA "input_images/2346f.txt"
#define CONVOLUTION_LAYER_1_TEST_OUTPUT_DATA "generated_outputs/conv_1.txt"
#define CONVOLUTION_LAYER_1_TEST_WEIGHTS_BIAS "weights/conv2d_1_weights.txt"
#define CONVOLUTION_LAYER_1_TEST_GOLDEN_OUTPUT "golden_outputs/conv2d_1_output.txt"
#define CONV_LAYER_1_NAME "Conv2d_1"

//Conv Layer 2
#define CONVOLUTION_LAYER_2_TEST_INPUT_DATA "generated_outputs/max_pool_1.txt"
#define CONVOLUTION_LAYER_2_TEST_OUTPUT_DATA "generated_outputs/conv_2.txt"
#define CONVOLUTION_LAYER_2_TEST_WEIGHTS_BIAS "weights/conv2d_2_weights.txt"
#define CONVOLUTION_LAYER_2_TEST_GOLDEN_OUTPUT "golden_outputs/conv2d_2_output.txt"
#define CONV_LAYER_2_NAME "Conv2d_2"

//Conv Layer 3
// #define CONVOLUTION_LAYER_3_TEST_INPUT_DATA "generated_outputs/max_pool_2.txt"
#define CONVOLUTION_LAYER_3_TEST_INPUT_DATA "golden_outputs/max_pooling2d_2_output.txt"
#define CONVOLUTION_LAYER_3_TEST_OUTPUT_DATA "generated_outputs/conv_3.txt"
#define CONVOLUTION_LAYER_3_TEST_WEIGHTS_BIAS "weights/conv2d_3_weights.txt"
#define CONVOLUTION_LAYER_3_TEST_GOLDEN_OUTPUT "golden_outputs/conv2d_3_output.txt"
#define CONV_LAYER_3_NAME "Conv2d_3"


void convolution_layer_test(const char* input_data,const char* weights,const char* golden_output_data, const char* output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif // !CONVOLUTION_TEST_H