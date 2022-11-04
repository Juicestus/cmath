Justus' + (Suhas') Math Library in C

Convention
==========
Use underscores
Constants and macros: all uppercase
Everything else: all lowercase

Constants are prefixed with M_
Functions are prefixed with m_
Buffers are prefixed with r_
Types are prefixed with t_

Organization
============
Function declarations are in a single header file:
- cmath.h

Implementations are in seperate files:
- impl_simple.c Simple miscellaneous functions
- impl_exp.c Anything to do with exponents
- impl_trig.c Trig functions
- impl_arc.c Arc Trig functions

Main function for testing:
- test.c

Todo
====
- more accurate arc trig functions
- pow and root
- hyperbolic trig functions
- stat functions