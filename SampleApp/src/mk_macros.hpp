#pragma once
#ifndef INCLUDE_GUARD_MK_MACROS


#define MK_ARCHITECTURE_I386 2
#define MK_ARCHITECTURE_AMD64 3

#ifdef _M_IX86
# define MK_ARCHITECTURE MK_ARCHITECTURE_I386
#else
# ifdef _M_X64
#  define MK_ARCHITECTURE MK_ARCHITECTURE_AMD64
# else
#  error Unknown architecture.
# endif
#endif


#define MK_NULL 0
#define MK_STATIC_ASSERT(X) { char arr[(X) ? 1 : 0]; (void)arr; }


#endif
