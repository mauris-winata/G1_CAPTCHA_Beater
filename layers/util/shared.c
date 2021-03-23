// this file contains all the function definitions that would be useful
// for testing various layers


#include "shared.h"



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
		default:
			break;
		}

	}

	return;
}

float mean_squared_error(float* layer_output, float* golden_output, layer_params layer_info, bool conv_layer)
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
		num_weights = layer_info.input_dim * layer_info.output_dim;
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
	printf("\n\n************************************* TEST %s PARAMETERS *************************************\n", layer_type);
	printf("Batch Size: %d\n", layer_info.batch_size);
	printf("Input Dimension: %d\n", layer_info.input_dim);
	printf("Input Height: %d\n", layer_info.input_height);
	printf("Input Width: %d\n", layer_info.input_width);
	printf("Output Dimension: %d\n", layer_info.output_dim);
	printf("Output Height: %d\n", layer_info.output_height);
	printf("Output Width: %d\n", layer_info.output_width);
	printf("Number of Weights: %d\n", weight_count);
	printf("Number of Biases: %d\n", bias_count);

	printf("\n************************************* TESTING RESULTS BELOW *************************************\n");
	printf("Mean Squared Error: %f\n", error);

	return;
}


