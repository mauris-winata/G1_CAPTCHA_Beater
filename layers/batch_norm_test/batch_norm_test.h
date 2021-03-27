// this file contains parameters and functions that are used to test the batch normalization layer

#ifndef BATCH_NORM_TEST_H
#define  BATCH_NORM_TEST_H

#include <stdio.h>
#include "../batch_norm/batch_norm_layer.h"
#include "../util/shared.h"

//Batch norm Layer 1
#define BATCH_NORM_LAYER_1_TEST_INPUT_DATA "generated_outputs/conv_1.txt"
#define BATCH_NORM_LAYER_1_TEST_OUTPUT_DATA "generated_outputs/batch_norm_1.txt"
#define BATCH_NORM_LAYER_1_TEST_WEIGHTS_BIAS "weights/batch_normalization_1_weights.txt"
#define BATCH_NORM_LAYER_1_TEST_GOLDEN_OUTPUT "golden_outputs/batch_normalization_1_output.txt"
#define BATCH_NORM_1_NAME "Batch_normalization_1"


void batch_norm_layer_test(const char* input_data,const char* weights,const char* golden_output_data, const char* output_data, int offset,const char* layer_name,layer_params convolution_parameters);

#endif 