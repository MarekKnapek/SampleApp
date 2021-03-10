#include "mk_win_kernel.hpp"


extern "C" __declspec(dllimport) void __stdcall DebugBreak();
extern "C" __declspec(dllimport) void __stdcall GetStartupInfoW(mk::win::startup_info_t*);
extern "C" __declspec(dllimport) mk::win::module_t __stdcall GetModuleHandleW(mk::win::widechar_t const*);
extern "C" __declspec(dllimport) mk::win::widechar_t const* __stdcall GetCommandLineW();
extern "C" __declspec(dllimport) mk::win::dword_t __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) mk::win::handle_t __stdcall GetCurrentProcess();
extern "C" __declspec(dllimport) void __stdcall ExitProcess(mk::win::uint_t);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall TerminateProcess(mk::win::handle_t, mk::win::uint_t);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(mk::win::critical_section_t*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(mk::win::critical_section_t*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(mk::win::critical_section_t*);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall TryEnterCriticalSection(mk::win::critical_section_t*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(mk::win::critical_section_t*);


void mk::win::kernel::debug_break()
{
	DebugBreak();
}

void mk::win::kernel::get_startup_info(mk::win::startup_info_t& startup_info)
{
	GetStartupInfoW(&startup_info);
}

mk::win::module_t mk::win::kernel::get_module_handle(mk::win::widechar_t const* const module_name)
{
	mk::win::module_t const module_handle = GetModuleHandleW(module_name);
	return module_handle;
}

mk::win::widechar_t const* mk::win::kernel::get_command_line()
{
	mk::win::widechar_t const* const cmd_line = GetCommandLineW();
	return cmd_line;
}

mk::win::dword_t mk::win::kernel::get_current_thread_id()
{
	mk::win::dword_t const current_thread_id = GetCurrentThreadId();
	return current_thread_id;
}

mk::win::handle_t mk::win::kernel::get_current_process()
{
	mk::win::handle_t const handle = GetCurrentProcess();
	return handle;
}

void mk::win::kernel::exit_process(mk::win::uint_t const exit_code)
{
	ExitProcess(exit_code);
}

bool mk::win::kernel::terminate_process(mk::win::handle_t const process, mk::win::uint_t const exit_code)
{
	bool const terminated = TerminateProcess(process, exit_code).m_value != 0;
	return terminated;
}

void mk::win::kernel::initialize_critical_section(mk::win::critical_section_t& critical_section)
{
	InitializeCriticalSection(&critical_section);
}

void mk::win::kernel::delete_critical_section(mk::win::critical_section_t& critical_section)
{
	DeleteCriticalSection(&critical_section);
}

void mk::win::kernel::enter_critical_section(mk::win::critical_section_t& critical_section)
{
	EnterCriticalSection(&critical_section);
}

bool mk::win::kernel::try_enter_critical_section(mk::win::critical_section_t& critical_section)
{
	bool const entered = TryEnterCriticalSection(&critical_section).m_value != 0;
	return entered;
}

void mk::win::kernel::leave_critical_section(mk::win::critical_section_t& critical_section)
{
	LeaveCriticalSection(&critical_section);
}

