#include "output_layer.h"
#include "../util/data_structs.h"
#include <stdio.h>

void output_layer(result_t* mem, //pointer to output of dense layer which serves as input for this layer
	char* arr, //pointer to first character in the list of possible characters ---- IN THE ORDER OF DENSE LAYER OUTPUT		
	int n_chr, //number of possible characters that could be an output
	char* out // pointer to memory where to write the output character
)
{
	char to_out = *arr;								// Initially set values to output as first character
	result_t max_val = *mem;

	for (int i = 0; i < n_chr; i++)					// Loop through all the outputs to find highest probability output
	{
		if (mem[i] > max_val)		// Check if probability is higher than current characters
		{
			to_out = arr[i];	// Assign new char if yes
			max_val = mem[i];	// Update max_val
		}
		
	}

	*out = to_out;									//write to output
	return;
}
