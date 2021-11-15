#ifndef GAME_PANELS_CONFIG_PIECEPROMOTIONPANELCFG_H_
#define GAME_PANELS_CONFIG_PIECEPROMOTIONPANELCFG_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers

//Forward declarations
class GameInterface;

struct PiecePromotionPanelCfg{
	GameInterface* gameInterface = nullptr;
	int32_t whitePiecesRsrcId = 0;
	int32_t blackPiecesRsrcId = 0;
	int32_t buttonBgrRsrcId = 0;
	int32_t gameBoardWidth = 0;
	int32_t gameBoatdHeight = 0;
	int32_t buttonBgrWidth = 0;
	int32_t buttonBgrHeight = 0;
	int32_t buttonWidth = 0;
	int32_t buttonHeight = 0;
};
#endif /* GAME_PANELS_CONFIG_PIECEPROMOTIONPANELCFG_H_ */
