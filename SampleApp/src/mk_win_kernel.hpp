#pragma once
#ifndef INCLUDE_GUARD_MK_WIN_KERNEL
#define INCLUDE_GUARD_MK_WIN_KERNEL


#include "mk_windows.hpp"


namespace mk
{
	namespace win
	{
		namespace kernel
		{

			void debug_break();
			void get_startup_info(mk::win::startup_info_t& startup_info);
			mk::win::module_t get_module_handle(mk::win::widechar_t const* const module_name);
			mk::win::widechar_t const* get_command_line();
			mk::win::dword_t get_current_thread_id();
			mk::win::handle_t get_current_process();
			void exit_process(mk::win::uint_t const exit_code);
			bool terminate_process(mk::win::handle_t const process, mk::win::uint_t const exit_code);
			void initialize_critical_section(mk::win::critical_section_t& critical_section);
			void delete_critical_section(mk::win::critical_section_t& critical_section);
			void enter_critical_section(mk::win::critical_section_t& critical_section);
			bool try_enter_critical_section(mk::win::critical_section_t& critical_section);
			void leave_critical_section(mk::win::critical_section_t& critical_section);

		}
	}
}


#endif
