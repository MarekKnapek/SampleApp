#include "mk_win_user.hpp"


extern "C" __declspec(dllimport) mk::win::icon_t __stdcall LoadIconA(void*, mk::size_t);
extern "C" __declspec(dllimport) mk::win::cursor_t __stdcall LoadCursorA(void*, mk::size_t);
extern "C" __declspec(dllimport) mk::win::atom_t __stdcall RegisterClassExA(mk::win::window_classa_t const*);
extern "C" __declspec(dllimport) mk::win::atom_t __stdcall RegisterClassExW(mk::win::window_classw_t const*);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall UnregisterClassA(mk::size_t, mk::win::instance_t);
extern "C" __declspec(dllimport) mk::win::hwnd_t __stdcall CreateWindowExW(mk::win::dword_t, mk::size_t, mk::win::widechar_t const*, mk::win::dword_t, int, int, int, int, mk::win::hwnd_t, mk::win::menu_t, mk::win::instance_t, void*);
extern "C" __declspec(dllimport) mk::win::lresult_t __stdcall DefWindowProcW(mk::win::hwnd_t, mk::win::uint_t, mk::win::wparam_t, mk::win::lparam_t);
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386
extern "C" __declspec(dllimport) mk::size_t __stdcall GetWindowLongW(mk::win::hwnd_t, int);
extern "C" __declspec(dllimport) mk::size_t __stdcall SetWindowLongW(mk::win::hwnd_t, int, mk::size_t);
#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64
extern "C" __declspec(dllimport) mk::size_t __stdcall GetWindowLongPtrW(mk::win::hwnd_t, int);
extern "C" __declspec(dllimport) mk::size_t __stdcall SetWindowLongPtrW(mk::win::hwnd_t, int, mk::size_t);
#endif
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall PeekMessageW(mk::win::msg_t*, mk::win::hwnd_t, mk::win::uint_t, mk::win::uint_t, mk::win::uint_t);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall GetMessageW(mk::win::msg_t*, mk::win::hwnd_t, mk::win::uint_t, mk::win::uint_t);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall TranslateMessage(mk::win::msg_t const*);
extern "C" __declspec(dllimport) mk::win::lresult_t __stdcall DispatchMessageW(mk::win::msg_t const*);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall PostThreadMessageW(mk::win::dword_t, mk::win::uint_t, mk::win::wparam_t, mk::win::lparam_t);
extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int);
extern "C" __declspec(dllimport) mk::win::bool_t __stdcall ShowWindow(mk::win::hwnd_t, int);
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(mk::win::hwnd_t, char const*, char const*, mk::win::uint_t);


mk::win::icon_t mk::win::user::load_icon(mk::win::icon_id_e::icon_id_e const icon_id)
{
	mk::win::icon_t const icon = LoadIconA(MK_NULL, icon_id);
	return icon;
}

mk::win::cursor_t mk::win::user::load_cursor(mk::win::cursor_id_e::cursor_id_e const cursor_id)
{
	mk::win::cursor_t const cursor = LoadCursorA(MK_NULL, cursor_id);
	return cursor;
}

mk::win::brush_t mk::win::user::get_brush(mk::win::brush_id_e::brush_id_e const brush_id)
{
	mk::win::brush_t const brush = {reinterpret_cast<void*>(static_cast<mk::size_t>(brush_id + 1))};
	return brush;
}

mk::win::atom_t mk::win::user::register_window_class(mk::win::window_classa_t const& window_class)
{
	mk::win::atom_t const atom = RegisterClassExA(&window_class);
	return atom;
}

mk::win::atom_t mk::win::user::register_window_class(mk::win::window_classw_t const& window_class)
{
	mk::win::atom_t const atom = RegisterClassExW(&window_class);
	return atom;
}

bool mk::win::user::unregister_window_class(mk::win::atom_t const atom, mk::win::instance_t const instance)
{
	bool const unregistered = UnregisterClassA(atom.m_value, instance).m_value != 0;
	return unregistered;
}

mk::win::hwnd_t mk::win::user::create_window(mk::win::window_ex_style_e::window_ex_style_e const ex_style, mk::win::atom_t const atom, mk::win::widechar_t const* const name, mk::win::window_style_e::window_style_e const style, int const x, int const y, int const width, int const height, mk::win::hwnd_t const parent, mk::win::menu_t const menu, mk::win::instance_t const instance, void* const context)
{
	mk::win::dword_t const exstyle = {ex_style};
	mk::win::dword_t const stl = {style};
	mk::win::hwnd_t const hwnd = CreateWindowExW(exstyle, atom.m_value, name, stl, x, y, width, height, parent, menu, instance, context);
	return hwnd;
}

mk::win::lresult_t mk::win::user::def_window_proc(mk::win::hwnd_t const hwnd, mk::win::uint_t const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam)
{
	mk::win::lresult_t const lresult = DefWindowProcW(hwnd, msg, wparam, lparam);
	return lresult;
}

mk::size_t mk::win::user::get_window_long(mk::win::hwnd_t const hwnd, mk::win::window_long_e::window_long_e const index)
{
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386

	mk::size_t const lng = GetWindowLongW(hwnd, index);
	return lng;

#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64

	mk::size_t const lng = GetWindowLongPtrW(hwnd, index);
	return lng;

#endif
}

mk::size_t mk::win::user::set_window_long(mk::win::hwnd_t const hwnd, mk::win::window_long_e::window_long_e const index, mk::size_t const new_value)
{
#if MK_ARCHITECTURE == MK_ARCHITECTURE_I386

	mk::size_t const old_value = SetWindowLongW(hwnd, index, new_value);
	return old_value;

#elif MK_ARCHITECTURE == MK_ARCHITECTURE_AMD64

	mk::size_t const old_value = SetWindowLongPtrW(hwnd, index, new_value);
	return old_value;

#endif
}

bool mk::win::user::peek_message(mk::win::msg_t& msg, mk::win::hwnd_t const hwnd, mk::win::uint_t const filter_min, mk::win::uint_t const filter_max, mk::win::peek_message_e::peek_message_e const removal_flags)
{
	mk::win::uint_t const removal_flagss = {removal_flags};
	bool const peeked = PeekMessageW(&msg, hwnd, filter_min, filter_max, removal_flagss).m_value != 0;
	return peeked;
}

mk::win::bool_t mk::win::user::get_message(mk::win::msg_t& msg, mk::win::hwnd_t const hwnd, mk::win::uint_t const filter_min, mk::win::uint_t const filter_max)
{
	mk::win::bool_t const got = GetMessageW(&msg, hwnd, filter_min, filter_max);
	return got;
}

bool mk::win::user::translate_message(mk::win::msg_t const& msg)
{
	bool const translated = TranslateMessage(&msg).m_value != 0;
	return translated;
}

mk::win::lresult_t mk::win::user::dispatch_message(mk::win::msg_t const& msg)
{
	mk::win::lresult_t const lresult = DispatchMessageW(&msg);
	return lresult;
}

bool mk::win::user::post_thread_message(mk::win::dword_t const thread_id, mk::win::wm_e::wm_e const msg, mk::win::wparam_t const wparam, mk::win::lparam_t const lparam)
{
	mk::win::uint_t const msgg = {msg};
	bool const posted = PostThreadMessageW(thread_id, msgg, wparam, lparam).m_value != 0;
	return posted;
}

void mk::win::user::post_quit_message(int const exit_code)
{
	PostQuitMessage(exit_code);
}

bool mk::win::user::show_window(mk::win::hwnd_t const hwnd, int const cmd_show)
{
	bool const shown = ShowWindow(hwnd, cmd_show).m_value != 0;
	return shown;
}

int mk::win::user::message_box(mk::win::hwnd_t const hwnd, char const* const text, char const* const caption, mk::win::mb_e::mb_e const type)
{
	mk::win::uint_t const typee = {type};
	int const msg = MessageBoxA(hwnd, text, caption, typee);
	return msg;
}
