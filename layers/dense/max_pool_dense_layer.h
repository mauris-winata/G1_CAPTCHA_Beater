// this file contains the dense layer function declarations that follows the max pool layer
// additional layer specific parameters have been added 
#ifndef MAX_POOL_DENSE_LAYER_H
#define MAX_POOL_DENSE_LAYER_H

#include "../max_pool/max_pool_layer.h"
#include "../util/data_structs.h"


// first type of dense layer parameters (connecting to max pool layer)
#define MAX_POOL_DENSE1_BATCHES 1
#define MAX_POOL_DENSE1_NUM_INPUTS MAX_POOL_3_OUTPUT_DIM
#define MAX_POOL_DENSE1_INPUT_X MAX_POOL_3_OUTPUT_X
#define MAX_POOL_DENSE1_INPUT_Y MAX_POOL_3_OUTPUT_Y
#define MAX_POOL_DENSE1_NUM_OUTPUTS 1
#define MAX_POOL_DENSE1_OUTUPUT_X 57
#define MAX_POOL_DENSE1_OUTPUT_Y 1

// max pool dense layer function declaration
void max_pool_dense_layer(weights_biases_t* mem, // global pointer to weights and biases
	result_t* input,  // pointer to the input data for the current layer
	result_t* output, // poimter to the output buffer for resulting data
	int offset, // location of the weights and biases for the current layer
	int b, // batch size of the input data
	int id, // dimensions of the input
	int ix, // input data x dimension (length after arriving from flatten layer, 1xid)
	int iy, // input data y dimension
	int ox // output data dimension (length after leaving dense layer, 1xod)
);


#endif