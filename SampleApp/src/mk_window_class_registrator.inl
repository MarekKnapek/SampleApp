#include "mk_window_class_registrator.hpp"

#include "mk_check_ret.hpp"


template<typename t>
mk::window_class_registrator_t<t>::window_class_registrator_t()
{
	bool const registered = t::register_class();
	MK_CHECK_CRASH(registered);
}

template<typename t>
mk::window_class_registrator_t<t>::~window_class_registrator_t()
{
	bool const unregistered = t::unregister_class();
	MK_CHECK_CRASH(unregistered);
}
