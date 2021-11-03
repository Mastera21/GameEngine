#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_


//C system headers

//C++ system headers
#include <cstdint>
#include <unordered_map>

//Other libraries headers

//Own components headers

struct GameCfg{
	int32_t wheelId;
	int32_t runningGrilId;
	int32_t textFontId;

	int32_t startButtonRsrcId;
	int32_t stopButtonRsrcId;

};

#endif /* GAME_CONFIG_GAMECFG_H_ */
