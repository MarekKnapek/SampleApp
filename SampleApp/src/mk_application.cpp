#include "mk_application.hpp"

#include "mk_win_user.hpp"
#include "mk_win_kernel.hpp"
#include "mk_window_class_registrator.hpp"


mk::application_t::application_t(mk::win::instance_t const instance, int const cmd_show) :
	m_instance(instance),
	m_cmd_show(cmd_show),
	m_thread_id(),
	m_idle_tasks(),
	m_main_window()
{
}

mk::application_t::~application_t()
{
}

mk::win::instance_t mk::application_t::get_instance() const
{
	return m_instance;
}

int mk::application_t::run()
{
	m_thread_id = mk::win::kernel::get_current_thread_id();
	mk::window_class_registrator_t<mk::main_window_t> const main_window_class;
	mk::main_window_t main_window;
	m_main_window = &main_window;
	mk::win::user::show_window(main_window.get_hwnd(), m_cmd_show);
	int const exit_code = run_message_loop();
	return exit_code;
}

void mk::application_t::add_task(mk::task_t const& task)
{
	m_idle_tasks.add_task(task);
	mk::win::wparam_t const wparam = {0};
	mk::win::lparam_t const lparam = {0};
	bool const posted = mk::win::user::post_thread_message(m_thread_id, mk::win::wm_e::null, wparam, lparam); (void)posted;
}

int mk::application_t::run_message_loop()
{
	bool peeked;
	mk::win::msg_t msg;
	mk::win::hwnd_t const null_hwnd = {mk::win::s_null};
	mk::win::uint_t const filter_min = {0};
	mk::win::uint_t const filter_max = {0};
	for(;;)
	{
		peeked = mk::win::user::peek_message(msg, null_hwnd, filter_min, filter_max, mk::win::peek_message_e::remove);
		if(peeked)
		{
			if(msg.m_msg.m_value == mk::win::wm_e::quit)
			{
				break;
			}
			translate:
			bool const translated = mk::win::user::translate_message(msg); (void)translated;
			mk::win::lresult_t const dispatched = mk::win::user::dispatch_message(msg); (void)dispatched;
		}
		else
		{
			bool const idled = on_idle();
			if(idled)
			{
				continue;
			}
			else
			{
				mk::win::bool_t const got = mk::win::user::get_message(msg, null_hwnd, filter_min, filter_max);
				if(got.m_value == 0)
				{
					break;
				}
				goto translate;
			}
		}
	}
	while(on_idle())
	{
	};
	int const exit_code = static_cast<int>(msg.m_wparam.m_value);
	return exit_code;
}

bool mk::application_t::on_idle()
{
	bool const executed = m_idle_tasks.execute_task();
	return executed;
}
