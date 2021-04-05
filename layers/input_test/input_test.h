// this file contains parameters and functions that are used to test the convolution layer

#ifndef INPUT_TEST_H
#define  INPUT_TEST_H

#include <stdio.h>
#include "../input/input_layer.h"
#include "../util/shared.h"

//Input
#define INPUT_LAYER_INPUT_DATA "input_images/2346f.txt"
#define INPUT_LAYER_OUTPUT_DATA "generated_outputs/input_data.txt"
#define INPUT_LAYER_DEBUG_OUTPUT_DATA "debug_outputs/input_data_debug.txt"
#define INPUT_LAYER_WEIGHTS_BIASES "N/A"
#define INPUT_LAYER_GOLDEN_OUTPUT_DATA "N/A"
#define INPUT_LAYER_NAME "input"

void input_layer_test(const char* input_data,const char* weights,const char* golden_output_data, const char* output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif // !INPUT_TEST_H