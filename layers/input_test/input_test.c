#include "input_test.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "../input/input_layer.h"
#include "../util/shared.h"
#include "../input_test/input_test.h"

void input_layer_test(const char* input_data,const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params input_layer_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	FILE* output_file = fopen(output_data, "w+");
	FILE* output_file_debug = fopen(INPUT_LAYER_DEBUG_OUTPUT_DATA, "w+");

	if ((input_data_file == NULL) || (output_file == NULL))
	{
		printf("Failed to open the convolution layer test files\n");
		exit(-1);
	}

	//important parameters regarding the convolution layer
	int input_data_size = input_layer_parameters.batch_size * input_layer_parameters.input_height * input_layer_parameters.input_width;
	int output_size = input_data_size;

	// we read in the data from the test related files
	image_t* input_image = (image_t*)malloc(sizeof(image_t) * input_data_size);
	result_t* output_result = (result_t*)malloc(sizeof(result_t) * output_size);

	// check to make sure the memory was allocated appropriately
	if ((input_image == NULL) || (output_result == NULL))
	{
		printf("Failed to allocate memory for the convolution layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input_image, input_data_size, FLOAT); // input image


	// start the input operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", layer_name);

	// test the input layer
	input_layer(input_image, 				 		// where to get inputs
		output_result,				  			    // where to store outputs
		input_layer_parameters.batch_size,          // batch size
		input_layer_parameters.input_width,         // input width
		input_layer_parameters.input_height);       // input height

	// print the test results
	print_layer_test_result(layer_name, input_layer_parameters, 0, input_layer_parameters.output_dim, -1);

	//Printing output results to a file
	int i; 
	for (i = 0; i < output_size; i++){
		fprintf(output_file, "%d\n", output_result[i]);
	}
	
	for (i = 0; i < output_size; i++){
		fprintf(output_file_debug, "%f\n", fixed_to_float(output_result[i], NUM_FRAC_BITS));
	}
		

	printf("************************************* FINISHED TESTING %s LAYER *************************************\n", layer_name);

	// unallocating resources
	fclose(input_data_file);
	fclose(output_file);
	fclose(output_file_debug);

	free(input_image);
	free(output_result);
	
	return;
}