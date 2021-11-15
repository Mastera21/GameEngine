#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <unordered_map>
//Other libraries headers

//Own components headers
#include "game/panels/config/PiecePromotionPanelCfg.h"

struct GameCfg{
	PiecePromotionPanelCfg piecePromotionPanelCfg;
	int32_t chessBoardRsrcId;
	int32_t whitePiecesRsrcId;
	int32_t blackPiecesRsrcId;
	int32_t targetRsrcId;
	int32_t blinkTargetId;
	int32_t fpsId;
	int32_t unfinishedPieceFontId;
	int32_t moveTailId;
};
#endif /* GAME_CONFIG_GAMECFG_H_ */
