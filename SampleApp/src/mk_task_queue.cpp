#include "mk_task_queue.hpp"

#include "mk_lock.hpp"


mk::task_queue_t::task_queue_t() :
	m_vec_1(),
	m_vec_2(),
	m_idx(0),
	m_lock()
{
}

mk::task_queue_t::~task_queue_t()
{
}

void mk::task_queue_t::add_task(mk::task_t const& task)
{
	{
		mk::lock_t<mk::critical_section_t> const lck(m_lock);
		m_vec_1.push_back(task);
	}
}

bool mk::task_queue_t::execute_task()
{
	if(m_idx < m_vec_2.size())
	{
		mk::task_t& task = m_vec_2[m_idx];
		++m_idx;
		task.m_task_prc(task.m_task_ctx);
		return true;
	}
	m_vec_2.clear();
	{
		mk::lock_t<mk::critical_section_t> const lck(m_lock);
		m_vec_2.swap(m_vec_1);
	}
	if(m_vec_2.is_empty())
	{
		return false;
	}
	m_idx = 0;
	bool const executed = execute_task();
	return executed;
}
