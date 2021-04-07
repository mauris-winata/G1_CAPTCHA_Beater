#ifndef OUTPUT_TEST_H
#define  OUTPUT_TEST_H

#include <stdio.h>
#include "../output/output_layer.h"
#include "../util/shared.h"

#define OUTPUT_LAYER_INPUT_DIMS 1
#define OUTPUT_LAYER_INPUT_WIDTH 19
#define OUTPUT_LAYER_INPUT_HEIGHT 1
#define OUTPUT_LAYER_OUTPUT_DIMS 1
#define OUTPUT_LAYER_OUTPUT_WIDTH 1
#define OUTPUT_LAYER_OUTPUT_HEIGHT 1
#define OUTPUT_LAYER_WEIGHTS_BIAS "N/A"
#define OUTPUT_LAYER_GOLDEN_OUTPUT "N/A"

#define OUTPUT_LAYER_1_INPUT_DATA "generated_outputs/dense_1.txt"
#define OUTPUT_LAYER_1_NAME "CHAR_0"

#define OUTPUT_LAYER_2_INPUT_DATA "generated_outputs/dense_2.txt"
#define OUTPUT_LAYER_2_NAME "CHAR_1"

#define OUTPUT_LAYER_3_INPUT_DATA "generated_outputs/dense_3.txt"
#define OUTPUT_LAYER_3_NAME "CHAR_2"

#define OUTPUT_LAYER_4_INPUT_DATA "generated_outputs/dense_4.txt"
#define OUTPUT_LAYER_4_NAME "CHAR_3"

#define OUTPUT_LAYER_5_INPUT_DATA "generated_outputs/dense_5.txt"
#define OUTPUT_LAYER_5_NAME "CHAR_4"

void output_layer_test(const char* input_data,const char* weights,const char* golden_output_data, char* output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif // !OUTPUT_TEST_H