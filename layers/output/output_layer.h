
// this file contains the output layer function declarations
// additional layer specific parameters have been added 


#ifndef OUTPUT_LAYER_H
#define OUTPUT_LAYER_H

#include <float.h>
#include <stdint.h>
#include <math.h>
//#include "../dense/dense_layer.h"

typedef float dense_out; // For now Dense_out is set to float, change to fixed point whenever

//output layer function declaration

void output_layer(dense_out* mem, //pointer to output of dense layer which serves as input for this layer
	char* arr, //pointer to the array of possible characters ---- IN THE ORDER OF DENSE LAYER OUTPUT		
	int n_chr, //number of possible characters that could be an output
	char* out // pointer to memory where to write the output character
);

#endif // !OUTPUT_LAYER_H