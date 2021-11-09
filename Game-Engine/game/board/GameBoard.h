#ifndef GAME_BOARD_GAMEBOARD_H_
#define GAME_BOARD_GAMEBOARD_H_


//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
#include "game/proxies/GameBoardInterface.h"
//Forward declarations

class GameBoard : public GameBoardInterface {
public:
	int32_t init(int32_t boardRsrcId, int32_t targetRsrcId);
	void draw();

private:
	Image _boardImg;
	Image _targetImg;

	void onPieceGrabbed(const BoardPos& boardPos) final;
	void onPieceUngrabbed() final;
};

#endif /* GAME_BOARD_GAMEBOARD_H_ */
