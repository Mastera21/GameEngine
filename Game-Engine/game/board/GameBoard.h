#ifndef GAME_BOARD_GAMEBOARD_H_
#define GAME_BOARD_GAMEBOARD_H_


//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
//Forward declarations

class GameBoard {
public:
	int32_t init(int32_t boardRsrcId);
	void draw();

private:
	Image _boardImg;
};

#endif /* GAME_BOARD_GAMEBOARD_H_ */
