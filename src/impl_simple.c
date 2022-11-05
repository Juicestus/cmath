#include "cmath.h"

int m_absf(const float x, float* y)    
{    
    t_unholy u;
    u.f = x;    
    u.i &= 0x7FFFFFFF;    
    *y = u.f;
    return 0;    
}   

int m_signf(const float x, float* y)    
{    
    *y = (x > 0) - (x < 0);
    return 0;
}

#include <stdio.h>

int _nlsb_exact(int n, int k)
{
    return (n & (1 << (k - 1)));
}

int m_evenf(float x, float* y)
{ 
    t_unholy u;
    t_float_deconstruct d;
    u.f = x;
    d.f = x;
    // printf("%f -> %d\n", d.f, (d.segments.exponent >> 2) - 3);
    // printf("%f -> %d\n", u.f, d.segments.mantisa >> 2);
    // printf("%f -> %d\n", u.f, u.i >> 127);
    d.f = 12.3;
    printf("%f -> %d -> %d\n", d.f, d.segments.mantisa, _nlsb_exact(d.segments.mantisa, 23));
    return 0;
}