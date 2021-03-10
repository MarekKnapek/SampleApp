#include "mk_main_window.hpp"

#include "mk_assert.hpp"
#include "mk_check_ret.hpp"
#include "mk_main.hpp"
#include "mk_win_user.hpp"


mk::win::atom_t mk::main_window_t::g_atom;


bool mk::main_window_t::register_class()
{
	MK_ASSERT(g_atom.m_value == 0);

	mk::win::window_classw_t wc;
	wc.m_size.m_value = sizeof(wc);
	wc.m_style.m_value = 0;
	wc.m_window_procedure.m_value = &window_procedure_static;
	wc.m_class_extra = 0;
	wc.m_object_extra = 0;
	wc.m_instance = mk::get_instance();
	wc.m_icon = mk::win::user::load_icon(mk::win::icon_id_e::application);
	wc.m_cursor = mk::win::user::load_cursor(mk::win::cursor_id_e::arrow);
	wc.m_background = mk::win::user::get_brush(mk::win::brush_id_e::window);
	wc.m_menu_name = reinterpret_cast<mk::win::widechar_t const*>(mk::win::s_null);
	wc.m_class_name = reinterpret_cast<mk::win::widechar_t const*>(L"main_window");
	wc.m_icon_small = mk::win::user::load_icon(mk::win::icon_id_e::application);

	mk::win::atom_t const atom = mk::win::user::register_window_class(wc);
	MK_CHECK_RET_F(atom.m_value != 0);

	g_atom = atom;
	return true;
}

bool mk::main_window_t::unregister_class()
{
	MK_ASSERT(g_atom.m_value != 0);

	bool const unregistered = mk::win::user::unregister_window_class(g_atom, mk::get_instance());
	MK_CHECK_RET_F(unregistered);

	return true;
}

mk::win::lresult_t MK_WIN_STDCALL mk::main_window_t::window_procedure_static(mk::win::hwnd_t const hwnd, mk::win::uint_t const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam)
{
	if(msg.m_value == mk::win::wm_e::create)
	{
		mk::win::wm_create_t& wc = *reinterpret_cast<mk::win::wm_create_t*>(lparam.m_value);
		void* const context = wc.m_context;
		mk::main_window_t* const self = static_cast<mk::main_window_t*>(context);
		mk::win::user::set_window_long(hwnd, mk::win::window_long_e::user_data, reinterpret_cast<mk::size_t>(self));
	}

	mk::size_t const user_data = mk::win::user::get_window_long(hwnd, mk::win::window_long_e::user_data);
	if(user_data != 0)
	{
		mk::main_window_t& self = *reinterpret_cast<mk::main_window_t*>(user_data);
		mk::win::lresult_t const lresult = self.window_procedure(msg, wparam, lparam);
		return lresult;
	}

	mk::win::lresult_t const default_lresult = mk::win::user::def_window_proc(hwnd, msg, wparam, lparam);
	return default_lresult;
}

mk::main_window_t::main_window_t() :
	m_hwnd()
{
	mk::win::hwnd_t const parent = {mk::win::s_null};
	mk::win::menu_t const menu = {mk::win::s_null};
	mk::win::widechar_t const* const name = reinterpret_cast<mk::win::widechar_t const*>(L"Main Window");

	mk::win::hwnd_t const hwnd = mk::win::user::create_window(mk::win::window_ex_style_e::overlapped_window, g_atom, name, mk::win::window_style_e::overlapped_window, mk::win::cw_default, mk::win::cw_default, mk::win::cw_default, mk::win::cw_default, parent, menu, mk::get_instance(), this);
	MK_CHECK_RET(hwnd.m_value != mk::win::s_null);

	m_hwnd = hwnd;
}

mk::main_window_t::~main_window_t()
{
}

mk::win::hwnd_t mk::main_window_t::get_hwnd() const
{
	return m_hwnd;
}

mk::win::lresult_t mk::main_window_t::window_procedure(mk::win::uint_t const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam)
{
	switch(msg.m_value)
	{
		case mk::win::wm_e::destroy:
		{
			mk::win::user::post_quit_message(0);
		}
		break;
	}
	mk::win::lresult_t const default_lresult = mk::win::user::def_window_proc(m_hwnd, msg, wparam, lparam);
	return default_lresult;
}
