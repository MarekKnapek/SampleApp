#pragma once
#ifndef INCLUDE_GUARD_MK_DELAYED_CONSTRUCTOR
#define INCLUDE_GUARD_MK_DELAYED_CONSTRUCTOR


namespace mk
{


#pragma pack(push)
#pragma pack(8)

	template<typename t>
	class delayed_constructor_t
	{
	public:
		delayed_constructor_t();
		~delayed_constructor_t();
	public:
		void construct();
		t const& get() const;
		t& get();
	private:
		unsigned char m_buffer[sizeof(t)];
	};

#pragma pack(pop)


}


#include "mk_delayed_constructor.inl"


#endif
