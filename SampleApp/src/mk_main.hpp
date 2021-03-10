#pragma once
#ifndef INCLUDE_GUARD_MK_MAIN
#define INCLUDE_GUARD_MK_MAIN


#include "mk_windows.hpp"


namespace mk
{


	int win_main(mk::win::instance_t const instance, int const cmd_show);
	mk::win::instance_t get_instance();


}


#endif
