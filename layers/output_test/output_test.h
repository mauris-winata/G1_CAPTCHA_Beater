
// this file contains parmeters and functions that are used to test the output layer

#ifndef OUTPUT_TEST_H
#define OUTPUT_TEST_H


#include <stdio.h>
#include <stdlib.h>
#include "../util/shared.h"
#include "../output/output_layer.h"
#include "../output/output_layer.c"

//Number of characters
#define NUM_OF_POSSIBLE_CHARACTERS 19

//Character File
#define POSSBILE_CHARACTERS_DATA "char_list.txt"

//First Letter Output
#define OUTPUT_LAYER_1_TEST_INPUT_DATA "../golden_outputs/dense_2_output.txt" //using golden output of even dense layers as input
#define OUTPUT_LAYER_1_OUTPUT "out_layer_1.txt"
//Second Letter Output
#define OUTPUT_LAYER_2_TEST_INPUT_DATA "../golden_outputs/dense_4_output.txt" //using golden output of even dense layers as input
#define OUTPUT_LAYER_2_OUTPUT "out_layer_2.txt"
//Third Letter Output
#define OUTPUT_LAYER_3_TEST_INPUT_DATA "../golden_outputs/dense_6_output.txt" //using golden output of even dense layers as input
#define OUTPUT_LAYER_3_OUTPUT "out_layer_3.txt"
//Fourth Letter Output
#define OUTPUT_LAYER_4_TEST_INPUT_DATA "../golden_outputs/dense_8_output.txt" //using golden output of even dense layers as input
#define OUTPUT_LAYER_4_OUTPUT "out_layer_4.txt"
//Fifth Letter Output
#define OUTPUT_LAYER_5_TEST_INPUT_DATA "../golden_outputs/dense_10_output.txt" //using golden output of even dense layers as input
#define OUTPUT_LAYER_5_OUTPUT "out_layer_5.txt"

//Output Files
#define OUTPUT_LAYERS_TEST_GOLDEN "../golden_outputs/output_golden.txt"

void output_layer_test(const char* input_data, const char* golden_output_data, const char* output_data, const char* char_list, const int layer_num);

#endif