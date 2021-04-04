// this file contains the soft_max layer function declarations (is the layer immediately after a dense layer)
// additional layer specific parameters have been added 

#ifndef SOFT_MAX_LAYER_H
#define SOFT_MAX_LAYER_H

#include <float.h>
#include <stdint.h>
#include <math.h>
#include "../dense/dense_layer.h"

// dense layer function declaration
void soft_max_layer(result_t* input,  // pointer to the input data for the current layer
	result_t* output, // poimter to the output buffer for resulting data
	int b, // batch size of the input data
	int ix, // input data dimension (length after arriving from flatten layer, 1xid)
	int ox // output data dimension (length after leaving dense layer, 1xod)
);

#endif