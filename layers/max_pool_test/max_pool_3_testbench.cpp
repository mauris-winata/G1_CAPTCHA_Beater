#include <stdio.h>
#include "max_pool_test.h"
#include "data_structs.h"
#include "fixed_point.h"

#define DEBUG_PRINTS

layer_params max_pool_parameters = {.batch_size = MAX_POOL_3_BATCHES,
									.input_dim = MAX_POOL_3_OUTPUT_DIM,
									.input_height = MAX_POOL_3_INPUT_Y,
									.input_width = MAX_POOL_3_INPUT_X,
									.output_dim = MAX_POOL_3_OUTPUT_DIM,
									.output_height = MAX_POOL_3_OUTPUT_Y,
									.output_width = MAX_POOL_3_OUTPUT_X,
									.kernel_size = -1,
									.stride = -1};

int main(){

	// file handlers
	FILE* input_data_file = fopen(MAX_POOL_LAYER_3_TEST_INPUT_DATA, "r");
	FILE* golden_output_file = fopen(MAX_POOL_LAYER_3_TEST_GOLDEN_OUTPUT, "r");
	FILE* output_file = fopen(MAX_POOL_LAYER_3_TEST_OUTPUT_DATA, "w+");
	FILE* debug_output_file = fopen(MAX_POOL_LAYER_3_DEBUG_OUTPUT_DATA, "w+");

	if ((input_data_file == NULL) ||  (golden_output_file == NULL) || (output_file == NULL))
	{
		if(golden_output_file == NULL) printf("here\n");
		printf("Failed to open the max pool layer test files\n");
		exit(-1);
	}

	//important parameters regarding the convolution layer
	int input_data_size = max_pool_parameters.batch_size * max_pool_parameters.output_dim * max_pool_parameters.input_height * max_pool_parameters.input_width;
	int output_size = max_pool_parameters.batch_size * max_pool_parameters.output_dim * max_pool_parameters.output_height * max_pool_parameters.output_width;

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
	read_file_data(input_data_file, input, input_data_size, FIXED_POINT); // input image
	read_file_data(golden_output_file, golden_output, output_size, FLOAT); // golden output

	for (int i = 0; i < input_data_size; i++){
		max_pool_3(input[i], 				  // where to get inputs
			output_result);				  // where to store outputs
	}

	for (int i = 0; i < max_pool_parameters.output_width + 1; i++){
		max_pool_3(0, 				  // where to get inputs
			output_result);				  // where to store outputs
	}

	#ifdef DEBUG_PRINTS
	// resulting error of the test
	float max_pool_error = -1;

	// start the max_pool operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", MAX_POOL_1_NAME);

	// verify the output
	max_pool_error = mean_squared_error(output_result, golden_output, max_pool_parameters, true);

	// print the test results
	print_layer_test_result(MAX_POOL_1_NAME, max_pool_parameters, -1, max_pool_parameters.output_dim, max_pool_error);

	//printing max error
	print_max_error(output_result, golden_output, max_pool_parameters, true);

	printf("************************************* FINISHED TESTING %s LAYER *************************************\n", MAX_POOL_1_NAME);

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

	return 0;
}
