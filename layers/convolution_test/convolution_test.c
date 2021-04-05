#include "convolution_test.h"
#include "../util/data_structs.h"


void convolution_layer_test(const char* input_data,const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params convolution_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	FILE* weights_data_file = fopen(weights, "r");
	FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* output_file = fopen(output_data, "w+");


	if ((input_data_file == NULL) || (weights_data_file == NULL) || (golden_output_file == NULL) || (output_file == NULL))
	{
		printf("Failed to open the convolution layer test files\n");
		exit(-1);
	}

	//important parameters regarding the convolution layer
	int input_data_size = convolution_parameters.batch_size * convolution_parameters.input_dim * convolution_parameters.input_height * convolution_parameters.input_width;
	int weights_size = convolution_parameters.input_dim * convolution_parameters.kernel_size * convolution_parameters.kernel_size * convolution_parameters.output_dim +
		convolution_parameters.output_dim;
	int output_size = convolution_parameters.output_dim * convolution_parameters.output_height * convolution_parameters.output_width;

	// we read in the data from the test related files
	result_t* input_image = (result_t*)malloc(sizeof(result_t) * input_data_size);
	weights_biases_t* weights_bias = (weights_biases_t*)malloc(sizeof(weights_biases_t) * weights_size);
	result_t* golden_output = (result_t*)malloc(sizeof(result_t) * output_size);
	result_t* output_result = (result_t*)malloc(sizeof(result_t) * output_size);

	// resulting error of the test
	float convolution_error = 0.0;

	// check to make sure the memory was allocated appropriately
	if ((input_image == NULL) || (weights_bias == NULL) || (golden_output == NULL) || (output_result == NULL))
	{
		printf("Failed to allocate memory for the convolution layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input_image, input_data_size, FLOAT); // input image
	read_file_data(weights_data_file, weights_bias, weights_size, FLOAT); // weights and bias
	read_file_data(golden_output_file, golden_output, output_size, FLOAT); // golden output


	// start the convolution operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", layer_name);

	// test the convolution layer
	conv_layer(weights_bias,         	  // global memory pointer
		input_image, 				  // where to get inputs
		output_result,				  // where to store outputs
		offset, 						  // offset for biases, weights
		convolution_parameters.batch_size,            			  // batch size
		convolution_parameters.output_dim,        // number of filters
		convolution_parameters.output_width,           // output width
		convolution_parameters.output_height,           // output height
		convolution_parameters.input_dim,         // number of inputs 
		convolution_parameters.input_width,           // input width
		convolution_parameters.input_height,           // input height
		convolution_parameters.stride,             // stride
		convolution_parameters.kernel_size);            // kernel size

	// verify the output
	convolution_error = mean_squared_error(output_result, golden_output, convolution_parameters, true);

	// print the test results
	print_layer_test_result(layer_name, convolution_parameters, weights_size - convolution_parameters.output_dim, convolution_parameters.output_dim, convolution_error);

	//Printing output results to a file
	int i; 
	for (i = 0; i < output_size; i++){
		fprintf(output_file, "%.6f\n", output_result[i]);
	}
		

	printf("************************************* FINISHED TESTING %s LAYER *************************************\n", layer_name);

	// unallocating resources
	fclose(input_data_file);
	fclose(weights_data_file);
	fclose(golden_output_file);
	fclose(output_file);

	free(input_image);
	free(weights_bias);
	free(golden_output);
	free(output_result);
	
	return;
}