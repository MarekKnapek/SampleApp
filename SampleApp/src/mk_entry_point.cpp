#ifdef MK_ENTRY


#include "mk_win_kernel.hpp"
#include "main.hpp"


extern "C" int __stdcall entry_point()
{
	mk::win::widechar_t const* const null_module_name = MK_NULL;
	mk::win::module_t const module_handle = mk::win::kernel::get_module_handle(null_module_name);

	mk::win::startup_info_t startup_info;
	startup_info.m_flags.m_value = 0;
	mk::win::kernel::get_startup_info(startup_info);

	mk::win::instance_t const instance = {module_handle.m_value};
	mk::win::instance_t const prev_instance = {MK_NULL};
	mk::win::widechar_t const* const cmd_line = mk::win::kernel::get_command_line();
	int const cmd_show = ((startup_info.m_flags.m_value & mk::win::startup_info_e::useshowwindow) != 0) ? startup_info.m_show_window.m_value : mk::win::show_window_e::showdefault;
	int const exit_code = wWinMain(instance, prev_instance, cmd_line, cmd_show);
	
	mk::win::uint_t const exit_codee = {exit_code};
	mk::win::kernel::exit_process(exit_codee);

	mk::win::handle_t const current_process = mk::win::kernel::get_current_process();
	bool const terminated = mk::win::kernel::terminate_process(current_process, exit_codee); (void)terminated;

	mk::win::kernel::debug_break();

	return exit_code;
}


#else


#endif
