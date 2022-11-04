#include <stdio.h>

#include "cmath.h"

// Ugly macro
#define PRINT_CALL_F_1_1(n, x) { float __buff_ ## n; if (!n(x, &__buff_ ## n)) printf("%s(%f) = %f\n", #n, x, __buff_ ## n); else printf("%s(%f) errored\n", #n, x); }
#define PRINT_CALL_F_2_1(n, x, y) { float __buff_ ## n; if (!n(x, y, &__buff_ ## n)) printf("%s(%f, %f) = %f\n", #n, x, y, __buff_ ## n); else printf("%s(%f, %f) errored\n", #n, x, y); }

int main(const int argc, const char** argv) 
{
    // PRINT_CALL_F_1_1(m_sin, M_PI / 6);
    // PRINT_CALL_F_1_1(m_sin, M_PI / 4);
    // PRINT_CALL_F_1_1(m_sin, M_PI / 3);
    // PRINT_CALL_F_1_1(m_sin, M_PI / 2);
    // PRINT_CALL_F_1_1(m_sin, M_PI);
    // PRINT_CALL_F_1_1(m_sin, 2 * M_PI);
    // PRINT_CALL_F_1_1(m_sin, 200 * M_PI);

    // const double x = M_PI_2 / 3.;
    // PRINT_CALL_F_1_1(m_sin, x);
	// PRINT_CALL_F_1_1(m_cos, x);
	// PRINT_CALL_F_1_1(m_tan, x);
	// PRINT_CALL_F_1_1(m_csc, x);
	// PRINT_CALL_F_1_1(m_sec, x);
	// PRINT_CALL_F_1_1(m_cot, x);

    // PRINT_CALL_F_1_1(m_absf, -2.2);
    // PRINT_CALL_F_1_1(m_absf, 5.2);
    // PRINT_CALL_F_1_1(m_absf, -773.20948852);
    // PRINT_CALL_F_1_1(m_absf, 2288489.20948852);

    // printf("%lu\n", sizeof(float) * 8);
    // printf("%lu\n", sizeof(double) * 8);

    // PRINT_CALL_F_1_1(m_sqrtf, 4.);
    // PRINT_CALL_F_1_1(m_sqrtf, 2.);
    // PRINT_CALL_F_1_1(m_sqrtf, .8);
    // PRINT_CALL_F_1_1(m_sqrtf, 2.5);
    // PRINT_CALL_F_1_1(m_sqrtf, -1.);

    // PRINT_CALL_F_1_1(m_asin, .5);
    // PRINT_CALL_F_1_1(m_acos, .5);
    // PRINT_CALL_F_1_1(m_atan, .5);
    // PRINT_CALL_F_1_1(m_atan, 2.5);
    // PRINT_CALL_F_1_1(m_atan, -2.5);

    // PRINT_CALL_F_1_1(m_absf, 1.);
    // PRINT_CALL_F_1_1(m_absf, -1.);
    // PRINT_CALL_F_1_1(m_signf, -1.5);
    // PRINT_CALL_F_1_1(m_signf, 2859.);
    // PRINT_CALL_F_1_1(m_signf, -8272.5);

    PRINT_CALL_F_2_1(m_ln, .5, 1.);
    PRINT_CALL_F_2_1(m_ln, 1., 1.);
    PRINT_CALL_F_2_1(m_ln, 2.5, 1.);
    PRINT_CALL_F_2_1(m_ln, -1., 1.);

    return 0;
}
