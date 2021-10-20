#ifndef ENGINE_ENGINECONFIGLOADER_H_
#define ENGINE_ENGINECONFIGLOADER_H_

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "engine/config/EngineConfig.h"

//Forward declarations

class EngineConfigLoader {
public:
	EngineConfigLoader() = delete;
	virtual ~EngineConfigLoader() = default;

	static EngineConfig loadConfig();

};

#endif /* ENGINE_ENGINECONFIGLOADER_H_ */
