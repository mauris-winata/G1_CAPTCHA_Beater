#include <stdio.h>
#include <stdint.h>
#include "conv_layer.h"
#include "dense_layer.h"
#include "max_pool_layer.h"
#include "batch_norm_layer.h"

#define DIM 5

int main(){
	
	//Conv layer params
    int kernel_size = 2;
    int num_filters = 1;
    int num_weights_biases = num_filters*kernel_size*kernel_size + num_filters;
    int32_t weights_biases[10] = {1,1,1,1,1,1,1,1,1,0};
    int32_t input_arr[DIM*DIM] = {1,1,2,4,5,5,6,7,8,3,3,2,1,0,7,1,2,3,4,8,4,6,5,9,4};
    int32_t output_arr[DIM*DIM];
    int32_t output_arr_2[3*3];
	
    // Dense Layer Params
    // input to dense layer is flattened
    float input_array_dense[INPUT_LENGTH_DENSE_LAYER_TEST] = { 1,2,3,4 };
    float output_array_dense[OUTPUT_LENTH_DENSE_LAYER_TEST] = {0};
    float weights_biases_test[10] = { 1,1,1,1,1,1,1,1,1,0 };
	
    //First conv layer
    conv_layer(weights_biases,         	  // global memory pointer
				input_arr, 				  // where to get inputs
				output_arr,				  // where to store outputs
				0, 						  // offset for biases, weights
                1,            			  // batch size
                CONV1_NUM_FILTERS,        // number of filters
                CONV1_OUTPUT_X,           // output width
                CONV1_OUTPUT_Y,           // output height
                CONV1_NUM_INPUTS,         // number of inputs 
                CONV1_OUTPUT_X,           // input width
                CONV1_OUTPUT_Y,           // input height
                CONV1_STRIDE,             // stride
                CONV1_KERNEL);            // kernel size
    
    int i,j;
	
	printf("\n**************************************** Beginning Conv Layer Testing ****************************************\n");
	
    printf("Kernel array:\n");
    for(i = 0; i < CONV1_KERNEL; i++){
        for (j = 0; j < CONV1_KERNEL; j++){
            printf("%d ", weights_biases[j+ CONV1_KERNEL*i]);  
        }
        printf("\n");
    }
	
    printf("Input array:\n");
    for(i = 0; i < DIM; i++){
        for (j = 0; j < DIM; j++){
            printf("%d ", input_arr[j+ DIM*i]);  
        }
        printf("\n");
    }
    
    printf("Output array:\n");
    for(i = 0; i < DIM; i++){
        for (j = 0; j < DIM; j++){
            printf("%d ", output_arr[j+ DIM*i]);  
        }
        printf("\n");
    }
    
    max_pool(output_arr, 		// where to get inputs
    			output_arr_2,		// where to store outputs
                1,           // number of outputs
                3,           // output width
                3,           // output height
                5,           // input width
                5);           // input height    
 
    printf("Output array 2:\n");
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", output_arr_2[j+ 3*i]);  
        }
        printf("\n");
    }   
    
    // dense layer test output
	
	printf("\n**************************************** End Conv Layer Testing ****************************************\n");

    printf("**************************************** Beginning Dense Layer Testing ****************************************\n");

    printf("Kernel array for dense layer test:\n");
    for (i = 0; i < CONV1_KERNEL; i++) {
        for (j = 0; j < CONV1_KERNEL; j++) {
            printf("%d ", weights_biases[j + CONV1_KERNEL * i]);
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

    printf("\n**************************************** Finishing Dense Layer Testing ****************************************\n");
    
    printf("Hello World");

    return 0;
}