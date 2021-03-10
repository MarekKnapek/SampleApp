#include "mk_utility.hpp"


template<typename t>
void mk::swap_t<t>::operator()(t& a, t& b) const
{
	t const tmp = a;
	a = b;
	b = tmp;
}
