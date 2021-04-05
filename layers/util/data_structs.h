#include <stdint.h>

typedef float image_t; //input image (can probably be uint8_t)
typedef int32_t weights_biases_t; //raw weights/biases for layers (probably 16/32 bit)
typedef int32_t result_t; //used for intermediate calculations (ie result from conv layer 1)
typedef int32_t gamma_t; //gamma for batch norm
typedef int32_t beta_t; //beta for batch norm
typedef int32_t mean_t; //mean for batch norm
typedef int32_t var_t; //var for batch norm

