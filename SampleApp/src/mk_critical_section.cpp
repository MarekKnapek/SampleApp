#include "mk_critical_section.hpp"

#include "mk_win_kernel.hpp"


mk::critical_section_t::critical_section_t() :
	m_critical_section()
{
	mk::win::kernel::initialize_critical_section(m_critical_section);
}

mk::critical_section_t::~critical_section_t()
{
	mk::win::kernel::delete_critical_section(m_critical_section);
}

void mk::critical_section_t::lock()
{
	mk::win::kernel::enter_critical_section(m_critical_section);
}

bool mk::critical_section_t::try_lock()
{
	bool const locked = mk::win::kernel::try_enter_critical_section(m_critical_section);
	return locked;
}

void mk::critical_section_t::unlock()
{
	mk::win::kernel::leave_critical_section(m_critical_section);
}
