

#include "output_test.h"
#include "../util/data_structs.h"

void output_layer_test(	const char* input_data, //File of previous dense layer output
						const char* golden_output_data, //File with output string
						const char* output_data, //File to write result
						const char* char_list, //File of possible characters
						const int layer_num // Name of Layer (If CAPTCHA is abcde, a is 1, b is 2, ..., e is 5)
)
{
	// file handlers
	FILE* input_data_file = fopen(input_data, "r");
	FILE* golden_output_file = fopen(golden_output_data, "r");
	FILE* output_file = fopen(output_data, "w");
	FILE* char_file = fopen(char_list, "r");

	
	if ((input_data_file == NULL) || (golden_output_file == NULL) || (output_file == NULL)|| (char_file == NULL))
	{
		printf("Failed to open the test files\n");
		exit(-1);
	}
	

	//Create arrays to store data
	float input_data_arr[NUM_OF_POSSIBLE_CHARACTERS];	// Array to hold input weights
	char golden_output_arr[5];							//Array to hold golden ouptut
	char char_list_arr[NUM_OF_POSSIBLE_CHARACTERS];		//Array to hold possible characters

	//Scan file data into arrays
	for (int i = 0; i < NUM_OF_POSSIBLE_CHARACTERS; i++) {
		fscanf(input_data_file, "%e", &input_data_arr[i]);	// Dense Output
		fscanf(char_file, "%c", &char_list_arr[i]);			// Char list
	}
	for (int i = 0; i < 5; i++) {
		fscanf(golden_output_file, "%c", &golden_output_arr[i]);	// golden_output
	}

	//Get Output Character
	char out_char;
	output_layer(&input_data_arr[0], &char_list_arr[0], NUM_OF_POSSIBLE_CHARACTERS, &out_char);

	//Write to File
	if (golden_output_arr[layer_num-1] != out_char)
	{
		printf("Incorrect Output\n");
		exit(-1);
	}

	fprintf(output_file,"%c", out_char);
	printf("Correct Output\n");




	fclose(input_data_file);
	fclose(golden_output_file);
	fclose(output_file);
	fclose(char_file);
}