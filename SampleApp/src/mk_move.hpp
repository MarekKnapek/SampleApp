#pragma once
#ifndef INCLUDE_GUARD_MK_MOVE


namespace mk
{


	template<typename t>
	struct move_t
	{
		t* m_value;
	};

	template<typename t>
	mk::move_t<t> move(t& value);


}


#include "mk_move.inl"


#endif
