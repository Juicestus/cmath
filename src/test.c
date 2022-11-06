#include <stdio.h>

#include "cmath.h"

// Ugly macro
#define PRINT_CALL_F_1_1(n, x)                          \
    {                                                   \
        float __buff_##n;                               \
        if (!n(x, &__buff_##n))                         \
            printf("%s(%f) = %f\n", #n, x, __buff_##n); \
        else                                            \
            printf("%s(%f) errored\n", #n, x);          \
    }
#define PRINT_CALL_F_2_1(n, x, y)                              \
    {                                                          \
        float __buff_##n;                                      \
        if (!n(x, y, &__buff_##n))                             \
            printf("%s(%f, %f) = %f\n", #n, x, y, __buff_##n); \
        else                                                   \
            printf("%s(%f, %f) errored\n", #n, x, y);          \
    }

#define PRINT_CALL_F_3_1(n, x, y, z)                                  \
    {                                                                 \
        float __buff_##n;                                             \
        if (!n(x, y, z, &__buff_##n))                                 \
            printf("%s(%f, %f, %f) = %f\n", #n, x, y, z, __buff_##n); \
        else                                                          \
            printf("%s(%f, %f, %f) errored\n", #n, x, y, z);          \
    }

#define PRINT_CALL_F_4_1(n, x, y, z, w)                                      \
    {                                                                        \
        float __buff_##n;                                                    \
        if (!n(x, y, z, w, &__buff_##n))                                     \
            printf("%s(%f, %f, %f, %f) = %f\n", #n, x, y, z, w, __buff_##n); \
        else                                                                 \
            printf("%s(%f, %f, %f, %f) errored\n", #n, x, y, z, w);          \
    }

int main(const int argc, const char **argv)
{
    // PRINT_CALL_F_1_1(m_sin, M_PI / 6);

    // const double x = M_PI_2 / 3.;
    // PRINT_CALL_F_1_1(m_sin, x);
    // PRINT_CALL_F_1_1(m_cos, x);
    // PRINT_CALL_F_1_1(m_tan, x);
    // PRINT_CALL_F_1_1(m_csc, x);
    // PRINT_CALL_F_1_1(m_sec, x);
    // PRINT_CALL_F_1_1(m_cot, x);

    // PRINT_CALL_F_1_1(m_absf, -773.20948852);
    // PRINT_CALL_F_1_1(m_absf, 2288489.20948852);

    // printf("%lu\n", sizeof(float) * 8);
    // printf("%lu\n", sizeof(double) * 8);

    // PRINT_CALL_F_1_1(m_sqrt, 4.);
    // PRINT_CALL_F_1_1(m_sqrt, .8);
    // PRINT_CALL_F_1_1(m_sqrt, 2.5);
    // PRINT_CALL_F_1_1(m_sqrt, -1.);

    // PRINT_CALL_F_1_1(m_asin, .5);
    // PRINT_CALL_F_1_1(m_acos, .5);
    // PRINT_CALL_F_1_1(m_atan, .5);
    // PRINT_CALL_F_1_1(m_atan, 2.5);
    // PRINT_CALL_F_1_1(m_atan, -2.5);

    // PRINT_CALL_F_1_1(m_signf, -1.5);
    // PRINT_CALL_F_1_1(m_signf, 2859.);
    // PRINT_CALL_F_1_1(m_signf, -8272.5);

    // PRINT_CALL_F_1_1(m_exp, -4.5);
    // PRINT_CALL_F_1_1(m_exp, 2.5);
    // PRINT_CALL_F_1_1(m_ln, -.5);
    // PRINT_CALL_F_1_1(m_ln, 0.);
    // PRINT_CALL_F_1_1(m_ln, 1.);
    // PRINT_CALL_F_2_1(m_log, 2., 5.);

    // PRINT_CALL_F_2_1(m_pow, 4., .5);
    // PRINT_CALL_F_2_1(m_pow, -2., 5.);
    // PRINT_CALL_F_2_1(m_pow, -2., .4);
    // PRINT_CALL_F_2_1(m_pow, .2, 2.);
    // PRINT_CALL_F_2_1(m_pow, -.2, 2.);
    // PRINT_CALL_F_2_1(m_pow, -.2, .2);
    // PRINT_CALL_F_2_1(m_pow, -.2, -.2);

    // PRINT_CALL_F_3_1(m_zscore, 2., 2., 3.);
    // PRINT_CALL_F_3_1(m_normalcdf, 2., 0., 1.);
    // PRINT_CALL_F_4_1(m_normalcdfrange, 2., 5., 2.5, 0.5);
    // PRINT_CALL_F_1_1(m_invnormalcdf_p, 0.341);

    return 0;
}
