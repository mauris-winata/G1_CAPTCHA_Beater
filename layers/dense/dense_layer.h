// this file contains the dense layer function declarations
// additional layer specific parameters have been added 
#ifndef DENSE_LAYER_H
#define DENSE_LAYER_H



#include <float.h>
#include <stdint.h>
#include <math.h>
#include "../max_pool/max_pool_layer.h"

/*// dense layer types
typedef enum
{
	RELU_ACTIVATION, 
	SOFTMAX_ACTIVATION
} DENSE_LAYER_TYPE;*/


// second type of dense layer parameters (connecting to first set of dense layers)
#define DENSE2_BATCHES 1
#define DENSE2_INPUT_X 57
#define DENSE2_INPUT_Y 1
#define DENSE2_OUTUPUT_X 19
#define DENSE2_OUTPUT_Y 1


// dense layer function declaration
void dense_layer(weights_biases_t* mem, // global pointer to weights and biases
	result_t* input,  // pointer to the input data for the current layer
	result_t* output, // poimter to the output buffer for resulting data
	int offset, // location of the weights and biases for the current layer
	//DENSE_LAYER_TYPE layer_type,
	int b, // batch size of the input data
	int ix, // input data dimension (length after arriving from flatten layer, 1xid)
	int ox // output data dimension (length after leaving dense layer, 1xod)
);

#endif // !DENSE_LAYER_H