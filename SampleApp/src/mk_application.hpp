#pragma once
#ifndef INCLUDE_GUARD_MK_APPLICATION
#define INCLUDE_GUARD_MK_APPLICATION


#include "mk_main_window.hpp"
#include "mk_windows.hpp"
#include "mk_task_queue.hpp"


namespace mk
{

	class application_t
	{
	public:
		application_t(mk::win::instance_t const instance, int const cmd_show);
		~application_t();
	public:
		mk::win::instance_t get_instance() const;
	public:
		int run();
		void add_task(mk::task_t const& task);
	private:
		int run_message_loop();
		bool on_idle();
	private:
		mk::win::instance_t m_instance;
		int m_cmd_show;
		mk::win::dword_t m_thread_id;
		mk::task_queue_t m_idle_tasks;
		mk::main_window_t* m_main_window;
	};

}


#endif
