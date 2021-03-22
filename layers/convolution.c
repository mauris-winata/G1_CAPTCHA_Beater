// #include <algorithm>
#include <float.h>
#include "conv_layer.h"
#include "batch_norm_layer.h"
#include <stdint.h>

void conv_layer(int32_t * mem,         // global memory pointer
				int32_t * input, 		// where to get inputs
				int32_t * output,		// where to store outputs
				int offset, 			// offset for biases, weights
                // int input_offset,       // offset of inputs
                // int output_offset,      // offset of outputs
                const int b,            // batch size
                const int od,           // number of filters
                const int ox,           // output width
                const int oy,           // output height
                const int id,           // number of inputs 
                const int ix,           // input width
                const int iy,           // input height
                const int s,            // stride
                const int k)            // kernel size
{

// // Global memory interface
// #pragma HLS INTERFACE m_axi port=mem depth=2147483648
// // Bind all control ports to a single bundle
// #pragma HLS INTERFACE s_axilite port=b bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=od bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=ox bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=oy bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=id bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=ix bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=iy bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=s bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=k bundle=CTRL_BUS
// #pragma HLS INTERFACE s_axilite port=input_offset
// #pragma HLS INTERFACE s_axilite port=output_offset
// #pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
 
  int num_weights = id*od*k*k;
  int num_biases = od;
  int num_input = b*id*ix*iy;
  int num_output = b*od*ox*oy;
  
  //Calculating padding required
  // int left_pad;
  // int right_pad; 
  // int top_pad;
  // int bot_pad;
  // int horz_padding;
  // int vert_padding; 
  
  // horz_padding = ((ix/k + 1)*k)%ix;
  // vert_padding = ((iy/k + 1)*k)%iy;
  

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
		   uint32_t bias = mem[offset/sizeof(uint32_t) + num_weights + o_d]; //one bias per filter
           float output_element = bias;

          // Weighted Sum:

          // Number of inputs
          for (int i_d = 0; i_d < id; i_d++)
          {
            // Input Y Dimension
            for (int i_y = o_y*s-k/2, iiy = 0; i_y < o_y*s+k-s; i_y++, iiy++)
            {
              if (i_y < 0) continue;
              if (i_y > iy - 1) continue;
              // Input X Dimension
              for (int i_x = o_x*s-k/2, iix = 0; i_x < o_x*s+k-s; i_x++, iix++)
              {
                
                if (i_x < 0) continue;
                if (i_x > ix - 1) continue;
				//access the input array; offset is: batch + current input + row + column
				uint32_t input_val = input[b_*id*ix*iy + i_d*ix*iy + i_y*ix + i_x];
				
				//access the weights/bias array; offset is: + row + column
				uint32_t weight = mem[offset/sizeof(uint32_t) + o_d*k*k + iiy*k + iix];
                output_element += input_val*weight;                                  
              }
            }
          }
          // Write output
          output[b_*od*ox*oy + o_d*ox*oy + o_y*ox + o_x] = MAX(0, output_element); //ReLu activation means output is non-negative
        }
      }
    }
  }
}