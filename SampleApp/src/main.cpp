#include "mk_main.hpp"


extern "C" int __stdcall wWinMain(mk::win::instance_t const instance, mk::win::instance_t const prev_instance, mk::win::widechar_t const* const cmd_line, int const cmd_show)
{
	(void)prev_instance;
	(void)cmd_line;
	int const exit_code = mk::win_main(instance, cmd_show);
	return exit_code;
}
