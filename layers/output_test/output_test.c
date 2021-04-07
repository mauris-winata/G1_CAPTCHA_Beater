#include "output_test.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"
#include "../output/output_layer.h"

char char_list[NUM_CHARS] = {'2', '3', '4', '5', '6', '7', '8', 'b', 'c', 'd', 'e', 'f', 'g', 'm', 'n', 'p', 'w', 'x', 'y'};

void output_layer_test(const char* input_data,const char* weights, const char* golden_output_data, char* output_data, int offset, const char* layer_name, layer_params output_parameters)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");

	if (input_data_file == NULL)
	{
		printf("Failed to open the output layer test files\n");
		exit(-1);
	}

	//important parameters regarding the output layer
	int input_data_size = output_parameters.input_dim * output_parameters.input_height * output_parameters.input_width;

	// we read in the data from the test related files
	result_t* input_image = (result_t*)malloc(sizeof(result_t) * input_data_size);

	// check to make sure the memory was allocated appropriately
	if (input_image == NULL)
	{
		printf("Failed to allocate memory for the output layer test\n");
		exit(-1);
	}

	// read the relevant test data from the files
	read_file_data(input_data_file, input_image, input_data_size, INT_32); // input image

	// test the output layer
	output_layer(input_image, //pointer to output of dense layer which serves as input for this layer
		char_list, //pointer to first character in the list of possible characters ---- IN THE ORDER OF DENSE LAYER OUTPUT		
		NUM_CHARS, //number of possible characters that could be an output
		output_data // pointer to memory where to write the output character
	);

	// unallocating resources
	fclose(input_data_file);

	free(input_image);
	
	return;
}