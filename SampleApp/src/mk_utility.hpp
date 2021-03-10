#pragma once
#ifndef INCLUDE_GUARD_MK_UTILITY
#define INCLUDE_GUARD_MK_UTILITY


namespace mk
{

	template<typename t>
	class swap_t
	{
	public:
		void operator()(t& a, t& b) const;
	};

}


#include "mk_utility.inl"


#endif
