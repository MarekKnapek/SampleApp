#include "mk_check_ret.hpp"

#include "mk_macros.hpp"
#include "mk_win_user.hpp"
#include "mk_win_kernel.hpp"


void mk::report(int const line)
{
	int n = line;
	char buffer[12];
	char* ptr = buffer;

	if(n < 0)
	{
		ptr[0] = '-';
		++ptr;
		n = -n;
	}

	int places;
	if(n < 10)
	{
		places = 1;
	}
	else if(n < 100)
	{
		places = 2;
	}
	else if(n < 1000)
	{
		places = 3;
	}
	else if(n < 10000)
	{
		places = 4;
	}
	else if(n < 100000)
	{
		places = 5;
	}
	else if(n < 1000000)
	{
		places = 6;
	}
	else if(n < 10000000)
	{
		places = 7;
	}
	else if(n < 100000000)
	{
		places = 8;
	}
	else if(n < 1000000000)
	{
		places = 9;
	}
	else
	{
		places = 10;
	}

	for(int i = 0; i != places - 1; ++i)
	{
		int const digit = n % 10;
		n = n / 10;
		char const ch = static_cast<char>('0' + digit);
		ptr[places - 1 - i] = ch;
	}
	char const ch = static_cast<char>('0' + n);
	ptr[0] = ch;

	ptr[places] = '\0';

	mk::win::hwnd_t const hwnd = {mk::win::s_null};
	char const* const text = buffer;
	char const* const caption = "Surprise, Madafaka!";
	mk::win::mb_e::mb_e const type = static_cast<mk::win::mb_e::mb_e>(mk::win::mb_e::ok | mk::win::mb_e::iconerror);
	int const msg = mk::win::user::message_box(hwnd, text, caption, type); (void)msg;
}

void mk::crash()
{
	mk::win::kernel::debug_break();

	mk::win::uint_t const exit_code = {1};
	bool const terminated = mk::win::kernel::terminate_process(mk::win::kernel::get_current_process(), exit_code); (void)terminated;

	int volatile* volatile ptr = MK_NULL;
	*ptr = 0;
}
