#ifndef MANAGER_INCLUDE_MANAGER_CONFIG_DRAWMGRCFG_H_
#define MANAGER_INCLUDE_MANAGER_CONFIG_DRAWMGRCFG_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "sdl/config/MonitorWindowCfg.h"

//Own components headers

struct DrawMgrCfg {
	MonitorWindowCofg windowCfg;
	int64_t maxFrameRate;
};

#endif /* MANAGER_INCLUDE_MANAGER_CONFIG_DRAWMGRCFG_H_ */
