#pragma once
#ifndef INCLUDE_GUARD_MK_WIN_USER
#define INCLUDE_GUARD_MK_WIN_USER


#include "mk_windows.hpp"


namespace mk
{
	namespace win
	{
		namespace user
		{

			mk::win::icon_t load_icon(mk::win::icon_id_e::icon_id_e const icon_id);
			mk::win::cursor_t load_cursor(mk::win::cursor_id_e::cursor_id_e const cursor_id);
			mk::win::brush_t get_brush(mk::win::brush_id_e::brush_id_e const brush_id);
			mk::win::atom_t register_window_class(mk::win::window_classa_t const& window_class);
			mk::win::atom_t register_window_class(mk::win::window_classw_t const& window_class);
			bool unregister_window_class(mk::win::atom_t const atom, mk::win::instance_t const instance);
			mk::win::hwnd_t create_window(mk::win::window_ex_style_e::window_ex_style_e const ex_style, mk::win::atom_t const atom, mk::win::widechar_t const* const name, mk::win::window_style_e::window_style_e const style, int const x, int const y, int const width, int const height, mk::win::hwnd_t const parent, mk::win::menu_t const menu, mk::win::instance_t const instance, void* const context);
			mk::win::lresult_t def_window_proc(mk::win::hwnd_t const hwnd, mk::win::uint_t const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam);
			mk::size_t get_window_long(mk::win::hwnd_t const hwnd, mk::win::window_long_e::window_long_e const index);
			mk::size_t set_window_long(mk::win::hwnd_t const hwnd, mk::win::window_long_e::window_long_e const index, mk::size_t const new_value);
			bool peek_message(mk::win::msg_t& msg, mk::win::hwnd_t const hwnd, mk::win::uint_t const filter_min, mk::win::uint_t const filter_max, mk::win::peek_message_e::peek_message_e const removal_flags);
			mk::win::bool_t get_message(mk::win::msg_t& msg, mk::win::hwnd_t const hwnd, mk::win::uint_t const filter_min, mk::win::uint_t const filter_max);
			bool translate_message(mk::win::msg_t const& msg);
			mk::win::lresult_t dispatch_message(mk::win::msg_t const& msg);
			bool post_thread_message(mk::win::dword_t const thread_id, mk::win::wm_e::wm_e const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam);
			void post_quit_message(int const exit_code);
			bool show_window(mk::win::hwnd_t const hwnd, int const cmd_show);
			int message_box(mk::win::hwnd_t const hwnd, char const* const text, char const* const caption, mk::win::mb_e::mb_e const type);

		}
	}
}


#endif
