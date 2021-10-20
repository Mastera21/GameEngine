#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "sdl/config/MonitorWindowCfg.h"
#include "game/Game.h"
//Own components headers

struct EngineConfig {
	MonitorWindowCofg windowCfg;
	GameCfg gameCfg;
};


#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
