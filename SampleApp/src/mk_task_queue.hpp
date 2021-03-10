#pragma once
#ifndef INCLUDE_GUARD_MK_TASK_QUEUE
#define INCLUDE_GUARD_MK_TASK_QUEUE


#include "mk_vector.hpp"
#include "mk_critical_section.hpp"


namespace mk
{


	struct task_t
	{
		void(*m_task_prc)(void* const);
		void* m_task_ctx;
	};


	class task_queue_t
	{
	public:
		task_queue_t();
		~task_queue_t();
	public:
		void add_task(mk::task_t const& task);
		bool execute_task();
	private:
		mk::vector_t<mk::task_t> m_vec_1;
		mk::vector_t<mk::task_t> m_vec_2;
		mk::size_t m_idx;
		mk::critical_section_t m_lock;
	};

}


#endif
