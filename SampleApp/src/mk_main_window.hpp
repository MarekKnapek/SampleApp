#pragma once
#ifndef INCLUDE_GUARD_MK_MAIN_WINDOW
#define INCLUDE_GUARD_MK_MAIN_WINDOW


#include "mk_windows.hpp"


namespace mk
{

	class main_window_t
	{
	public:
		static bool register_class();
		static bool unregister_class();
		static mk::win::lresult_t MK_WIN_STDCALL window_procedure_static(mk::win::hwnd_t const hwnd, mk::win::uint_t const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam);
	public:
		main_window_t();
		~main_window_t();
	public:
		mk::win::hwnd_t get_hwnd() const;
		mk::win::lresult_t window_procedure(mk::win::uint_t const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam);
	private:
		static mk::win::atom_t g_atom;
	private:
		mk::win::hwnd_t m_hwnd;
	};

}


#endif
