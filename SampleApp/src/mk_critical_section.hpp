#pragma once
#ifndef INCLUDE_GUARD_MK_CRITICAL_SECTION
#define INCLUDE_GUARD_MK_CRITICAL_SECTION


#include "mk_windows.hpp"


namespace mk
{

	class critical_section_t
	{
	public:
		critical_section_t();
		~critical_section_t();
		void lock();
		bool try_lock();
		void unlock();
	private:
		mk::win::critical_section_t m_critical_section;
	};

}


#endif
