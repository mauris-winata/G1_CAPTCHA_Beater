#include <float.h>
#include "conv_layer.h"
#include "../util/data_structs.h"
#include "../util/fixed_point.h"
#include <stdint.h>
#include <stdio.h>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_utils.h"

#define b CONV2_BATCHES
#define od CONV2_NUM_FILTERS
#define ox CONV2_OUTPUT_X
#define oy CONV2_OUTPUT_Y
#define id CONV2_NUM_INPUTS
#define ix CONV2_INPUT_X
#define iy CONV2_INPUT_Y
#define s CONV2_STRIDE
#define k CONV2_KERNEL


void conv_layer2(//result_t * input, 		// where to get inputs
		         //result_t * output,		// where to store outputs
		         hls::stream<result_t>& input, 		// where to get inputs
				 hls::stream<result_t>& output)		// where to store outputs

{
//#pragma HLS DATAFLOW
#pragma HLS INTERFACE ap_ctrl_none port=return //causes it to be always active
#pragma HLS INTERFACE axis port=input bundle=input_stream
#pragma HLS INTERFACE axis port=output bundle=output_stream


  ap_uint<14> num_weights = id*od*k*k;
  int offset = 0;
  result_t input_array[b*id*ix*iy];


  for (int input_size=0; input_size<b*id*ix*iy; input_size++) {
	      input_array[input_size] = input.read();
  }

  
  // Batch
  for (int b_=0; b_< b; b_++)
  {
    // Number of filters
    for (int o_d = 0; o_d < od; o_d++)
    {
      // Output Y Dimension
      for (int o_y = 0; o_y < oy; o_y++)
      {
        // Output X Dimension
        for (int o_x = 0; o_x < ox; o_x++)
        {
          // Set bias
        	weights_biases_t bias = conv_weights2[offset/sizeof(weights_biases_t) + num_weights + o_d]; //one bias per filter
        	result_t output_element = bias;

          // Weighted Sum:

          // Number of inputs
          for (int i_d = 0; i_d < id; i_d++)
          {
            // Input Y Dimension
            for (int i_y = o_y*s-k/2, iiy = 0; iiy < k; i_y++, iiy++)
            {
              if (i_y < 0) continue;
              if (i_y > iy - 1) continue;
              // Input X Dimension
              for (int i_x = o_x*s-k/2, iix = 0; iix < k; i_x++, iix++)
              {
                #pragma HLS PIPELINE II=1

                if (i_x < 0) continue;
                if (i_x > ix - 1) continue;
				//access the input array; offset is: batch + current input + row + column
                result_t input_val = input_array[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x];


				//access the weights/bias array; offset is: + row + column
                weights_biases_t weight = conv_weights2[offset/sizeof(weights_biases_t) + (k*iiy + iix)*od*id +i_d*od + o_d];
                output_element += fixed_mult(input_val, weight, NUM_FRAC_BITS);


              }
            }
          }
		  
          // Write output
          //output[b_*od*ox*oy + o_d*ox*oy + o_y*ox + o_x] = MAX(0, output_element); //ReLu activation means output is non-negative
          output.write(MAX(0, output_element));
        }
      }
    }
  }
}
