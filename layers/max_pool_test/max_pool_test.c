#include "max_pool_test.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"


void max_pool_layer_test(const char* input_data,const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params max_pool_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	// FILE* weights_data_file = fopen(weights, "r");
	FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* output_file = fopen(output_data, "w+");
	FILE* debug_output_file = fopen(MAX_POOL_LAYER_3_DEBUG_OUTPUT_DATA, "w+");


	if ((input_data_file == NULL) ||  (golden_output_file == NULL) || (output_file == NULL))
	{
		printf("Failed to open the max pool layer test files\n");
		exit(-1);
	}

	//important parameters regarding the convolution layer
	int input_data_size = max_pool_parameters.batch_size * max_pool_parameters.output_dim * max_pool_parameters.input_height * max_pool_parameters.input_width;
	// int weights_size = max_pool_parameters.input_dim * 4;
	int output_size = max_pool_parameters.batch_size * max_pool_parameters.output_dim * max_pool_parameters.output_height * max_pool_parameters.output_width;;

	// we read in the data from the test related files
	result_t* input = (result_t*)malloc(sizeof(result_t) * input_data_size);
	float* golden_output = (float*)malloc(sizeof(float) * output_size);
	result_t* output_result = (result_t*)malloc(sizeof(result_t) * output_size);



	// check to make sure the memory was allocated appropriately
	if ((input == NULL) || (golden_output == NULL) || (output_result == NULL))
	{
		if (output_result == NULL) printf("output_result is null\n");
		printf("Failed to allocate memory for the max pool layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input, input_data_size, INT_32); // input image
	read_file_data(golden_output_file, golden_output, output_size, FLOAT); // golden output




	// test the batch norm layer
	max_pool(input, 				  // where to get inputs
		output_result,				  // where to store outputs
		max_pool_parameters.output_dim,        // output dimensions
		max_pool_parameters.output_width,        // output width
		max_pool_parameters.output_height,        // output height
		max_pool_parameters.input_width,           // input width
		max_pool_parameters.input_height);           // input height

	#ifdef DEBUG_PRINTS
	// resulting error of the test
	float max_pool_error = -1;
	
	// start the max_pool operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", layer_name);

	// verify the output
	max_pool_error = mean_squared_error(output_result, golden_output, max_pool_parameters, true);

	// print the test results
	print_layer_test_result(layer_name, max_pool_parameters, -1, max_pool_parameters.output_dim, max_pool_error);

	//printing max error
	print_max_error(output_result, golden_output, max_pool_parameters, true);
	
	printf("************************************* FINISHED TESTING %s LAYER *************************************\n", layer_name);
	
	#endif
	
	//Printing output results to a file
	int i; 
	for (i = 0; i < output_size; i++){
		fprintf(output_file, "%d\n", output_result[i]);
	}

	for (i = 0; i < output_size; i++){
		fprintf(debug_output_file, "%f\n", fixed_to_float(output_result[i], NUM_FRAC_BITS));
	}		

	// unallocating resources
	fclose(input_data_file);
	fclose(golden_output_file);
	fclose(output_file);
	fclose(debug_output_file);

	free(input);
	free(golden_output);
	free(output_result);
	
	return;
}