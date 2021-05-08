#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "max_pool_layer.h"
#include "data_structs.h"
#include "fixed_point.h"
#include <stdint.h>
#include <math.h>
#include "hls_stream.h"

//Inline Functions
#define MAX(a,b) (((a)>(b))?(a):(b))

// Layer Params
#define od MAX_POOL_2_OUTPUT_DIM
#define ox MAX_POOL_2_OUTPUT_X
#define oy MAX_POOL_2_OUTPUT_Y
#define ix MAX_POOL_2_INPUT_X
#define iy MAX_POOL_2_INPUT_Y

// #define MAX_POOL_DEBUG

int calculate_max(result_t* array, int offset, int out_dim, int out_x, int out_y, result_t* max_val);

//void max_pool_2(hls::stream<result_t>& input, 		// where to get inputs
//				hls::stream<result_t>& output)		// where to store outputs
//{

void max_pool_2(result_t input, 		// where to get inputs
				result_t* output)		// where to store outputs
{
	#pragma HLS INTERFACE axis depth=30000  port=input
	#pragma HLS INTERFACE axis depth=30000  port=output

	// handling the hls stream interfaces
//	#pragma HLS INTERFACE ap_ctrl_none port=return
//	#pragma HLS INTERFACE axis port=input bundle=input_stream
//	#pragma HLS INTERFACE axis port=output bundle=output_stream

	static int o_d = 0;
	static int o_y = 0;
	static int o_x = 0;
	static int cut_off = -1;

	#ifdef MAX_POOL_DEBUG
	int output_count = 0;
	#endif

//	result_t input_val = input.read();
	result_t input_val = input;

//	printf("\ninput: %d", input);

	// Caching data
	static result_t buffer_a[2*MAX_POOL_1_INPUT_X] = {0};
	static result_t buffer_b[2*MAX_POOL_1_INPUT_X] = {0};
	static result_t *back_buffer = buffer_a; //buffer to fill
	static result_t *front_buffer = buffer_b; //buffer to read from
	static result_t *temp_buffer; //used for swapping buffers
	static int inputs_received = 0;
	static int front_counter = 0;
	static int offset = 0;
	static int back_counter = 0;
	static int output_counter = 0;

	static int i = 0; //total inputs received
	static int j = 0;

	// If we can make a calculation
	if (front_counter > 0 ){

		result_t pixel_0 = 0;
		result_t pixel_1 = 0;
		result_t pixel_2 = 0;
		result_t pixel_3 = 0;
		int pixels_used = 4;

		//Checking if still in bounds of image
		if (2*o_y + 1 > iy - 1){
		  pixel_2 = -2147483648; //-infinity
		  pixel_3 = -2147483648; //-infinity
		  pixels_used = 2;
		}

		if (2*o_x + 1 > ix - 1){
		  pixel_1 = -2147483648; //-infinity
		  pixel_3 = -2147483648; //-infinity
		  if (pixels_used == 2) pixels_used = 1;
		  else pixels_used = 2;
		}

		pixel_0 = front_buffer[offset]; //top left
		if (pixel_1 == 0) pixel_1 = front_buffer[offset + 1]; //top right
		if (pixel_2 == 0) pixel_2 = front_buffer[offset + ix]; //bot left
		if (pixel_3 == 0) pixel_3 = front_buffer[offset + ix + 1]; //bot right

		front_counter -= pixels_used;
		result_t output_val = MAX(MAX(pixel_0, pixel_1), MAX(pixel_2, pixel_3));
		output_counter++;

//		if (output_counter == 495 || inputs_received == 1876){
//			printf("output %d at coordinates (%d, %d) is %f\n", output_counter, o_x, o_y, fixed_to_float(output_val, 20));
//			printf("using values: %f %f %f %f\n", fixed_to_float(pixel_0, 20), fixed_to_float(pixel_1, 20), fixed_to_float(pixel_2, 20), fixed_to_float(pixel_3, 20));
//		}

//		printf("output at coordinates (%d, %d) is %f\n", o_x, o_y, fixed_to_float(output_val, 20));

		output[o_d*ox*oy + o_y*ox + o_x] = output_val;
//		output.write(output_val);
		offset += 2;

		// Increment counters
		o_x++;
		if (o_x >= ox){
			o_x = 0;
			o_y++;
		}
		if (o_y >= oy){
			o_y = 0;
			o_d++;
		}

	}

	// If front buffer is depleted - perform no calculation
	else if (front_counter == 0){
//		printf("front buffer depleted\n");
		offset = 0;
	}

	// Filling up the cache initially
	if (back_counter < 2*ix && inputs_received < ix*iy){
//		printf("filling %d\n", back_counter);
		back_buffer[back_counter] = input_val;
		back_counter++;
//		inputs_received++;
	}

	// Back buffer is full OR received all inputs for a full picture
	else if (back_counter == (2*ix) || inputs_received == ix*iy){
//		printf("Back buffer full - swapping\n");

		// if back_counter is half full - clear out bottom half
		if (inputs_received == ix*iy){
			inputs_received = 0;
		}

		// Swap buffers
		temp_buffer = front_buffer;
		front_buffer = back_buffer;
		back_buffer = temp_buffer;
		front_counter = back_counter;
		back_counter = 0;

//		if (inputs_received == ix*iy){
//			printf("inputs received = %d\n", inputs_received);
//			printf("od = %d, ox = %d, oy = %d, front_counter = %d, back_counter = %d\n", o_d, o_x, o_y, front_counter, back_counter);
//
//		}

		// Save new pixel
		back_buffer[back_counter] = input_val;
		back_counter++;

	}

	// Calling function extra times [TESTING ONLY]
	else {
		// Save new pixel
//		printf("problem\n");
//		if (inputs_received == 1876) printf("od = %d, ox = %d, oy = %d, front_counter = %d, back_counter = %d\n", o_d, o_x, o_y, front_counter, back_counter);
//		back_buffer[back_counter] = input_val;
//		inputs_received++;
	}

	inputs_received++;
}

