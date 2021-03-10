#pragma once
#ifndef INCLUDE_GUARD_MK_WINDOWS
#define INCLUDE_GUARD_MK_WINDOWS


#include "mk_macros.hpp"
#include "mk_types.hpp"


#define MK_WIN_STDCALL __stdcall


namespace mk
{
	namespace win
	{


		void* const s_null = 0;
		int const cw_default = static_cast<int>(0x80000000);


		namespace icon_id_e
		{
			enum icon_id_e
			{
				application = 32512,
				hand        = 32513, // error
				question    = 32514,
				exclamation = 32515, // warning
				asterisk    = 32516, // information
				winlogo     = 32517, // WINVER >= 0x0400
				shield      = 32518, // WINVER >= 0x0600
			};
		}

		namespace cursor_id_e
		{
			enum cursor_id_e
			{
				arrow       = 32512,
				ibeam       = 32513,
				wait        = 32514,
				cross       = 32515,
				uparrow     = 32516,
				size        = 32640, // obsolete, use sizeall
				icon        = 32641, // obsolete, use arrow
				sizenwse    = 32642,
				sizenesw    = 32643,
				sizewe      = 32644,
				sizens      = 32645,
				sizeall     = 32646,
				no          = 32648, // not in win3.1
				hand        = 32649, // WINVER >= 0x0500
				appstarting = 32650, // not in win3.1
				help        = 32651, // WINVER >= 0x0400
			};
		}

		namespace brush_id_e
		{
			enum brush_id_e
			{
				scrollbar               = 0,
				background              = 1,
				activecaption           = 2,
				inactivecaption         = 3,
				menu                    = 4,
				window                  = 5,
				windowframe             = 6,
				menutext                = 7,
				windowtext              = 8,
				captiontext             = 9,
				activeborder            = 10,
				inactiveborder          = 11,
				appworkspace            = 12,
				highlight               = 13,
				highlighttext           = 14,
				btnface                 = 15,
				btnshadow               = 16,
				graytext                = 17,
				btntext                 = 18,
				inactivecaptiontext     = 19,
				btnhighlight            = 20,
				triddkshadow            = 21, // WINVER >= 0x0400
				tridlight               = 22, // WINVER >= 0x0400
				infotext                = 23, // WINVER >= 0x0400
				infobk                  = 24, // WINVER >= 0x0400
				hotlight                = 26, // WINVER >= 0x0500
				gradientactivecaption   = 27, // WINVER >= 0x0500
				gradientinactivecaption = 28, // WINVER >= 0x0500
				menuhilight             = 29, // WINVER >= 0x0501
				menubar                 = 30, // WINVER >= 0x0501
				desktop                 = background,   // WINVER >= 0x0400
				tridface                = btnface,      // WINVER >= 0x0400
				tridshadow              = btnshadow,    // WINVER >= 0x0400
				tridhighligh            = btnhighlight, // WINVER >= 0x0400
				tridhilight             = btnhighlight, // WINVER >= 0x0400
				btnhilight              = btnhighlight, // WINVER >= 0x0400
			};
		}

		namespace window_long_e
		{
			enum window_long_e
			{
				proc      = -4,
				instance  = -6,
				parent    = -8,
				id        = -12,
				style     = -16, // not available on 64 bit
				ex_style  = -20, // not available on 64 bit
				user_data = -21,
			};
		}

		namespace startup_info_e
		{
			enum startup_info_e
			{
				useshowwindow    = 0x00000001,
				usesize          = 0x00000002,
				useposition      = 0x00000004,
				usecountchars    = 0x00000008,
				usefillattribute = 0x00000010,
				runfullscreen    = 0x00000020, // ignored for non-x86 platforms
				forceonfeedback  = 0x00000040,
				forceofffeedback = 0x00000080,
				usestdhandles    = 0x00000100,
			};
		}

		namespace show_window_e
		{
			enum show_window_e
			{
				hide            = 0,
				shownormal      = 1,
				normal          = 1,
				showminimized   = 2,
				showmaximized   = 3,
				maximize        = 3,
				shownoactivate  = 4,
				show            = 5,
				minimize        = 6,
				showminnoactive = 7,
				showna          = 8,
				restore         = 9,
				showdefault     = 10,
				forceminimize   = 11,
				max             = 11,
			};
		}

		namespace peek_message_e
		{
			enum peek_message_e
			{
				noremove = 0x0000,
				remove   = 0x0001,
			};
		}

		namespace wm_e
		{
			enum wm_e
			{
				null    = 0x0000,
				create  = 0x0001,
				destroy = 0x0002,
				quit    = 0x0012,
			};
		}

		namespace window_ex_style_e
		{
			enum window_ex_style_e
			{
				window_edge       = 0x00000100L,
				client_edge       = 0x00000200L,
				overlapped_window = window_edge | client_edge,
			};
		}

		namespace window_style_e
		{
			enum window_style_e
			{
				overlapped        = 0x00000000L,
				caption           = 0x00C00000L,
				sys_menu          = 0x00080000L,
				thick_frame       = 0x00040000L,
				minimize_box      = 0x00020000L,
				maixmize_box      = 0x00010000L,
				overlapped_window = overlapped | caption | sys_menu | thick_frame | minimize_box | maixmize_box,
			};
		}

		namespace mb_e
		{
			enum mb_e
			{
				ok                        = 0x00000000L,
				okcancel                  = 0x00000001L,
				abortretryignore          = 0x00000002L,
				yesnocancel               = 0x00000003L,
				yesno                     = 0x00000004L,
				retrycancel               = 0x00000005L,
				canceltrycontinue         = 0x00000006L, // WINVER >= 0x0500
				iconhand                  = 0x00000010L,
				iconquestion              = 0x00000020L,
				iconexclamation           = 0x00000030L,
				iconasterisk              = 0x00000040L,
				usericon                  = 0x00000080L,     // WINVER >= 0x0400
				iconwarning               = iconexclamation, // WINVER >= 0x0400
				iconerror                 = iconhand,        // WINVER >= 0x0400
				iconinformation           = iconasterisk,
				iconstop                  = iconhand,
				defbutton1                = 0x00000000L,
				defbutton2                = 0x00000100L,
				defbutton3                = 0x00000200L,
				defbutton4                = 0x00000300L, // WINVER >= 0x0400
				applmodal                 = 0x00000000L,
				systemmodal               = 0x00001000L,
				taskmodal                 = 0x00002000L,
				help                      = 0x00004000L,  // WINVER >= 0x0400
				nofocus                   = 0x00008000L,
				setforeground             = 0x00010000L,
				default_desktop_only      = 0x00020000L,
				topmost                   = 0x00040000L, // WINVER >= 0x0400
				right                     = 0x00080000L, // WINVER >= 0x0400
				rtlreading                = 0x00100000L, // WINVER >= 0x0400
				service_notification      = 0x00200000L, // _WIN32_WINNT >= 0x0400
				//service_notification      = 0x00040000L, // _WIN32_WINNT
				service_notification_nt3x = 0x00040000L, // _WIN32_WINNT
				typemask                  = 0x0000000FL,
				iconmask                  = 0x000000F0L,
				defmask                   = 0x00000F00L,
				modemask                  = 0x00003000L,
				miscmask                  = 0x0000C000L,
			};
		}


	}
}


namespace mk
{
	namespace win
	{


		struct brush_t    { void* m_value; };
		struct cursor_t   { void* m_value; };
		struct handle_t   { void* m_value; };
		struct hwnd_t     { void* m_value; };
		struct icon_t     { void* m_value; };
		struct instance_t { void* m_value; };
		struct menu_t     { void* m_value; };
		struct module_t   { void* m_value; };

		struct atom_t     { unsigned short int m_value; };
		struct widechar_t { unsigned short int m_value; };
		struct word_t     { unsigned short int m_value; };

		struct dword_t { unsigned int m_value; };
		struct uint_t  { unsigned int m_value; };

		struct bool_t { signed long int m_value; };
		struct long_t { signed long int m_value; };

		struct lresult_t { mk::ptrdiff_t m_value; };

		struct lparam_t { mk::size_t m_value; };
		struct wparam_t { mk::size_t m_value; };

		struct window_procedure_t
		{
			mk::win::lresult_t(MK_WIN_STDCALL*m_value)(mk::win::hwnd_t const, mk::win::uint_t const, mk::win::wparam_t const, mk::win::lparam_t const);
		};

		struct list_entry_t
		{
			void* m_next;
			void* m_prev;
		};

		struct critical_section_t;

		struct critical_section_debug_t
		{
			mk::win::word_t m_type;
			mk::win::word_t m_creator_back_trace_index;
			mk::win::critical_section_t* m_critical_section;
			mk::win::list_entry_t m_process_locks_list;
			mk::win::dword_t m_entry_count;
			mk::win::dword_t m_contention_count;
			mk::win::dword_t m_flags;
			mk::win::word_t m_creator_back_trace_index_high;
			mk::win::word_t m_reserved;
		};

		struct critical_section_t
		{
			critical_section_debug_t* m_critical_section_debug;
			mk::win::long_t m_lock_count;
			mk::win::long_t m_recursion_count;
			mk::win::handle_t m_owning_thread;
			mk::win::handle_t m_lock_semaphore;
			mk::size_t m_spin_count;
		};

		struct startup_info_t
		{
			mk::win::dword_t m_size;
			mk::win::widechar_t m_reserved_1;
			mk::win::widechar_t m_desktop;
			mk::win::widechar_t m_title;
			mk::win::dword_t m_x;
			mk::win::dword_t m_y;
			mk::win::dword_t m_x_size;
			mk::win::dword_t m_y_size;
			mk::win::dword_t m_x_count_chars;
			mk::win::dword_t m_y_count_chars;
			mk::win::dword_t m_fill_attribute;
			mk::win::dword_t m_flags;
			mk::win::word_t m_show_window;
			mk::win::word_t m_reserved_2;
			void* m_reserved_3;
			mk::win::handle_t m_std_input;
			mk::win::handle_t m_std_output;
			mk::win::handle_t m_std_error;
		};

		struct window_classa_t
		{
			mk::win::uint_t m_size;
			mk::win::uint_t m_style;
			mk::win::window_procedure_t m_window_procedure;
			int m_class_extra;
			int m_object_extra;
			mk::win::instance_t m_instance;
			mk::win::icon_t m_icon;
			mk::win::cursor_t m_cursor;
			mk::win::brush_t m_background;
			char const* m_menu_name;
			char const* m_class_name;
			mk::win::icon_t m_icon_small;
		};

		struct window_classw_t
		{
			mk::win::uint_t m_size;
			mk::win::uint_t m_style;
			mk::win::window_procedure_t m_window_procedure;
			int m_class_extra;
			int m_object_extra;
			mk::win::instance_t m_instance;
			mk::win::icon_t m_icon;
			mk::win::cursor_t m_cursor;
			mk::win::brush_t m_background;
			mk::win::widechar_t const* m_menu_name;
			mk::win::widechar_t const* m_class_name;
			mk::win::icon_t m_icon_small;
		};

		struct point_t
		{
			mk::win::long_t x;
			mk::win::long_t y;
		};

		struct msg_t
		{
			mk::win::hwnd_t m_hwnd;
			mk::win::uint_t m_msg;
			mk::win::wparam_t m_wparam;
			mk::win::lparam_t m_lparam;
			mk::win::dword_t m_time;
			mk::win::point_t m_point;
		};

		struct wm_create_t
		{
			void* m_context;
			mk::win::instance_t m_instance;
			mk::win::menu_t m_menu;
			mk::win::hwnd_t m_parent;
			int m_height;
			int m_width;
			int m_y;
			int m_x;
			mk::win::long_t m_style;
			mk::win::widechar_t const* m_name;
			mk::win::widechar_t const* m_class;
			mk::win::dword_t m_ex_style;
		};


	}
}


#endif
