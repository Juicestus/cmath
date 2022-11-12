/// @: Justus Languell <jlanguell@extendable.co>

#ifndef __TEST_MACROS_H__
#define __TEST_MACROS_H__

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define __VAR_FLOAT_TERMINATOR -.8028533846193f
#define __EPSILON_ERROR 0.0000000000001f
#define __PRINT_FUNCTION_SIGNATURE(f) printf("%s(", #f)
#define __PRINT_FUNCTION_CLOSURE() printf(") = ")
#define __FLOAT_FORMAT "%4.3f"
#define __PRINT_FUNCTION_ARGUMENTS(...)                                        \
  __print_variatic_floats(", ", ##__VA_ARGS__, __VAR_FLOAT_TERMINATOR)

static void __print_variatic_floats(char* str_delim, ...)
{
  va_list l_args;
  va_start(l_args, str_delim);
  double r_arg = va_arg(l_args, double);

  while (1) {
    printf(__FLOAT_FORMAT, r_arg);
    if ((r_arg = va_arg(l_args, double)) == __VAR_FLOAT_TERMINATOR) break;
    printf("%s", str_delim);
  }
}

/// Nice way to print functions.
/// Params:
///   f: Function that:
///     - Takes any number of floats arguments
///     - Last parameter is a float* result buffer
///     - Returns 0 on success, 1 on failure
///   ...: Any number of floats to pass to f
#define F_PRINT_CALL(f, ...)                                                   \
  {                                                                            \
    float __r_##f;                                                             \
    __PRINT_FUNCTION_SIGNATURE(f);                                             \
    __PRINT_FUNCTION_ARGUMENTS(__VA_ARGS__);                                   \
    __PRINT_FUNCTION_CLOSURE();                                                \
    if (!f(__VA_ARGS__, &__r_##f))                                             \
      printf(__FLOAT_FORMAT "\n", __r_##f);                                    \
    else                                                                       \
      printf("ERROR\n");                                                       \
  }

#define ERROR 1.

/// Nice way to print functions.
/// Params:
///   e: Expected result or ERROR if expected to error
///   f: Function that:
///     - Takes any number of floats arguments
///     - Last parameter is a float* result buffer
///     - Returns 0 on success, 1 on failure
///   ...: Any number of floats to pass to f
#define F_TEST_CASE(e, f, ...)                                                 \
  {                                                                            \
    float __r_##f;                                                             \
    const int wf = !strcmp("ERROR", #e);                                       \
    __PRINT_FUNCTION_SIGNATURE(f);                                             \
    __PRINT_FUNCTION_ARGUMENTS(__VA_ARGS__);                                   \
    __PRINT_FUNCTION_CLOSURE();                                                \
    unsigned int pass;                                                         \
    if (!f(__VA_ARGS__, &__r_##f)) {                                           \
      printf(__FLOAT_FORMAT, __r_##f);                                         \
      pass = __r_##f <= e + __EPSILON_ERROR && \
          __r_##f >=  - __EPSILON_ERROR && !wf;                                              \
    }                                                                          \
    else {                                                                     \
      printf("ERROR");                                                         \
      pass = wf;                                                               \
    }                                                                          \
    printf(" %s ", pass ? "==" : "!=");                                        \
    if (wf)                                                                    \
      printf("ERROR");                                                         \
    else                                                                       \
      printf(__FLOAT_FORMAT, e);                                               \
    printf(" [%s]\n", pass ? "PASS" : "FAIL");                                 \
  }

/// A goofy function to test F_TEST_CASE
int m_test(const float v1, const float v2, float* result)
{
  if (v1 == v2) return 1;
  *result = v1 * v2;
  return 0;
}

#endif