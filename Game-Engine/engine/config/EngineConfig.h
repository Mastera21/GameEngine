#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "manager/config/DrawMgrCfg.h"
#include "sdl/config/ImageContainerCfg.h"
#include "sdl/config/TextContainerCfg.h"
#include "game/config/GameCfg.h"
//Own components headers

struct EngineConfig {
	DrawMgrCfg drawMgrCfg;
	ImageContainerCfg imageContainerCfg;
	TextContainerCfg textContainerCfg;
	GameCfg gameCfg;
};


#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
