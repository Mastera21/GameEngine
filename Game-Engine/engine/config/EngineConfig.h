#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "manager/config/ManagerHandlerCfg.h"
#include "game/config/GameCfg.h"
//Own components headers

struct EngineConfig {
	ManagerHandlerCfg managerHandlerCfg;
	GameCfg gameCfg;
};


#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
