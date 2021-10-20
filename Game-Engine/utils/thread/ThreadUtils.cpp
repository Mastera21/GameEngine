#include "ThreadUtils.h"

#include <thread>


#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#endif

void Threading::sleepFor(int64_t microseconds) {
	if(0 > microseconds){
		return;
	}
#ifdef _WIN32
  const DWORD milliseconds = static_cast<DWORD>(microseconds / 1000);
  Sleep(milliseconds); //sleep uses milliseconds
#else
  std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
#endif
}
