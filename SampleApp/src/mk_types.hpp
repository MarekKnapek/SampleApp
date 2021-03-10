#pragma once
#ifndef INCLUDE_GUARD_MK_TYPES
#define INCLUDE_GUARD_MK_TYPES


#include "mk_macros.hpp"


namespace mk
{


#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
		typedef int ptrdiff_t;
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
		typedef __int64 ptrdiff_t;
#endif

#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
		typedef unsigned int size_t;
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
		typedef unsigned __int64 size_t;
#endif


}


#endif
