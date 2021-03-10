#include "mk_main.hpp"

#include "mk_application.hpp"
#include "mk_assert.hpp"


namespace mk
{
	namespace detail
	{

		mk::application_t* g_application;

	}
}


int mk::win_main(mk::win::instance_t const instance, int const cmd_show)
{
	MK_ASSERT(mk::detail::g_application == MK_NULL);
	mk::application_t application(instance, cmd_show);
	mk::detail::g_application = &application;
	int const exit_code = application.run();
	MK_ASSERT((mk::detail::g_application = MK_NULL, true));
	return exit_code;
}

mk::win::instance_t mk::get_instance()
{
	MK_ASSERT(mk::detail::g_application != MK_NULL);
	mk::win::instance_t const instance = mk::detail::g_application->get_instance();
	return instance;
}
