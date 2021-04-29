// this file contains the dense layer functionality tester definition (this dense layer occurs immediately after the final max pool layer)

#include "max_pool_dense_test_hls.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"
#include "hls_stream.h"
//#include "../dense/max_pool_dense_layer_hls.h"

void max_pool_dense_layer_test(const char* input_data, const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params max_pool_dense_layer_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	FILE* weights_data_file = fopen(weights, "r");
	FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* output_file = fopen(output_data, "w+");
	//FILE* debug_output_file = fopen("debug_outputs/max_pool_dense_1_debug.txt", "w+");

	if ((input_data_file == NULL) || (weights_data_file == NULL) || (golden_output_file == NULL) || (output_file == NULL))
	{
		printf("Failed to open the convolution layer test files\n");
		exit(-1);
	}

	//important parameters regarding the dense layer
	int input_data_size = max_pool_dense_layer_parameters.batch_size * max_pool_dense_layer_parameters.input_dim * max_pool_dense_layer_parameters.input_height * max_pool_dense_layer_parameters.input_width;
	int weights_size = max_pool_dense_layer_parameters.input_dim * max_pool_dense_layer_parameters.input_height * max_pool_dense_layer_parameters.input_width * max_pool_dense_layer_parameters.output_dim * max_pool_dense_layer_parameters.output_height * max_pool_dense_layer_parameters.output_width +
		max_pool_dense_layer_parameters.output_width;
	int output_size = max_pool_dense_layer_parameters.output_dim * max_pool_dense_layer_parameters.output_height * max_pool_dense_layer_parameters.output_width;

	// we read in the data from the test related files
	result_t* input_data_values = (result_t*)malloc(sizeof(result_t) * input_data_size);
	weights_biases_t* weights_bias = (weights_biases_t*)malloc(sizeof(weights_biases_t) * weights_size);
	float* golden_output = (float*)malloc(sizeof(float) * output_size);
	result_t* output_result = (result_t*)malloc(sizeof(result_t) * output_size);

	// stream
	hls::stream<result_t> in;
	hls::stream<result_t> out;

	// resulting error of the test
	float dense_error = 0.0;

	// check to make sure the memory was allocated appropriately
	if ((input_data_values == NULL) || (weights_bias == NULL) || (golden_output == NULL) || (output_result == NULL))
	{
		printf("Failed to allocate memory for the convolution layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input_data_values, input_data_size, INT_32); // input image
	read_file_data(weights_data_file, weights_bias, weights_size, FIXED_POINT); // weights and bias
	read_file_data(golden_output_file, golden_output, output_size, FLOAT); // golden output


	for (int i = 0; i < input_data_size; i++)
	{
		in.write(input_data_values[i]);
	}


	// start the dense operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", layer_name);

	// test the dense layer
	max_pool_dense_layer_one(//weights_bias,         	  // global memory pointer
		//input_data_values, 				  // where to get inputs
			in,
		//output_result,				  // where to store outputs
			out
		//offset, 						  // offset for biases, weights
		//max_pool_dense_layer_parameters.batch_size,        // batch size
		//max_pool_dense_layer_parameters.input_dim,         // input dimension
		//max_pool_dense_layer_parameters.input_width,           // input size width
		//max_pool_dense_layer_parameters.input_height,          // input size height
		//max_pool_dense_layer_parameters.output_width);           // output size (1-d vector)
);
	for (int i = 0; i < output_size; i++)
	{
		output_result[i] = out.read();
	}

	// verify the output
	dense_error = mean_squared_error(output_result, golden_output, max_pool_dense_layer_parameters, false);

	// print the test results
	print_layer_test_result(layer_name, max_pool_dense_layer_parameters, weights_size - max_pool_dense_layer_parameters.output_width, max_pool_dense_layer_parameters.output_width, dense_error);

	//print max error
	print_max_error(output_result, golden_output, max_pool_dense_layer_parameters, false);

	//Printing output results to a file
	int i;
	for (i = 0; i < output_size; i++) {
		fprintf(output_file, "%d\n", output_result[i]);
	}
	
	/*for (i = 0; i < output_size; i++){
		fprintf(debug_output_file, "%f\n", fixed_to_float(output_result[i], NUM_FRAC_BITS));
	}*/


	printf("************************************* FINISHED TESTING %s LAYER *************************************\n", layer_name);

	// unallocating resources
	fclose(input_data_file);
	fclose(weights_data_file);
	fclose(golden_output_file);
	fclose(output_file);
	//fclose(debug_output_file);

	free(input_data_values);
	free(weights_bias);
	free(golden_output);
	free(output_result);

}
