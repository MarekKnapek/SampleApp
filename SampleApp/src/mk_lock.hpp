#pragma once
#ifndef INCLUDE_GUARD_MK_LOCK
#define INCLUDE_GUARD_MK_LOCK


namespace mk
{

	template<typename t>
	class lock_t
	{
	public:
		lock_t(t& lock);
		~lock_t();
	private:
		mk::lock_t<t>& operator=(mk::lock_t<t> const&);
	private:
		t& m_lock;
	};

}


#include "mk_lock.inl"


#endif
