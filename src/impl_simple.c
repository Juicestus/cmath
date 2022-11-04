#include "cmath.h"

int m_absf(const float x, float* y)    
{    
    union {    
        long i;    
        float d;    
    } u;    

    u.d = x;    
    u.i &= 0x7FFFFFFF;    
    *y = u.d;    
    return 0;    
}   

int m_signf(const float x, float* y)    
{    
    *y = (x > 0) - (x < 0);
    return 0;
}