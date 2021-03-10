#pragma once
#ifndef INCLUDE_GUARD_MK_CSTDLIB
#define INCLUDE_GUARD_MK_CSTDLIB


#include "mk_types.hpp"


namespace mk
{

	void* allocate(mk::size_t const len);
	void deallocate(void* const ptr);

}


#endif
