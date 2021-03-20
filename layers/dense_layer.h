// this file contains the dense layer function declarations
// additional layer specific parameters have been added 

#include <float.h>
#include <stdint.h>
#include <math.h>
#include "layer_defs.h"

// dense layer types
typedef enum
{
	RELU_ACTIVATION, 
	SOFTMAX_ACTIVATION
} DENSE_LAYER_TYPE;

// dense layer test sizes
#define INPUT_LENGTH_DENSE_LAYER_TEST 4
#define OUTPUT_LENTH_DENSE_LAYER_TEST 2

// first type of dense layer parameters (dense_151 to dense_159)
#define INPUT_LENGTH_DENSE_LAYER_ONE 4256
#define OUTPUT_LENTH_DENSE_LAYER_ONE 57


// second type of dense layer parameters (dense_152 to dense_156)
#define INPUT_LENGTH_DENSE_LAYER_TWO 57
#define OUTPUT_LENTH_DENSE_LAYER_TWO 19


// dense layer function declaration
void dense_layer(float* mem, // global pointer to weights and biases
	float* input,  // pointer to the input data for the current layer
	float* output, // poimter to the output buffer for resulting data
	int offset, // location of the weights and biases for the current layer
	DENSE_LAYER_TYPE layer_type,
	int b, // batch size of the input data
	int ix, // input data dimension (length after arriving from flatten layer, 1xid)
	int ox // output data dimension (length after leaving dense layer, 1xod)
);