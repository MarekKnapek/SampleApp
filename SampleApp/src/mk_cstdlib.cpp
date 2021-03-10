#include "mk_cstdlib.hpp"


#ifdef MK_ENTRY


extern "C" __declspec(dllimport) void* __cdecl malloc(mk::size_t);
extern "C" __declspec(dllimport) void __cdecl free(void*);


#else


#include <cstdlib>


#endif


void* mk::allocate(mk::size_t const len)
{
	void* const ret = malloc(len);
	return ret;
}

void mk::deallocate(void* const ptr)
{
	free(ptr);
}
