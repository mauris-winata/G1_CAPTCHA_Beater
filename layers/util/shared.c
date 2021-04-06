// this file contains all the function definitions that would be useful
// for testing various layers

#include "shared.h"
#include "data_structs.h"
#include "fixed_point.h"

void read_file_data(FILE* file, void* data_container, int data_size, LAYER_DATA_TYPE type)
{
	float read_value = 0.0;

	for (int i = 0; i < data_size; i++)
	{
		switch (type)
		{
		case INT_8:
			fscanf(file, "%f", &read_value);
			((int8_t*)data_container)[i] = read_value;
			break;
		case INT_16:
			fscanf(file, "%f", &read_value);
			((int16_t*)data_container)[i] = read_value;
			break;
		case INT_32:
			fscanf(file, "%f", &read_value);
			((int32_t*)data_container)[i] = read_value;
			break;
		case DOUBLE:
			fscanf(file, "%f", &read_value);
			((double*)data_container)[i] = read_value;
			break;
		case FLOAT:
			fscanf(file, "%f", &read_value);
			((float*)data_container)[i] = read_value;
			break;
		case FIXED_POINT:
			fscanf(file, "%f", &read_value);
			((fixed_point_t*)data_container)[i] = float_to_fixed(read_value, NUM_FRAC_BITS);
			break;
		default:
			break;
		}

	}

	return;
}

float mean_squared_error(result_t* layer_output, float* golden_output, layer_params layer_info, bool conv_layer)
{
	float total_error = 0.0;
	float intermediate_error = 0.0;
	int total_number_of_outputs = 0;

	// layer parameters
	int num_inputs;
	int num_biases;
	int num_weights;
	int num_outputs;
	int batch_size = layer_info.batch_size;

	// convolution layers and other layers have different parameter calculations
	if (conv_layer)
	{
		// if our current layer verification is convolution
		num_inputs = layer_info.input_dim * layer_info.input_height * layer_info.input_width;
		num_biases = layer_info.output_dim;
		num_weights = layer_info.input_dim * layer_info.kernel_size * layer_info.kernel_size * layer_info.output_dim;
		num_outputs = layer_info.output_dim * layer_info.output_height * layer_info.output_width;
	}
	else
	{
		// any other layer type (in our case this would be dense, softmax, max pooling etc..)
		num_inputs = layer_info.input_dim * layer_info.input_height * layer_info.input_width;
		num_biases = layer_info.output_dim;
		num_weights = layer_info.input_dim * layer_info.input_height * layer_info.input_width * layer_info.output_dim * layer_info.output_height * layer_info.output_width;
		num_outputs = layer_info.output_dim * layer_info.output_height * layer_info.output_width;
	}

	// number of indiviual outputs
	total_number_of_outputs += (batch_size * num_outputs);

	// actually calculating the error below
	for (int i = 0; i < batch_size * num_outputs; i++)
	{
		intermediate_error = fabs(layer_output[i] - golden_output[i]);
		total_error += (intermediate_error * intermediate_error);
	}

	// get the average below
	total_error /= total_number_of_outputs;

	return total_error;
}

void print_layer_test_result(const char* layer_type, layer_params layer_info, int weight_count, int bias_count, float error)
{
	printf("Test Parameters:\n");
	if(layer_info.batch_size != -1) printf("  Batch Size: %d\n", layer_info.batch_size);
	if(layer_info.input_dim != -1) printf("  Input Dimension: %d\n", layer_info.input_dim);
	if(layer_info.input_height != -1) printf("  Input Height: %d\n", layer_info.input_height);
	if(layer_info.input_width != -1) printf("  Input Width: %d\n", layer_info.input_width);
	if(layer_info.output_dim != -1) printf("  Output Dimension: %d\n", layer_info.output_dim);
	if(layer_info.output_height != -1) printf("  Output Height: %d\n", layer_info.output_height);
	if(layer_info.output_width != -1) printf("  Output Width: %d\n", layer_info.output_width);
	if(weight_count != -1) printf("  Number of Weights: %d\n", weight_count);
	if(bias_count != -1) printf("  Number of Biases: %d\n", bias_count);

	printf("\nTesting Results:\n");
	printf("  Mean Squared Error: %f\n", error);

	return;
}


