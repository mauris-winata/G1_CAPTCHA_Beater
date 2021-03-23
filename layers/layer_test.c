#include <stdio.h>
#include <stdint.h>
#include "conv_layer.h"
#include "dense_layer.h"
#include "max_pool_layer.h"
#include "batch_norm_layer.h"
#include "shared.h"
#include "convolution_test.h"

#define DIM 5

/* Input Image */
#define IMG_WIDTH 150
#define IMG_HEIGHT 50

/* Layers (turn on if required) */
#define CONV_1_LAYER
// #define BATCH_NORM_1_LAYER
// #define MAX_POOL_1_LAYER
// #define CONV_2_LAYER
// #define BATCH_NORM_2_LAYER
// #define MAX_POOL_2_LAYER
// #define CONV_3_LAYER
// #define BATCH_NORM_3_LAYER
// #define MAX_POOL_3_LAYER
// #define DENSE_1_LAYER
// #define DENSE_2_LAYER


/* Layer Setup */
//Conv layer params
// int kernel_size = 2;
// int num_filters = 1;
// int num_weights_biases = num_filters*kernel_size*kernel_size + num_filters;
// int32_t weights_biases[10] = {1,1,1,1,1,1,1,1,1,0};
// int32_t input_arr[DIM*DIM] = {1,1,2,4,5,5,6,7,8,3,3,2,1,0,7,1,2,3,4,8,4,6,5,9,4};
// int32_t output_arr[DIM*DIM];
// int32_t output_arr_2[3*3];

// Dense Layer Params
// input to dense layer is flattened
float input_array_dense[INPUT_LENGTH_DENSE_LAYER_TEST] = { 1,2,3,4 };
float output_array_dense[OUTPUT_LENTH_DENSE_LAYER_TEST] = {0};
float weights_biases_test[10] = { 1,1,1,1,1,1,1,1,1,0 };

/* Input Image */
extern float input_image[];
float temp_input_image[150*50] = {0};

int main(){
	
    int i,j;
	FILE *results;
	results = fopen("Outputs/results.txt","w+");
	
	if(results == NULL){
	  printf("Error! Can't Open File! \n");   
	  return(1);             
	}
	
	/* Conv Layer 1 */
    #ifdef CONV_1_LAYER
	printf("\n**************************************** Beginning Conv 1 Layer Testing ****************************************\n");
	
	float conv_1_out[CONV1_OUTPUT_X*CONV1_OUTPUT_Y*CONV1_NUM_FILTERS*CONV1_BATCHES];
	extern float conv2d_1[];
	
    conv_layer(conv2d_1,         	  	  // global memory pointer
				input_image, 		  // where to get inputs
				conv_1_out,				  // where to store outputs
				0, 						  // offset for biases, weights
                CONV1_BATCHES,            // batch size
                CONV1_NUM_FILTERS,        // number of filters
                CONV1_OUTPUT_X,           // output width
                CONV1_OUTPUT_Y,           // output height
                CONV1_NUM_INPUTS,         // number of inputs 
                CONV1_OUTPUT_X,           // input width
                CONV1_OUTPUT_Y,           // input height
                CONV1_STRIDE,             // stride
                CONV1_KERNEL);            // kernel size   
	
	for (i = 0; i < CONV1_OUTPUT_X*CONV1_OUTPUT_Y*CONV1_NUM_FILTERS*CONV1_BATCHES; i++){
		fprintf(results, "%f ", conv_1_out[i]);
	}
	fprintf(results, "\n");
	
	printf("\n**************************************** End Conv 1 Layer Testing ****************************************\n");

    /* Using the test framework (convolution layer)*/
    // prepping for testing the convolution layer
    layer_params convolution_layer_one = { .batch_size = CONV1_BATCHES,
                                           .input_dim = CONV1_NUM_INPUTS,
                                           .input_height = CONV1_INPUT_Y,
                                           .input_width = CONV1_INPUT_X,
                                           .kernel_size = CONV1_KERNEL,
                                           .output_dim = CONV1_NUM_FILTERS,
                                           .output_height = CONV1_OUTPUT_Y,
                                           .output_width = CONV1_OUTPUT_X,
                                           .stride = CONV1_STRIDE };

    convolution_layer_test(CONVOLUTION_LAYER_1_TEST_INPUT_DATA, CONVOLUTION_LAYER_1_TEST_WEIGHTS_BIAS, CONVOLUTION_LAYER_1_TEST_GOLDEN_OUTPUT,
        0, CONV_LAYER_1_NAME, convolution_layer_one);


	#endif
	
	/* Batch Norm Layer 1 */
	#ifdef BATCH_NORM_1_LAYER
	printf("\n**************************************** Beginning Batch Norm 1 Layer Testing ****************************************\n");
	float batch_norm_1_out[CONV1_OUTPUT_X*CONV1_OUTPUT_Y*CONV1_NUM_FILTERS*CONV1_BATCHES];
	extern float batch_normalization_1[];

	batch_norm(batch_normalization_1,   // global memory pointer (stores params)
					conv_1_out, 		// where to get inputs
					batch_norm_1_out,	// where to store outputs
					0, 					// offset for biases, weights
					1,            		// number of batches
					CONV1_NUM_FILTERS,  // number of inputs (number of outputs from previous conv layer)
					CONV1_OUTPUT_X,     // input width
					CONV1_OUTPUT_Y)     // input height
	
	printf("\n**************************************** End Batch Norm 1 Layer Testing ****************************************\n");
	#endif
	
	/* Max Pool Layer 1 */
	#ifdef MAX_POOL_1_LAYER
	printf("\n**************************************** Beginning Max Pool 1 Layer Testing ****************************************\n");
	float max_pool_1_out[MAX_POOL_1_OUTPUT_X*MAX_POOL_1_OUTPUT_Y*CONV1_NUM_FILTERS*CONV1_BATCHES];
	
	max_pool(batch_norm_1_out, 			  // where to get inputs
				max_pool_1_out,			  // where to store outputs
                1,           			  // number of outputs (todo - need to double check)
                MAX_POOL_1_OUTPUT_X,      // output width
                MAX_POOL_1_OUTPUT_Y,      // output height
                BATCH_NORM_1_OUTPUT_X,    // input width
                BATCH_NORM_1_OUTPUT_Y);   // input height
	
	printf("\n**************************************** End Max Pool 1 Layer Testing ****************************************\n");
	#endif
	
	/* Conv Layer 2 */
	#ifdef CONV_2_LAYER
	printf("\n**************************************** Beginning Conv 2 Layer Testing ****************************************\n");

	//Create output array
	float conv_2_out[CONV2_OUTPUT_X*CONV2_OUTPUT_Y];
	
    conv_layer(weights_biases,         	  // global memory pointer
				batch_norm_out_1, 				  // where to get inputs
				conv_2_out,				  // where to store outputs
				0, 						  // offset for biases, weights
                1,            			  // batch size
                CONV2_NUM_FILTERS,        // number of filters
                CONV2_OUTPUT_X,           // output width
                CONV2_OUTPUT_Y,           // output height
                CONV1_NUM_FILTERS,         // number of inputs 
                CONV2_OUTPUT_X,           // input width
                CONV2_OUTPUT_Y,           // input height
                CONV2_STRIDE,             // stride
                CONV2_KERNEL);            // kernel size   

	printf("\n**************************************** End Conv 2 Layer Testing ****************************************\n");
	#endif
	
    // printf("Kernel array:\n");
    // for(i = 0; i < CONV1_KERNEL; i++){
        // for (j = 0; j < CONV1_KERNEL; j++){
            // printf("%d ", weights_biases[j+ CONV1_KERNEL*i]);  
        // }
        // printf("\n");
    // }
	
    // printf("Input array:\n");
    // for(i = 0; i < DIM; i++){
        // for (j = 0; j < DIM; j++){
            // printf("%d ", input_arr[j+ DIM*i]);  
        // }
        // printf("\n");
    // }
    
    // printf("Output array:\n");
    // for(i = 0; i < DIM; i++){
        // for (j = 0; j < DIM; j++){
            // printf("%d ", output_arr[j+ DIM*i]);  
        // }
        // printf("\n");
    // }
    
    // max_pool(output_arr, 		// where to get inputs
    			// output_arr_2,		// where to store outputs
                // 1,           // number of outputs
                // 3,           // output width
                // 3,           // output height
                // 5,           // input width
                // 5);           // input height    
 
    // printf("Output array 2:\n");
    // for(i = 0; i < 3; i++){
        // for (j = 0; j < 3; j++){
            // printf("%d ", output_arr_2[j+ 3*i]);  
        // }
        // printf("\n");
    // }   
    

    /*printf("**************************************** Beginning Dense Layer Testing ****************************************\n");

	// dense layer test output
    printf("Kernel array for dense layer test:\n");
    for (i = 0; i < CONV1_KERNEL; i++) {
        for (j = 0; j < CONV1_KERNEL; j++) {
            printf("%d ", weights_biases_test[j + CONV1_KERNEL * i]);
        }
        printf("\n");
    }

    printf("Input array for dense layer test:\n");
    for (i = 0; i < INPUT_LENGTH_DENSE_LAYER_TEST; i++) 
    {
        printf("%f ", input_array_dense[i]);
    }

    printf("\n");

    // calling the dense layer function
    dense_layer(weights_biases_test,
        input_array_dense,
        output_array_dense,
        0,
        SOFTMAX_ACTIVATION,
        1,
        INPUT_LENGTH_DENSE_LAYER_TEST,
        OUTPUT_LENTH_DENSE_LAYER_TEST);

    printf("output array for dense layer test:\n");
    for (i = 0; i < OUTPUT_LENTH_DENSE_LAYER_TEST; i++)
    {
        printf("%f ", output_array_dense[i]);
    }

    printf("\n**************************************** Finishing Dense Layer Testing ****************************************\n");*/
    
	fclose(results);
	
    return 0;
}