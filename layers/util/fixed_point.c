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
    int64_t a = op1;
    int64_t b = op2; 
    int64_t product = a*b;
    product = product >> frac_bits;
    return product;
}

//Division
fixed_point_t fixed_div (fixed_point_t op1, fixed_point_t op2, uint8_t frac_bits){
    int64_t a = op1;
    int64_t b = op2; 
    int64_t dividend = a << frac_bits;
    int64_t quotient = dividend/b;
    return quotient;
}

//Sqrt - taken from https://github.com/chmike/fpsqrt/blob/master/fpsqrt.c
fixed_point_t fixed_sqrt (fixed_point_t x, uint8_t frac_bits)
{
    uint32_t t, q, b, r;
    r = x;
    b = 0x40000000;
    q = 0;
    while( b > (NUM_TOTAL_BITS - frac_bits)*4)
    {
        t = q + b;
        if( r >= t )
        {
            r -= t;
            q = t + b; // equivalent to q += 2*b
        }
        r <<= 1;
        b >>= 1;
    }
    q >>= (NUM_TOTAL_BITS - frac_bits)/2;
    return q;
}