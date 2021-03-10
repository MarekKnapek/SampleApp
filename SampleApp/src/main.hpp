#pragma once
#ifndef INCLUDE_GUARD_MAIN
#define INCLUDE_GUARD_MAIN


#include "mk_windows.hpp"


extern "C" int __stdcall wWinMain(mk::win::instance_t const instance, mk::win::instance_t const prev_instance, mk::win::widechar_t const* const cmd_line, int const cmd_show);


#endif
