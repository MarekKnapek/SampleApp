#include "mk_delayed_constructor.hpp"


#include "mk_assert.hpp"

#include <new>


template<typename t>
mk::delayed_constructor_t<t>::delayed_constructor_t()
{
	MK_ASSERT(reinterpret_cast<mk::size_t>(this) % 8 == 0);
}

template<typename t>
mk::delayed_constructor_t<t>::~delayed_constructor_t()
{
	t& val = *static_cast<t*>(static_cast<void*>(m_buffer));
	val.~t();
}

template<typename t>
void mk::delayed_constructor_t<t>::construct()
{
	new(static_cast<void*>(&m_buffer))t;
}

template<typename t>
t const& mk::delayed_constructor_t<t>::get() const
{
	t const& val = *static_cast<t const*>(static_cast<void const*>(m_buffer));
	return val;
}

template<typename t>
t& mk::delayed_constructor_t<t>::get()
{
	t& val = *static_cast<t*>(static_cast<void*>(m_buffer));
	return val;
}
