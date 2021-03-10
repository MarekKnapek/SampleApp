#pragma once
#ifndef INCLUDE_GUARD_MK_CHECK_RET
#define INCLUDE_GUARD_MK_CHECK_RET


#define MK_CHECK_RET(X) do{ if(X){}else{ mk::report(__LINE__); return; } }while(false, false)
#define MK_CHECK_RET_F(X) do{ if(X){}else{ mk::report(__LINE__); return false; } }while(false, false)
#define MK_CHECK_CRASH(X) do{ if(X){}else{ mk::report(__LINE__); mk::crash(); } }while(false, false)


namespace mk
{
	void report(int const line);
	void crash();
}


#endif
