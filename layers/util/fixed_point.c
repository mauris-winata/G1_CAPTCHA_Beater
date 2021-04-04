#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "fixed_point.h"
#include "data_structs.h"

//Conversion
fixed_point_t float_to_fixed(float input, uint8_t frac_bits){
    return (fixed_point_t)(round(input * (1 << frac_bits)));
}

//Conversion
float fixed_to_float(fixed_point_t input, uint8_t frac_bits){
    return ((float)input / (float)(1 << frac_bits));
}

//Multiplication
fixed_point_t fixed_mult (fixed_point_t op1, fixed_point_t op2, uint8_t frac_bits){
    int64_t product = op1*op2;
    return (((fixed_point_t) product) >> frac_bits);
}

//Division
fixed_point_t fixed_div (fixed_point_t op1, fixed_point_t op2, uint8_t frac_bits){
    int64_t dividend = op1 << frac_bits;
    int64_t quotient = dividend/op2;
    return (fixed_point_t) quotient;
}