#define NUM_FRAC_BITS 10

typedef int32_t fixed_point_t;

//Conversion
fixed_point_t float_to_fixed(float input, uint8_t frac_bits);

//Conversion
float fixed_to_float(fixed_point_t input, uint8_t frac_bits);

//Multiplication
fixed_point_t fixed_mult (fixed_point_t op1, fixed_point_t op2, uint8_t frac_bits);

//Division
fixed_point_t fixed_div (fixed_point_t op1, fixed_point_t op2, uint8_t frac_bits);