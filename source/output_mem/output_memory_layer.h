#include "../util/fixed_point.h"
#include "../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "hls_stream.h"


void output_memory(hls::stream<float>&input_1,
		   hls::stream<float>&input_2,
		   hls::stream<float>&input_3,
	           hls::stream<float>&input_4,
                   hls::stream<float>&input_5,
                   float* output);
