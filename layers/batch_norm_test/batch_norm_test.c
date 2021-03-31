#include "batch_norm_test.h"
#include "../util/data_structs.h"


void batch_norm_layer_test(const char* input_data,const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params batch_norm_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	FILE* weights_data_file = fopen(weights, "r");
	// FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* output_file = fopen(output_data, "w+");


	if ((input_data_file == NULL) || (weights_data_file == NULL) || (golden_output_file == NULL) || (output_file == NULL))
	{
		printf("Failed to open the convolution layer test files\n");
		exit(-1);
	}

	//important parameters regarding the convolution layer
	int input_data_size = batch_norm_parameters.batch_size * batch_norm_parameters.input_dim * batch_norm_parameters.input_height * batch_norm_parameters.input_width;
	int weights_size = batch_norm_parameters.input_dim * 4;
	int output_size = input_data_size;

	// we read in the data from the test related files
	result_t* input = (result_t*)malloc(sizeof(result_t) * input_data_size);
	weights_biases_t* weights_bias = (weights_biases_t*)malloc(sizeof(weights_biases_t) * weights_size);		
	result_t* golden_output = (result_t*)malloc(sizeof(result_t) * output_size);
	result_t* output_result = (result_t*)malloc(sizeof(result_t) * output_size);
	


	// resulting error of the test
	float batch_norm_error = -1;

	// check to make sure the memory was allocated appropriately
	if ((input == NULL) || (weights_bias == NULL) || (golden_output == NULL) || (output_result == NULL))
	{
		printf("Failed to allocate memory for the batch norm layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input, input_data_size, FLOAT); // input image
	read_file_data(weights_data_file, weights_bias, weights_size, FLOAT); // weights and bias
	read_file_data(golden_output_file, golden_output, output_size, FLOAT); // golden output

	// start the batch norm operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", layer_name);

	// test the batch norm layer
	batch_norm(weights_bias,         	  // global memory pointer
		input, 				  // where to get inputs
		output_result,				  // where to store outputs
		offset, 						  // offset for biases, weights
		batch_norm_parameters.batch_size,            			  // batch size
		batch_norm_parameters.input_dim,         // number of inputs 
		batch_norm_parameters.input_width,           // input width
		batch_norm_parameters.input_height);           // input height


	// verify the output
	batch_norm_error = mean_squared_error(output_result, golden_output, batch_norm_parameters, true);

	// print the test results
	print_layer_test_result(layer_name, batch_norm_parameters, 4*batch_norm_parameters.input_dim, batch_norm_parameters.output_dim, batch_norm_error);

	//Printing output results to a file
	int i; 
	for (i = 0; i < output_size; i++){
		fprintf(output_file, "%f\n", output_result[i]);
	}
		

	printf("************************************* FINISHED TESTING %s LAYER *************************************\n", layer_name);

	// unallocating resources
	fclose(input_data_file);
	fclose(weights_data_file);
	fclose(golden_output_file);
	fclose(output_file);

	free(input);
	free(weights_bias);
	free(golden_output);
	free(output_result);
	
	return;
}