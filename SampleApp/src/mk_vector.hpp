#pragma once
#ifndef INCLUDE_GUARD_MK_VECTOR
#define INCLUDE_GUARD_MK_VECTOR


#include "mk_types.hpp"
#include "mk_utility.hpp"


namespace mk
{

	template<typename t>
	class vector_t
	{
	public:
		vector_t();
		vector_t(mk::vector_t<t>& other);
		mk::vector_t<t>& operator=(mk::vector_t<t>& other);
		void swap(mk::vector_t<t>& other);
		~vector_t();
	public:
		mk::size_t size() const;
		mk::size_t capacity() const;
		bool is_empty() const;
		bool is_full() const;
		mk::size_t space() const;
		t const& operator[](mk::size_t const idx) const;
		t const* begin() const;
		t const* cbegin() const;
		t const* end() const;
		t const* cend() const;
		t const& front() const;
		t const& back() const;
	public:
		t& operator[](mk::size_t const idx);
		t* begin();
		t* end();
		t& front();
		t& back();
		void reserve(mk::size_t const size);
		void resize(mk::size_t const size);
		t& push_back(t const& val);
		void pop_back();
		void clear();
	private:
		t* m_array;
		mk::size_t m_size;
		mk::size_t m_capacity;
	};

}


#include "mk_vector.inl"


#endif
