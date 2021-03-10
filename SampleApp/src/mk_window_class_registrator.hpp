#pragma once
#ifndef INCLUDE_GUARD_MK_WINDOW_CLASS_REGISTRATOR
#define INCLUDE_GUARD_MK_WINDOW_CLASS_REGISTRATOR


namespace mk
{

	template<typename t>
	struct window_class_registrator_t
	{
		window_class_registrator_t();
		~window_class_registrator_t();
	};

}


#include "mk_window_class_registrator.inl"


#endif
