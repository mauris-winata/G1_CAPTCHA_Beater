// this file contains the dense layer functionality tester definition

#include "dense_test_hls.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"
#include "hls_stream.h"

void dense_layer_test(const char* input_data, const char* weights, const char* golden_output_data, const char* output_data, int offset, const char* layer_name, layer_params dense_layer_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	FILE* weights_data_file = fopen(weights, "r");
	FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* output_file = fopen(output_data, "w+");
	//FILE* debug_output_file = fopen("debug_outputs/dense_1_debug.txt", "w+");

	if ((input_data_file == NULL) || (weights_data_file == NULL) || (golden_output_file == NULL) || (output_file == NULL))
	{
		printf("Failed to open the convolution layer test files\n");
		exit(-1);
	}

	//important parameters regarding the dense layer
	int input_data_size = dense_layer_parameters.batch_size * dense_layer_parameters.input_dim * dense_layer_parameters.input_height * dense_layer_parameters.input_width;
	int weights_size = dense_layer_parameters.input_dim * dense_layer_parameters.input_height * dense_layer_parameters.input_width * dense_layer_parameters.output_dim * dense_layer_parameters.output_height * dense_layer_parameters.output_width +
		dense_layer_parameters.output_width;
	int output_size = dense_layer_parameters.output_dim * dense_layer_parameters.output_height * dense_layer_parameters.output_width;

	// we read in the data from the test related files
	result_t* input_data_values = (result_t*)malloc(sizeof(result_t) * input_data_size);
	weights_biases_t* weights_bias = (weights_biases_t*)malloc(sizeof(weights_biases_t) * weights_size);
	float* golden_output = (float*)malloc(sizeof(float) * output_size);
	result_t* output_result_dense = (result_t*)malloc(sizeof(result_t) * output_size); // output after the dense layer operation
	float* output_result_soft_max = (float*)malloc(sizeof(float) * output_size); // output after the softmax layer operation
	result_t* output_result_soft_max_int = (result_t*)malloc(sizeof(result_t*) * output_size); // output after the softmax layer operation
	float* output_result_dense_float = (float*)malloc(sizeof(float) * output_size); // output after the softmax layer operation

	// axi stream variables
	// stream
	hls::stream<result_t> in;
	hls::stream<result_t> out;

	// resulting error of the test
	float dense_error = 0.0;

	// check to make sure the memory was allocated appropriately
	if ((input_data_values == NULL) || (weights_bias == NULL) || (golden_output == NULL) || (output_result_dense == NULL) || (output_result_soft_max == NULL))
	{
		printf("Failed to allocate memory for the convolution layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input_data_values, input_data_size, INT_32); // input image
	read_file_data(weights_data_file, weights_bias, weights_size, FIXED_POINT); // weights and bias
	read_file_data(golden_output_file, golden_output, output_size, FLOAT); // golden output

	printf("\n {");
	    for (int i=0; i<weights_size; i++) {
	        printf("%d, ", weights_bias[i]);
	    }

	    printf("} \n");

	// load in the input to the axi stream
	/*for (int i = 0; i < input_data_size; i++)
	{
		in.write(input_data_values[i]);
	}


	// start the dense operation
	printf("\n\n************************************* TESTING %s LAYER *************************************\n", layer_name);

	// test the dense layer
	dense_layer(//weights_bias,         	  // global memory pointer
		in, 				  // where to get inputs
		out				  // where to store outputs
		//offset, 						  // offset for biases, weights
		//dense_layer_parameters.batch_size,        // batch size
		//dense_layer_parameters.input_width,           // input size
		//dense_layer_parameters.output_width);           // output size
);
	// test the soft max layer operation after the previous dense layer
	/*soft_max_layer(output_result_dense,          // output from the previous dense layer
		output_result_soft_max,                  // where to store the current output
		dense_layer_parameters.batch_size,       // batch size
		dense_layer_parameters.input_width,      // input size
		dense_layer_parameters.output_width);    // output size*/

	/*for (int i = 0; i < output_size; i++)
	{
		output_result_dense[i] = out.read();
	}

	for (int i = 0; i < dense_layer_parameters.output_width; i++)
	{
		output_result_dense_float[i] = fixed_to_float(output_result_dense[i], NUM_FRAC_BITS);
	}

	// calculating softmax output
	soft_max_calculation(output_result_dense_float, output_result_soft_max, dense_layer_parameters.batch_size, dense_layer_parameters.input_width, dense_layer_parameters.output_width);

	for (int i = 0; i < dense_layer_parameters.output_width; i++)
	{
		output_result_soft_max_int[i] = float_to_fixed(output_result_soft_max[i], NUM_FRAC_BITS);
		//printf("%.30f\n", output_result_soft_max[i]);
	}

	// verify the output
	dense_error = mean_squared_error(output_result_soft_max_int, golden_output, dense_layer_parameters, false);

	// print the test results
	print_layer_test_result(layer_name, dense_layer_parameters, weights_size - dense_layer_parameters.output_dim, dense_layer_parameters.output_dim, dense_error);

	//print max error
	print_max_error(output_result_soft_max_int, golden_output, dense_layer_parameters, false);
	
	//Printing output results to a file
	/*int i;
	for (i = 0; i < output_size; i++) {
		fprintf(output_file, "%d\n", output_result_soft_max[i]);
	}
	
	/*for (i = 0; i < output_size; i++){
		fprintf(debug_output_file, "%f\n", fixed_to_float(output_result_soft_max[i], NUM_FRAC_BITS));
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
	free(output_result_dense);
	free(output_result_soft_max);
	free(output_result_dense_float);
	free(output_result_soft_max_int);

	return;
}

void soft_max_calculation(float* input_data, float* output_data, int b, int ix, int ox)
{
		// start with the batches
		for (int b_ = 0; b_ < b; b_++)
		{
			float output_result_sum = 0;

			// update values based on the output dimension
			for (int o_x = 0; o_x < ox; o_x++)
			{
				float intermediate_result = (float)exp(input_data[b_ * ox + o_x]); // initial step of softmax operation
				output_result_sum += intermediate_result;
				output_data[b_ * ox + o_x] = intermediate_result;
			}

			// perform the final softmax layer calculation
			for (int o_x = 0; o_x < ox; o_x++)
			{
				output_data[b_ * ox + o_x] /= output_result_sum;
			}
		}

		return;
}
