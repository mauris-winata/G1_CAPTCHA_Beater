
/// Working with AXI Stream and Input Data Preset
//#include "input_layer.h"
//#include "../../util/fixed_point.h"
//#include "../../util/data_structs.h"
//#include <float.h>
//#include <stdint.h>
//#include <stdio.h>
//
//// #define INPUT_DEBUG
//
//
//
//void input_layer(result_t * output)		// where to store outputs
//
//{
//#pragma HLS INTERFACE axis port=output depth=7500
////#pragma HLS INTERFACE m_axi port=input depth=7500
////#pragma HLS INTERFACE ap_ctrl_none port=return //causes it to be always active
//// Bind all control ports to a single bundle
////#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
//
//	float input_image[] = {247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 145, 134, 137, 144, 96, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 96, 96, 96, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 253, 251, 247, 235, 168, 136, 138, 138, 136, 133, 128, 94, 93, 110, 236, 249, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 249, 231, 131, 231, 249, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 253, 253, 249, 240, 185, 139, 134, 125, 126, 130, 133, 133, 101, 94, 88, 128, 172, 252, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 249, 252, 253, 253, 253, 252, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 252, 248, 242, 237, 194, 144, 138, 130, 130, 134, 134, 134, 133, 131, 127, 102, 126, 128, 156, 236, 250, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 251, 227, 115, 221, 243, 251, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 253, 253, 247, 236, 236, 250, 245, 250, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 245, 220, 160, 139, 135, 131, 130, 134, 133, 130, 124, 135, 134, 139, 129, 134, 134, 133, 134, 172, 249, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 227, 92, 95, 115, 248, 252, 247, 247, 247, 247, 247, 249, 253, 251, 227, 115, 221, 243, 251, 247, 247, 247, 247, 247, 247, 249, 251, 253, 253, 248, 241, 237, 200, 142, 145, 203, 225, 119, 221, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 252, 253, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 220, 142, 126, 126, 130, 133, 134, 131, 135, 143, 145, 157, 222, 159, 140, 135, 135, 133, 126, 168, 242, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 248, 115, 95, 92, 230, 249, 254, 253, 253, 251, 248, 247, 251, 243, 227, 92, 95, 115, 248, 252, 247, 247, 247, 248, 251, 253, 254, 248, 243, 236, 212, 147, 145, 137, 126, 122, 130, 88, 99, 115, 248, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 253, 252, 242, 240, 246, 253, 253, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 212, 134, 123, 133, 132, 129, 123, 126, 138, 212, 238, 245, 244, 246, 182, 137, 130, 131, 128, 170, 245, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 221, 116, 233, 250, 249, 235, 232, 240, 244, 250, 247, 252, 248, 115, 95, 92, 227, 243, 251, 247, 247, 248, 252, 246, 241, 236, 223, 151, 144, 139, 130, 125, 126, 130, 139, 98, 93, 94, 227, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 250, 246, 238, 174, 144, 212, 237, 238, 242, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 251, 227, 115, 221, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 215, 136, 124, 134, 139, 146, 148, 141, 212, 250, 253, 253, 253, 253, 244, 156, 137, 130, 128, 169, 245, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 244, 252, 247, 250, 165, 146, 143, 163, 242, 253, 247, 251, 243, 221, 115, 227, 251, 253, 249, 247, 249, 253, 251, 239, 154, 148, 140, 133, 124, 126, 128, 127, 127, 137, 195, 226, 122, 228, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 252, 248, 193, 138, 133, 131, 139, 143, 155, 231, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 227, 92, 95, 117, 253, 254, 253, 253, 253, 253, 251, 249, 247, 247, 247, 250, 253, 213, 135, 121, 135, 186, 241, 234, 237, 244, 251, 249, 247, 248, 253, 244, 222, 132, 129, 128, 170, 245, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 252, 247, 164, 132, 124, 118, 149, 236, 253, 247, 249, 253, 243, 248, 243, 253, 249, 247, 249, 253, 248, 242, 148, 133, 127, 130, 129, 129, 127, 134, 145, 157, 198, 253, 247, 249, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 249, 246, 190, 130, 126, 124, 124, 123, 115, 135, 222, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 248, 117, 99, 101, 233, 241, 239, 233, 234, 232, 240, 245, 252, 249, 247, 247, 250, 253, 210, 131, 124, 185, 250, 253, 253, 253, 252, 249, 247, 247, 247, 253, 241, 153, 135, 131, 129, 171, 244, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 252, 251, 245, 162, 133, 131, 134, 126, 155, 239, 253, 247, 247, 249, 251, 252, 251, 249, 248, 250, 253, 252, 235, 110, 132, 130, 134, 133, 139, 149, 150, 176, 237, 240, 245, 252, 253, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 253, 202, 133, 124, 131, 140, 150, 144, 126, 137, 222, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 244, 221, 109, 217, 238, 194, 145, 146, 149, 146, 149, 227, 247, 252, 247, 247, 250, 253, 218, 153, 197, 251, 252, 251, 248, 247, 247, 247, 247, 247, 249, 254, 233, 148, 124, 131, 126, 165, 242, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 252, 248, 170, 134, 130, 134, 135, 126, 155, 239, 253, 247, 247, 247, 247, 247, 247, 247, 250, 249, 246, 232, 106, 94, 97, 137, 129, 93, 144, 227, 241, 245, 252, 253, 252, 249, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 253, 253, 198, 128, 125, 138, 204, 244, 238, 160, 149, 231, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 254, 253, 212, 145, 148, 138, 128, 125, 126, 123, 128, 150, 235, 253, 247, 247, 248, 251, 248, 235, 242, 246, 253, 249, 249, 251, 252, 251, 249, 247, 251, 249, 229, 141, 129, 132, 134, 173, 250, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 251, 250, 242, 170, 134, 131, 132, 136, 134, 124, 154, 237, 253, 247, 247, 247, 247, 247, 247, 249, 253, 249, 185, 101, 93, 88, 123, 122, 86, 91, 121, 248, 254, 253, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 189, 124, 125, 196, 251, 254, 253, 241, 238, 242, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 241, 242, 237, 194, 128, 122, 127, 127, 129, 131, 131, 125, 143, 227, 253, 248, 247, 249, 253, 253, 231, 119, 223, 244, 252, 253, 243, 248, 243, 253, 250, 253, 245, 154, 134, 130, 126, 155, 236, 250, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 252, 253, 250, 215, 155, 136, 131, 132, 135, 135, 130, 131, 156, 245, 253, 247, 247, 247, 247, 247, 247, 251, 247, 229, 98, 84, 88, 133, 144, 107, 98, 99, 231, 245, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 254, 218, 146, 128, 128, 201, 253, 253, 250, 253, 253, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 220, 148, 142, 141, 131, 129, 139, 149, 146, 138, 132, 124, 144, 228, 253, 248, 247, 251, 243, 227, 92, 95, 115, 249, 254, 251, 227, 115, 221, 244, 253, 252, 231, 143, 126, 130, 137, 173, 252, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 251, 247, 243, 200, 147, 128, 127, 128, 129, 134, 132, 137, 149, 240, 247, 250, 247, 247, 247, 247, 247, 248, 253, 246, 122, 96, 88, 133, 146, 232, 225, 121, 228, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 250, 239, 183, 120, 138, 208, 253, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 208, 125, 114, 127, 135, 144, 200, 241, 241, 171, 136, 123, 147, 232, 254, 249, 247, 252, 248, 115, 95, 92, 227, 246, 246, 227, 92, 95, 116, 252, 253, 243, 153, 136, 130, 126, 152, 235, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 248, 206, 147, 137, 128, 130, 142, 148, 140, 131, 128, 141, 232, 251, 253, 248, 247, 247, 247, 247, 248, 251, 253, 237, 159, 92, 120, 134, 224, 254, 249, 249, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 253, 219, 146, 127, 187, 245, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 249, 247, 247, 250, 252, 253, 221, 140, 124, 132, 187, 242, 249, 254, 254, 244, 162, 124, 136, 224, 249, 252, 247, 251, 243, 221, 115, 227, 251, 254, 249, 116, 97, 97, 237, 250, 247, 154, 133, 129, 131, 140, 175, 253, 253, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 250, 204, 132, 127, 122, 126, 136, 217, 239, 164, 128, 134, 164, 246, 253, 248, 247, 247, 247, 247, 247, 249, 249, 246, 183, 136, 131, 132, 152, 236, 254, 252, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 250, 253, 253, 202, 124, 121, 194, 253, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 249, 247, 247, 242, 244, 253, 248, 210, 140, 187, 249, 253, 253, 250, 253, 247, 174, 127, 129, 149, 239, 253, 247, 249, 253, 243, 248, 243, 253, 252, 244, 226, 117, 224, 242, 245, 160, 133, 130, 133, 132, 147, 226, 235, 244, 245, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 252, 250, 209, 133, 129, 133, 141, 149, 217, 253, 246, 162, 123, 138, 228, 250, 251, 247, 247, 247, 247, 247, 247, 253, 253, 193, 136, 130, 129, 136, 216, 248, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 244, 252, 253, 209, 131, 134, 208, 255, 254, 253, 252, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 231, 96, 247, 113, 221, 245, 253, 243, 240, 241, 250, 251, 248, 247, 252, 251, 181, 139, 121, 144, 229, 253, 247, 247, 249, 251, 252, 251, 249, 249, 253, 244, 241, 177, 158, 144, 137, 131, 134, 135, 134, 144, 150, 159, 186, 251, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 252, 253, 252, 216, 136, 130, 133, 129, 193, 239, 254, 254, 177, 135, 122, 146, 233, 254, 249, 247, 247, 247, 247, 247, 248, 251, 241, 177, 127, 132, 129, 143, 228, 254, 252, 251, 250, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 249, 216, 170, 235, 197, 125, 172, 233, 238, 234, 238, 245, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 248, 131, 96, 96, 99, 115, 248, 253, 251, 253, 252, 250, 248, 247, 247, 252, 247, 234, 148, 119, 144, 229, 253, 247, 247, 247, 247, 247, 247, 248, 250, 254, 253, 187, 134, 126, 129, 132, 135, 136, 135, 134, 133, 130, 128, 167, 239, 250, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 252, 247, 244, 212, 137, 129, 132, 134, 171, 113, 233, 253, 244, 159, 122, 131, 166, 240, 252, 247, 247, 247, 247, 247, 247, 252, 253, 198, 139, 132, 134, 126, 151, 216, 253, 249, 252, 249, 247, 253, 253, 253, 253, 250, 248, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 251, 246, 223, 135, 139, 143, 143, 138, 141, 154, 154, 145, 146, 217, 246, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 231, 96, 96, 108, 227, 243, 251, 247, 247, 247, 247, 247, 247, 247, 253, 251, 180, 137, 132, 154, 241, 253, 247, 247, 247, 247, 247, 248, 251, 250, 247, 235, 168, 126, 131, 136, 136, 136, 136, 136, 135, 135, 135, 133, 139, 184, 252, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 249, 252, 250, 228, 145, 136, 133, 133, 131, 165, 86, 101, 119, 246, 175, 136, 126, 138, 225, 251, 251, 247, 247, 247, 247, 247, 247, 253, 249, 191, 130, 127, 132, 137, 144, 208, 125, 224, 228, 169, 239, 246, 242, 233, 244, 253, 253, 252, 252, 249, 248, 247, 249, 253, 243, 248, 243, 253, 253, 232, 144, 126, 127, 131, 131, 132, 131, 129, 126, 125, 125, 140, 225, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 249, 247, 96, 237, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 253, 243, 166, 124, 127, 220, 241, 253, 247, 247, 247, 247, 247, 248, 250, 244, 193, 140, 140, 135, 133, 133, 129, 129, 129, 134, 136, 136, 135, 131, 125, 165, 240, 251, 249, 247, 247, 247, 247, 247, 247, 247, 248, 252, 250, 231, 137, 131, 125, 127, 156, 211, 113, 97, 102, 233, 179, 137, 128, 124, 145, 230, 253, 249, 247, 247, 247, 247, 247, 247, 253, 250, 192, 133, 128, 142, 141, 206, 96, 100, 105, 143, 142, 158, 221, 150, 141, 176, 236, 237, 238, 245, 251, 250, 249, 253, 251, 227, 115, 221, 244, 253, 220, 132, 117, 129, 132, 135, 134, 131, 130, 130, 132, 119, 129, 212, 253, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 249, 247, 247, 249, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 253, 242, 172, 126, 133, 155, 240, 253, 247, 247, 247, 247, 247, 253, 254, 201, 136, 125, 130, 136, 132, 140, 144, 156, 146, 137, 127, 127, 131, 132, 131, 135, 183, 251, 253, 247, 247, 247, 247, 247, 247, 247, 251, 248, 235, 143, 133, 128, 128, 138, 190, 247, 227, 120, 232, 243, 179, 129, 127, 131, 155, 236, 252, 247, 247, 247, 247, 247, 247, 247, 253, 253, 193, 132, 127, 137, 205, 112, 97, 88, 123, 127, 127, 135, 133, 132, 124, 137, 145, 147, 154, 208, 248, 252, 253, 244, 227, 92, 95, 115, 248, 253, 231, 153, 141, 143, 138, 131, 135, 143, 145, 136, 133, 131, 147, 224, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 249, 249, 251, 252, 251, 249, 247, 247, 247, 247, 252, 246, 168, 129, 119, 143, 227, 253, 247, 247, 247, 247, 248, 251, 244, 187, 126, 127, 135, 134, 125, 98, 200, 234, 235, 162, 146, 154, 143, 139, 127, 128, 179, 249, 253, 247, 247, 247, 247, 247, 247, 247, 253, 241, 157, 132, 129, 131, 135, 171, 248, 253, 246, 252, 247, 202, 141, 128, 132, 143, 229, 248, 251, 247, 247, 247, 247, 247, 247, 248, 252, 244, 185, 129, 131, 143, 139, 134, 98, 130, 135, 131, 139, 135, 138, 130, 134, 132, 128, 125, 127, 138, 202, 246, 253, 248, 115, 95, 92, 227, 244, 253, 243, 240, 235, 205, 136, 124, 131, 185, 238, 188, 146, 205, 241, 243, 249, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 252, 244, 184, 130, 132, 157, 242, 253, 247, 247, 247, 247, 250, 252, 203, 135, 123, 133, 132, 133, 83, 99, 126, 253, 254, 243, 234, 241, 214, 138, 126, 128, 174, 241, 252, 249, 247, 247, 247, 247, 247, 248, 254, 236, 151, 127, 133, 132, 166, 246, 254, 253, 251, 254, 252, 184, 125, 91, 127, 216, 252, 253, 248, 247, 247, 247, 247, 247, 247, 250, 253, 199, 135, 128, 133, 133, 136, 130, 129, 126, 126, 131, 154, 214, 136, 120, 128, 131, 132, 134, 133, 128, 136, 210, 254, 248, 221, 115, 227, 251, 253, 250, 251, 253, 254, 226, 146, 126, 129, 194, 253, 248, 241, 247, 253, 252, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 251, 227, 115, 221, 243, 251, 247, 247, 247, 252, 246, 174, 127, 130, 221, 245, 253, 247, 247, 247, 247, 250, 250, 207, 144, 149, 167, 207, 109, 95, 97, 228, 245, 252, 252, 253, 255, 228, 145, 125, 132, 136, 190, 252, 252, 247, 247, 247, 247, 247, 250, 247, 228, 140, 129, 134, 132, 166, 236, 252, 252, 252, 254, 246, 177, 90, 82, 107, 221, 253, 251, 247, 247, 247, 247, 247, 247, 247, 250, 253, 202, 138, 126, 99, 128, 130, 138, 141, 152, 147, 154, 243, 232, 154, 143, 151, 142, 135, 131, 135, 129, 127, 195, 247, 254, 244, 247, 243, 253, 249, 247, 247, 247, 251, 247, 203, 124, 128, 192, 253, 254, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 227, 92, 95, 115, 248, 252, 247, 247, 248, 254, 247, 168, 122, 141, 192, 252, 251, 247, 247, 247, 247, 248, 248, 241, 236, 233, 245, 244, 226, 119, 228, 251, 253, 249, 247, 248, 253, 222, 142, 126, 130, 128, 182, 247, 253, 247, 247, 247, 247, 247, 250, 250, 156, 136, 125, 131, 134, 141, 142, 176, 238, 249, 255, 245, 114, 88, 90, 137, 225, 253, 248, 247, 247, 247, 247, 247, 247, 247, 248, 253, 239, 176, 89, 93, 96, 131, 142, 220, 239, 234, 242, 249, 248, 239, 232, 241, 211, 141, 133, 133, 133, 130, 143, 219, 254, 253, 253, 251, 249, 247, 247, 247, 247, 252, 253, 208, 131, 148, 218, 253, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 248, 115, 95, 92, 227, 243, 251, 247, 247, 249, 251, 239, 159, 118, 134, 223, 250, 249, 247, 247, 247, 247, 248, 249, 252, 252, 253, 253, 254, 245, 248, 243, 253, 249, 247, 247, 248, 253, 221, 140, 126, 131, 131, 185, 249, 253, 247, 247, 247, 247, 247, 250, 244, 232, 151, 136, 136, 129, 129, 129, 134, 143, 191, 243, 189, 132, 90, 126, 212, 250, 252, 247, 247, 247, 247, 247, 247, 247, 247, 248, 254, 251, 125, 95, 90, 129, 134, 220, 252, 254, 253, 253, 252, 252, 253, 253, 254, 252, 203, 131, 131, 135, 127, 141, 201, 252, 246, 253, 249, 247, 247, 247, 247, 247, 252, 253, 207, 131, 176, 249, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 221, 115, 227, 251, 253, 249, 247, 248, 253, 253, 179, 133, 129, 149, 238, 253, 248, 247, 249, 252, 253, 254, 254, 254, 254, 254, 254, 254, 254, 255, 254, 254, 254, 254, 254, 254, 255, 230, 146, 131, 135, 134, 192, 254, 255, 254, 254, 254, 254, 254, 254, 255, 254, 253, 237, 154, 142, 137, 138, 133, 134, 151, 153, 148, 140, 130, 145, 230, 255, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 247, 180, 95, 133, 164, 238, 255, 255, 254, 254, 254, 254, 254, 254, 254, 254, 255, 236, 166, 137, 137, 135, 140, 190, 124, 233, 253, 254, 254, 254, 254, 254, 254, 255, 254, 206, 132, 182, 253, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 249, 251, 237, 160, 118, 130, 219, 248, 252, 247, 247, 251, 238, 228, 214, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 219, 223, 198, 126, 120, 123, 120, 166, 222, 221, 216, 217, 217, 217, 218, 220, 222, 223, 227, 220, 198, 121, 116, 120, 121, 124, 123, 124, 125, 126, 121, 126, 195, 225, 219, 217, 217, 217, 217, 217, 217, 217, 217, 221, 227, 186, 129, 122, 120, 188, 224, 223, 220, 217, 217, 217, 217, 217, 217, 217, 219, 221, 218, 172, 114, 122, 126, 131, 90, 89, 96, 213, 221, 217, 217, 217, 217, 219, 223, 205, 138, 114, 172, 243, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 253, 251, 179, 132, 129, 148, 235, 254, 249, 247, 247, 252, 242, 137, 126, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 132, 133, 129, 116, 105, 99, 104, 117, 129, 136, 130, 130, 130, 132, 138, 127, 131, 127, 140, 137, 130, 124, 117, 117, 109, 100, 97, 102, 105, 105, 100, 111, 125, 139, 136, 132, 130, 130, 130, 130, 130, 130, 132, 140, 126, 121, 103, 104, 109, 121, 135, 134, 130, 130, 130, 130, 130, 130, 130, 130, 130, 133, 136, 129, 115, 106, 103, 93, 96, 94, 117, 122, 134, 130, 130, 130, 130, 133, 133, 119, 104, 91, 120, 242, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 253, 247, 175, 121, 128, 216, 248, 251, 247, 247, 247, 251, 238, 228, 214, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 217, 222, 229, 202, 130, 119, 121, 166, 222, 221, 218, 220, 223, 227, 221, 197, 83, 191, 212, 221, 220, 223, 227, 230, 199, 135, 129, 125, 124, 128, 124, 121, 182, 211, 211, 218, 217, 217, 217, 217, 217, 218, 224, 220, 201, 93, 152, 119, 123, 190, 226, 221, 217, 217, 217, 217, 217, 217, 217, 217, 217, 219, 222, 218, 173, 122, 125, 121, 114, 226, 232, 221, 218, 217, 217, 217, 217, 220, 224, 190, 121, 119, 182, 247, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 251, 227, 115, 221, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 241, 169, 119, 140, 224, 253, 250, 247, 247, 247, 249, 252, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 254, 222, 139, 129, 136, 192, 254, 255, 255, 253, 255, 252, 247, 106, 108, 128, 254, 255, 254, 254, 254, 254, 252, 248, 196, 140, 137, 135, 131, 134, 144, 164, 248, 255, 254, 254, 254, 254, 254, 254, 253, 240, 109, 110, 107, 137, 134, 211, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 215, 145, 139, 134, 133, 211, 253, 255, 254, 254, 254, 254, 254, 254, 254, 255, 220, 135, 162, 239, 250, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 227, 92, 95, 115, 248, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 253, 187, 137, 121, 141, 220, 253, 250, 252, 252, 252, 249, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 253, 229, 146, 131, 126, 130, 183, 249, 254, 251, 227, 119, 221, 111, 97, 92, 227, 243, 251, 247, 247, 247, 249, 252, 253, 252, 191, 128, 134, 142, 145, 141, 216, 243, 249, 247, 247, 247, 247, 247, 252, 248, 116, 96, 88, 166, 126, 130, 143, 219, 253, 250, 247, 247, 247, 247, 247, 247, 247, 247, 252, 251, 197, 129, 126, 129, 139, 212, 253, 252, 247, 247, 247, 247, 247, 247, 251, 253, 212, 135, 132, 196, 254, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 248, 115, 95, 92, 227, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 252, 241, 173, 124, 127, 149, 232, 254, 245, 249, 237, 252, 248, 254, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 254, 223, 140, 122, 128, 138, 195, 252, 247, 227, 92, 97, 111, 221, 119, 227, 251, 253, 249, 247, 247, 247, 247, 248, 253, 248, 191, 126, 129, 199, 240, 248, 246, 252, 249, 247, 247, 247, 247, 247, 251, 243, 222, 119, 190, 150, 140, 123, 138, 214, 253, 251, 247, 247, 247, 247, 247, 247, 247, 247, 251, 253, 205, 139, 129, 126, 135, 208, 252, 251, 247, 247, 247, 247, 247, 247, 251, 253, 213, 131, 124, 175, 245, 249, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 221, 115, 227, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 253, 253, 203, 145, 125, 131, 217, 246, 254, 234, 168, 213, 164, 224, 240, 243, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 250, 219, 135, 126, 135, 179, 246, 253, 249, 116, 97, 97, 237, 241, 251, 243, 253, 249, 247, 247, 247, 247, 247, 250, 252, 208, 143, 122, 133, 210, 255, 254, 252, 249, 247, 247, 247, 247, 247, 247, 249, 253, 244, 250, 236, 189, 127, 124, 131, 208, 248, 252, 247, 247, 247, 247, 247, 247, 247, 247, 252, 252, 208, 145, 128, 126, 134, 208, 253, 251, 247, 247, 247, 247, 247, 247, 251, 253, 215, 140, 127, 167, 114, 226, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 243, 179, 127, 133, 144, 224, 239, 171, 208, 151, 126, 141, 140, 175, 251, 250, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 249, 254, 239, 159, 130, 123, 167, 241, 252, 252, 245, 228, 111, 227, 248, 255, 253, 251, 249, 247, 247, 247, 247, 247, 247, 252, 251, 195, 128, 123, 145, 216, 253, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 253, 254, 199, 137, 127, 130, 145, 226, 253, 249, 247, 247, 247, 247, 247, 247, 247, 253, 253, 204, 136, 126, 131, 147, 219, 252, 250, 247, 247, 247, 247, 247, 247, 252, 249, 208, 129, 150, 88, 95, 117, 247, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 253, 197, 137, 128, 131, 201, 172, 139, 144, 133, 138, 125, 121, 145, 232, 248, 249, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 253, 248, 220, 131, 122, 132, 179, 252, 253, 251, 254, 247, 227, 111, 228, 245, 251, 247, 247, 247, 247, 247, 247, 247, 247, 253, 253, 200, 127, 122, 194, 246, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 244, 180, 131, 123, 129, 211, 250, 253, 249, 247, 247, 247, 247, 247, 248, 253, 246, 194, 129, 125, 131, 200, 248, 252, 247, 247, 247, 247, 247, 247, 248, 253, 226, 147, 131, 95, 98, 97, 227, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 253, 249, 187, 129, 125, 142, 140, 140, 128, 127, 126, 137, 132, 130, 155, 243, 253, 248, 247, 247, 247, 247, 247, 249, 253, 251, 227, 115, 223, 247, 254, 241, 155, 131, 132, 167, 245, 249, 249, 250, 245, 230, 96, 97, 116, 248, 252, 247, 247, 247, 247, 247, 247, 247, 248, 251, 246, 190, 126, 136, 211, 253, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 253, 216, 152, 125, 132, 139, 227, 252, 253, 251, 248, 247, 247, 249, 253, 253, 219, 149, 131, 126, 135, 206, 253, 253, 247, 247, 247, 247, 247, 247, 250, 253, 215, 131, 121, 156, 116, 233, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 253, 249, 186, 127, 127, 134, 129, 127, 123, 134, 128, 151, 211, 150, 172, 246, 252, 247, 247, 247, 247, 247, 247, 251, 243, 227, 92, 96, 120, 247, 251, 217, 137, 119, 155, 239, 253, 251, 248, 252, 248, 115, 95, 92, 227, 243, 251, 247, 247, 247, 247, 247, 247, 247, 251, 253, 209, 134, 124, 188, 245, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 249, 181, 132, 126, 130, 141, 219, 245, 247, 253, 251, 251, 252, 248, 244, 195, 132, 129, 128, 134, 204, 253, 252, 247, 247, 247, 247, 247, 247, 250, 253, 217, 133, 126, 174, 246, 250, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 252, 194, 130, 124, 122, 131, 138, 145, 154, 217, 176, 235, 244, 237, 246, 250, 247, 247, 247, 247, 247, 247, 252, 248, 115, 96, 97, 230, 234, 161, 140, 135, 133, 173, 252, 253, 248, 247, 251, 243, 221, 115, 227, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 253, 253, 203, 124, 123, 196, 253, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 250, 246, 174, 135, 129, 134, 137, 151, 230, 249, 253, 252, 248, 216, 154, 140, 136, 132, 126, 135, 204, 253, 251, 247, 247, 247, 247, 247, 247, 250, 253, 218, 134, 124, 186, 252, 254, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 250, 244, 187, 143, 143, 145, 214, 236, 244, 240, 250, 245, 253, 252, 250, 248, 247, 247, 247, 247, 247, 247, 251, 243, 221, 119, 227, 243, 157, 134, 126, 123, 150, 235, 251, 249, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 251, 247, 195, 125, 133, 203, 253, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 253, 243, 164, 127, 129, 127, 135, 142, 182, 237, 225, 162, 157, 133, 126, 131, 129, 128, 143, 212, 252, 250, 247, 247, 247, 247, 247, 247, 250, 253, 217, 134, 125, 187, 249, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 251, 243, 235, 231, 240, 248, 253, 253, 253, 251, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 244, 253, 244, 170, 134, 130, 129, 131, 165, 250, 253, 248, 247, 247, 247, 249, 251, 252, 251, 249, 247, 247, 247, 247, 247, 247, 247, 247, 250, 253, 215, 136, 124, 184, 245, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 252, 253, 190, 135, 123, 124, 126, 128, 137, 146, 145, 137, 130, 134, 131, 136, 138, 145, 207, 246, 250, 248, 247, 247, 247, 247, 247, 247, 250, 253, 217, 134, 130, 195, 249, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 253, 253, 253, 253, 252, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 253, 253, 241, 152, 127, 130, 138, 154, 242, 248, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 253, 205, 124, 121, 191, 251, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 250, 243, 168, 142, 150, 141, 131, 120, 121, 122, 125, 127, 127, 125, 126, 178, 240, 248, 250, 250, 247, 247, 247, 247, 247, 247, 247, 250, 253, 215, 131, 117, 177, 246, 253, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 251, 227, 116, 224, 247, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 253, 250, 247, 238, 159, 137, 130, 126, 146, 235, 252, 252, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 253, 202, 125, 125, 195, 253, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 252, 247, 242, 233, 237, 232, 154, 146, 148, 147, 139, 140, 140, 146, 157, 214, 253, 252, 249, 248, 247, 247, 247, 247, 247, 247, 247, 250, 253, 213, 137, 130, 189, 248, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 227, 93, 102, 111, 248, 247, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 250, 245, 237, 173, 139, 134, 125, 123, 131, 158, 247, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 253, 211, 140, 180, 244, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 250, 253, 253, 254, 250, 242, 233, 236, 237, 213, 168, 233, 236, 238, 243, 249, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 252, 219, 169, 229, 244, 247, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 252, 248, 116, 102, 94, 207, 111, 224, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 252, 246, 187, 138, 135, 126, 133, 141, 147, 157, 235, 248, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 249, 241, 238, 241, 249, 251, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 251, 253, 253, 253, 253, 248, 249, 249, 253, 253, 252, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 249, 242, 246, 248, 253, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 251, 243, 224, 111, 207, 94, 102, 116, 248, 252, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 249, 253, 253, 250, 184, 132, 128, 129, 127, 137, 216, 237, 243, 246, 253, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 251, 253, 252, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 250, 251, 250, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 250, 251, 249, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 247, 248, 111, 102, 93, 227, 243, 251, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 250, 250, 247, 242, 185, 135, 131, 132, 130, 130, 155, 239, 254, 253, 251, 248, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 247, 224, 116, 227, 251, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 248, 206, 143, 138, 134, 133, 135, 134, 137, 220, 246, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 249, 253, 243, 248, 243, 253, 249, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 253, 210, 127, 134, 136, 135, 135, 134, 127, 226, 250, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247};
//
//	int i;
//	for (int b_ = 0; b_ < INPUT_BATCH_SIZE; b_++){
//loop_1: for (i = 0; i < INPUT_IMAGE_WIDTH*INPUT_IMAGE_HEIGHT; i++){
//#pragma HLS pipeline
//			float input_val = input_image[b_*INPUT_IMAGE_WIDTH*INPUT_IMAGE_HEIGHT + i];
//			int32_t temp = float_to_fixed(input_val, NUM_FRAC_BITS);
//			output[b_*INPUT_IMAGE_WIDTH*INPUT_IMAGE_HEIGHT + i] = temp;
//		}
//	}
//}

#include "input_layer.h"
#include "../../util/fixed_point.h"
#include "../../util/data_structs.h"
#include <float.h>
#include <stdint.h>
#include <stdio.h>

// #define INPUT_DEBUG



void input_layer(image_t * input_image,
		         result_t * output)		// where to store outputs

{
#pragma HLS INTERFACE axis port=output depth=7500
#pragma HLS INTERFACE m_axi port=input_image depth=7500
//#pragma HLS INTERFACE ap_ctrl_none port=return //causes it to be always active
// Bind all control ports to a single bundle
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS


	int i; 
	for (int b_ = 0; b_ < INPUT_BATCH_SIZE; b_++){
loop_1: for (i = 0; i < INPUT_IMAGE_WIDTH*INPUT_IMAGE_HEIGHT; i++){
#pragma HLS pipeline
			float input_val = input_image[b_*INPUT_IMAGE_WIDTH*INPUT_IMAGE_HEIGHT + i];
			int32_t temp = float_to_fixed(input_val, NUM_FRAC_BITS);
			output[b_*INPUT_IMAGE_WIDTH*INPUT_IMAGE_HEIGHT + i] = temp;
		}
	}	
}
