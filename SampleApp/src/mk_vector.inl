#include "mk_vector.hpp"

#include "mk_assert.hpp"
#include "mk_cstdlib.hpp"
#include "mk_check_ret.hpp"

#include <new>


template<typename t>
mk::vector_t<t>::vector_t() :
	m_array(MK_NULL),
	m_size(0),
	m_capacity(0)
{
}

template<typename t>
mk::vector_t<t>::vector_t(mk::vector_t<t>& other) :
	mk::vector_t()
{
	swap(other);
}

template<typename t>
mk::vector_t<t>& mk::vector_t<t>::operator=(mk::vector_t<t>& other)
{
	MK_ASSERT(this != &other);
	swap(other);
	return *this;
}

template<typename t>
void mk::vector_t<t>::swap(mk::vector_t<t>& other)
{
	MK_ASSERT(this != &other);
	mk::swap_t<t*>()(m_array, other.m_array);
	mk::swap_t<mk::size_t>()(m_size, other.m_size);
	mk::swap_t<mk::size_t>()(m_capacity, other.m_capacity);
}

template<typename t>
mk::vector_t<t>::~vector_t()
{
	for(mk::size_t i = 0; i != m_size; ++i)
	{
		mk::size_t const idx = m_size - 1 - i;
		t& val = m_array[idx];
		val.~t();
		(void)val;
	}
	mk::deallocate(m_array);
}


template<typename t>
mk::size_t mk::vector_t<t>::size() const
{
	return m_size;
}

template<typename t>
mk::size_t mk::vector_t<t>::capacity() const
{
	return m_capacity;
}

template<typename t>
bool mk::vector_t<t>::is_empty() const
{
	return m_size == 0;
}

template<typename t>
bool mk::vector_t<t>::is_full() const
{
	return m_size == m_capacity;
}

template<typename t>
mk::size_t mk::vector_t<t>::space() const
{
	return m_capacity - m_size;
}

template<typename t>
t const& mk::vector_t<t>::operator[](mk::size_t const idx) const
{
	MK_ASSERT(idx < m_size);
	return m_array[idx];
}

template<typename t>
t const* mk::vector_t<t>::begin() const
{
	return m_array + 0;
}

template<typename t>
t const* mk::vector_t<t>::cbegin() const
{
	return m_array + 0;
}

template<typename t>
t const* mk::vector_t<t>::end() const
{
	return m_array + m_size;
}

template<typename t>
t const* mk::vector_t<t>::cend() const
{
	return m_array + m_size;
}

template<typename t>
t const& mk::vector_t<t>::front() const
{
	MK_ASSERT(m_size != 0);
	return m_array[0];
}

template<typename t>
t const& mk::vector_t<t>::back() const
{
	MK_ASSERT(m_size != 0);
	return m_array[m_size - 1];
}


template<typename t>
t& mk::vector_t<t>::operator[](mk::size_t const idx)
{
	MK_ASSERT(idx < m_size);
	return m_array[idx];
}

template<typename t>
t* mk::vector_t<t>::begin()
{
	return m_array + 0;
}

template<typename t>
t* mk::vector_t<t>::end()
{
	return m_array + m_size;
}

template<typename t>
t& mk::vector_t<t>::front()
{
	MK_ASSERT(m_size != 0);
	return m_array[0];
}

template<typename t>
t& mk::vector_t<t>::back()
{
	MK_ASSERT(m_size != 0);
	return m_array[m_size - 1];
}

template<typename t>
void mk::vector_t<t>::reserve(mk::size_t const size)
{
	if(size <= m_capacity)
	{
		return;
	}
	mk::size_t const double_capacity = m_capacity * 2;
	mk::size_t const new_capacity = double_capacity < size ? size : double_capacity;
	t* const new_array = static_cast<t*>(mk::allocate(new_capacity * sizeof(t)));
	MK_CHECK_CRASH(new_array);
	for(mk::size_t i = 0; i != m_size; ++i)
	{
		t& val = m_array[i];
		new(new_array + i)t(val);
		val.~t();
	}
	mk::deallocate(m_array);
	m_array = new_array;
	m_capacity = new_capacity;
}

template<typename t>
void mk::vector_t<t>::resize(mk::size_t const size)
{
	if(size < m_size)
	{
		mk::size_t const diff = m_size - size;
		for(mk::size_t i = 0; i != diff; ++i)
		{
			mk::size_t const idx = m_size - 1 - i;
			t& val = m_array[idx];
			val.~t();
		}
		m_size = m_size - diff;
	}
	else if(size > m_size)
	{
		reserve(size);
		mk::size_t const diff = size - m_size;
		for(mk::size_t i = 0; i != diff; ++i)
		{
			new(m_array + m_size + i)t();
		}
		m_size = m_size + diff;
	}
}

template<typename t>
t& mk::vector_t<t>::push_back(t const& val)
{
	// Beware, will not work with vec.push_back(vec[42]); but we don't care.
	reserve(m_size + 1);
	new(m_array + m_size)t(val);
	++m_size;
	return m_array[m_size - 1];
}

template<typename t>
void mk::vector_t<t>::pop_back()
{
	MK_ASSERT(m_size >= 1);
	t& val = m_array[m_size - 1];
	val.~t();
	--m_size;
}

template<typename t>
void mk::vector_t<t>::clear()
{
	for(mk::size_t i = 0; i != m_size; ++i)
	{
		mk::size_t const idx = m_size - 1 - i;
		t& val = m_array[idx];
		val.~t();
		(void)val;
	}
	m_size = 0;
}
