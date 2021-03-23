// this file contains parameters and functions that are used to test the convolution layer

#ifndef CONVOLUTION_TEST_H
#define  CONVOLUTION_TEST_H

#include <stdio.h>
#include "conv_layer.h"
#include "shared.h"


#define CONVOLUTION_LAYER_1_TEST_INPUT_DATA "./convolution_test/input_image.txt"
#define CONVOLUTION_LAYER_1_TEST_WEIGHTS_BIAS "./convolution_test/conv2d_1_weights_bias.txt"
#define CONVOLUTION_LAYER_1_TEST_GOLDEN_OUTPUT "./convolution_test/conv2d_1_output.txt"

#define CONV_LAYER_1_NAME "Conv2d_1"


void convolution_layer_test(const char* input_data,const char* weights,const char* golden_output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif // !CONVOLUTION_TEST_H