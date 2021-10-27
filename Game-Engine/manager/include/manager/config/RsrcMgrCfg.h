#ifndef MANAGER_INCLUDE_MANAGER_CONFIG_RSRCMGRCFG_H_
#define MANAGER_INCLUDE_MANAGER_CONFIG_RSRCMGRCFG_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "sdl/containers/ImageContainer.h"
#include "sdl/containers/TextContainer.h"
//Own components headers

struct RsrcMgrCfg {
	ImageContainerCfg imageContainerCfg;
	TextContainerCfg textContainerCfg;
};


#endif /* MANAGER_INCLUDE_MANAGER_CONFIG_RSRCMGRCFG_H_ */
