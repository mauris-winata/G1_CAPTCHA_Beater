#include "../util/fixed_point.h"
#include "../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include "hls_stream.h"


void output_layer(hls::stream<result_t>& input, 		// where to get inputs
		hls::stream<float>& output);		// where to store outputs
