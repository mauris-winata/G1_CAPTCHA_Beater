#include "output_layer.h"
#include "../util/fixed_point.h"
#include "../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "ap_utils.h"
#include "hls_stream.h"
#include "ap_int.h"


// #define INPUT_DEBUG

char char_list[19] = {'2', '3', '4', '5', '6', '7', '8', 'b', 'c', 'd', 'e', 'f', 'g', 'm', 'n', 'p', 'w', 'x', 'y'};


void output_layer(hls::stream<result_t>& input, 		// where to get inputs
		          hls::stream<float>& output)		// where to store outputs

{
//Says that all functions can run concurrently
//#pragma HLS INTERFACE ap_ctrl_none port=return  //causes it to be always active
#pragma HLS INTERFACE axis port=input bundle =input_stream
#pragma HLS INTERFACE axis port=output bundle =output_stream
// Bind all control ports to a single bundle
#pragma HLS INTERFACE ap_ctrl_none port=return //causes it to be always active


	  result_t input_array[19];
      uint32_t temp;

	  for (int input_size=0; input_size<19; input_size++) {
		      input_array[input_size] = input.read();
	  }

	  for(int j=0; j<100; j++){
	      result_t max_val = input_array[0];
          char to_out = char_list[0];
	      for (int i = 1; i < 19; i++)                    // Loop through all the outputs to find highest probability output
	      {
//#pragma HLS PIPELINE
	          if (input_array[i] > max_val)        // Check if probability is higher than current characters
	          {
	              to_out = char_list[i];    // Assign new char if yes
	              max_val = input_array[i];    // Update max_val
	          }



		  }
	      temp = (float)to_out;
	      output.write(temp);

	  }
}




