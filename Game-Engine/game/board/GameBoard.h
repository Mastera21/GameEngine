#ifndef GAME_BOARD_GAMEBOARD_H_
#define GAME_BOARD_GAMEBOARD_H_


//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
#include "manager/time/TimerClient.h"
#include "game/interfaces/GameBoardInterface.h"
//Forward declarations

class GameBoard : public GameBoardInterface, public TimerClient {
public:
	int32_t init(int32_t boardRsrcId, int32_t targetRsrcId, int32_t blinkTimerId);
	void draw();

private:
	Image _boardImg;
	Image _targetImg;
	int32_t _blinkTimerId;

	std::vector<TileData> _currMoveTiles;

	void onPieceGrabbed(const BoardPos& boardPos, const std::vector<TileData>& moveTiles) final;
	void onPieceUngrabbed() final;
	void onTimeout(int32_t timerId) final;
	bool isMoveAllowed(const BoardPos &pos) const final;
};

#endif /* GAME_BOARD_GAMEBOARD_H_ */
