#ifndef GAME_GAME_H_
#define GAME_GAME_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
#include "manager/drawing/Text.h"
#include "game/board/GameBoard.h"
#include "game/pieces/types/ChessPiece.h"

//Forward declarations
struct Event;

class Game {
public:
	int32_t init(const GameCfg cfg);
	void deinit();
	void draw();
	void handleEvent(const Event& event);

private:
	GameBoard _board;
	ChessPiece _piece;
};

#endif /* GAME_GAME_H_ */
