// #include <algorithm>
#include <float.h>
#include "layer_defs.h"
#include <stdint.h>


void max_pool(int32_t * input, 		// where to get inputs
				int32_t * output,		// where to store outputs
                const int od,           // number of outputs
                const int ox,           // output width
                const int oy,           // output height
                const int ix,           // input width
                const int iy)           // input height
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
 
  
  // //Calculating padding required
  // int left_pad;
  // int right_pad; 
  // int top_pad;
  // int bot_pad;
  // int horz_padding;
  // int vert_padding; 
  
  // horz_padding = ((ix/k + 1)*k)%ix;
  // vert_padding = ((iy/k + 1)*k)%iy;
  
	// Number of outputs
	for (int o_d = 0; o_d < od; o_d++)
	{
	  // Output Y Dimension
	  for (int o_y = 0; o_y < oy; o_y++)
	  {
		// Output X Dimension
		for (int o_x = 0; o_x < ox; o_x++)
		{
		  //2x2 filter with stride of 2
		  int32_t pixel_0 = input[o_d*ix*iy + 2*o_y*ix + 2*o_x]; //top left
		  int32_t pixel_1 = input[o_d*ix*iy + 2*o_y*ix + 2*o_x + 1]; //top right
		  int32_t pixel_2 = input[o_d*ix*iy + (2*o_y + 1)*ix + 2*o_x]; //bot left
		  int32_t pixel_3 = input[o_d*ix*iy + (2*o_y + 1)*ix + 2*o_x + 1]; //bot right
		
		  //Checking if still in bounds of image
		  if (2*o_y + 1 > iy - 1){
		      pixel_2 = 0;
		      pixel_3 = 0;
		  }
		  
		  if (2*o_x + 1 > ix - 1){
		      pixel_1 = 0;
		      pixel_3 = 0;
		  }
		  
		  // Write output
		  output[o_d*ox*oy + o_y*ox + o_x] = MAX(MAX(pixel_0, pixel_1), MAX(pixel_2, pixel_3)); 
		}
	  }
	}
}
