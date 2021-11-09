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
#include "manager/time/TimerClient.h"
//Forward declarations

class GameBoard : public GameBoardInterface, public TimerClient {
public:
	int32_t init(int32_t boardRsrcId, int32_t targetRsrcId, int32_t blinkTimerId);
	void draw();

private:
	Image _boardImg;
	Image _targetImg;

	int32_t _blinkTimerId;

	void onPieceGrabbed(const BoardPos& boardPos) final;
	void onPieceUngrabbed() final;
	void onTimeout(int32_t timerId) final;
};

#endif /* GAME_BOARD_GAMEBOARD_H_ */
