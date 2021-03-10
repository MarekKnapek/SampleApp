#include "mk_move.hpp"


template<typename t>
mk::move_t<t> mk::move(t& value)
{
	mk::move_t<t> m;
	m.m_value = &value;
	return m;
}
