/// @: Justus Languell <jlanguell@extendable.co>

#ifndef __TEST_MACROS_H__
#define __TEST_MACROS_H__

#include <stdarg.h>
#include <stdio.h>

#define __FLOAT_FORMAT "%.6f"

static void __print_variatic_floats(int n, ...)
{
  va_list l_args;
  va_start(l_args, n);
  for (;;)
  {
    printf(__FLOAT_FORMAT, va_arg(l_args, double));
    if (!--n) break;
    printf(", ");
  }
  va_end(l_args);
}

#define __NUM_FLOAT_ARGS(...) (sizeof ((float[]){__VA_ARGS__}) / sizeof (float))

#define __PRINT_FUNC_ARGS(...) __print_variatic_floats(__NUM_FLOAT_ARGS(__VA_ARGS__), ##__VA_ARGS__)

#define __PRINT_FUNC_CALL(f, ...)\
{\
  const float r = f(__VA_ARGS__);\
  printf("%s(", #f);\
  __PRINT_FUNC_ARGS(__VA_ARGS__);\
  printf(") = " __FLOAT_FORMAT "\n", r);\
}

#define __BOTH(f, r, e) f(r) && f(e)
#define __ACCEPTABLE_ERROR 0.00001f // 1e-4f
#define __CLOSE(x, v) (x <= v + __ACCEPTABLE_ERROR && x >= v - __ACCEPTABLE_ERROR)

#define __TEST_FUNC_CALL(e, f, ...)\
{\
  const float r = f(__VA_ARGS__);\
  const unsigned short p = __CLOSE(r, e) || __BOTH(m_isposinf, r, e) ||\
      __BOTH(m_isneginf, r, e) || __BOTH(m_isnan, r, e);\
  printf("[%s] %s(", p ? "PASS" : "FAIL", #f);\
  __PRINT_FUNC_ARGS(__VA_ARGS__);\
  printf(") = " __FLOAT_FORMAT " %s= " __FLOAT_FORMAT "\n",\
      r, p ? "=" : "!", e);\
}

#ifndef TEST
  #define TEST(e, f, ...) __TEST_FUNC_CALL(e, f, __VA_ARGS__) 
#else
  #warning "Macro symbol TEST already defined"
#endif

#endif