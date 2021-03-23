// general functions declarations that can be used for testing various layers


#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
	int batch_size;
	int input_dim;
	int input_height;
	int input_width;
	int output_dim;
	int output_height;
	int output_width;
	int kernel_size;
	int stride;
} layer_params;

typedef enum
{
	INT_8,
	INT_16,
	INT_32,
	DOUBLE,
	FLOAT
} LAYER_DATA_TYPE;


void read_file_data(FILE* file, void* data_container, int data_size, LAYER_DATA_TYPE type);

float mean_squared_error(float* layer_output, float* golden_output, layer_params layer_info, bool conv_layer);

void print_layer_test_result(const char* layer_type, layer_params layer_info, int weight_count, int bias_count, float error);











#endif