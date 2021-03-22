#include <stdint.h>

//Inline Functions
#define MAX(a,b) (((a)>(b))?(a):(b))

//Conv 1 Params
#define CONV1_KERNEL 3
#define CONV1_BATCHES 1
#define CONV1_INPUT_X 150
#define CONV1_INPUT_Y 50
#define CONV1_OUTPUT_X 150
#define CONV1_OUTPUT_Y 50
#define CONV1_STRIDE 1
#define CONV1_NUM_INPUTS 1 //grayscale
#define CONV1_NUM_FILTERS 16 

//Conv 2 Params
#define CONV2_KERNEL 3
#define CONV2_INPUT_X 150 //todo
#define CONV2_INPUT_Y 50  //todo
#define CONV2_OUTPUT_X 5 //todo
#define CONV2_OUTPUT_Y 5 //todo
#define CONV2_STRIDE 1
#define CONV2_NUM_INPUTS 16 
#define CONV2_NUM_FILTERS 32 

//Conv 3 Params
#define CONV3_KERNEL 3
#define CONV3_INPUT_X 150 //todo
#define CONV3_INPUT_Y 50  //todo
#define CONV3_OUTPUT_X 5  //todo
#define CONV3_OUTPUT_Y 5  //todo
#define CONV3_STRIDE 1
#define CONV3_NUM_INPUTS 32 
#define CONV3_NUM_FILTERS 32 

void conv_layer(float * mem,         // global memory pointer
				float * input, 		// where to get inputs
				float * output,		// where to store outputs
				int offset, 			// offset for biases, weights
                const int b,            // batch size
                const int od,           // number of filters
                const int ox,           // output width
                const int oy,           // output height
                const int id,           // number of inputs 
                const int ix,           // input width
                const int iy,           // input height
                const int s,            // stride
                const int k);            // kernel size

