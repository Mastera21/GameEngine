#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_


//C system headers

//C++ system headers
#include <cstdint>
#include <unordered_map>

//Other libraries headers

//Own components headers

struct GameCfg{
	int32_t chessBoardRsrcId;
	int32_t whitePiecesRsrcId;
	int32_t blackPiecesRsrcId;
	int32_t targetRsrcId;
	int32_t blinkTargetId;
};

#endif /* GAME_CONFIG_GAMECFG_H_ */
