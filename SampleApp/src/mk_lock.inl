#include "mk_lock.hpp"


template<typename t>
mk::lock_t<t>::lock_t(t& lock) :
	m_lock(lock)
{
	m_lock.lock();
}

template<typename t>
mk::lock_t<t>::~lock_t()
{
	m_lock.unlock();
}
