#include "game/utils/BoardUtils.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "utils/drawing/Rectangle.h"

namespace{
constexpr auto BOARD_SIZE = 8;

constexpr auto FIRST_TILE_X_POS = 58;
constexpr auto FIRST_TILE_Y_POS = 60;

constexpr auto TILE_SIZE = 98;
}

BoardPos BoardUtils::getBoardPos(const Point &absPos){
	return {(absPos.y - FIRST_TILE_Y_POS) / TILE_SIZE, (absPos.x - FIRST_TILE_X_POS) / TILE_SIZE };
}

Point BoardUtils::getAbsPos(const BoardPos& boardPos){
	return {(boardPos.col * TILE_SIZE) + FIRST_TILE_X_POS, (boardPos.row * TILE_SIZE) + FIRST_TILE_Y_POS };
}

bool BoardUtils::isInsideBoard(const BoardPos& boardPos){
	const Rectangle bound {0, 0, BOARD_SIZE, BOARD_SIZE};
	const Point pos {boardPos.col, boardPos.row};
	return bound.isPointInside(pos);
}

bool BoardUtils::isInsideBoard(const Point& absPos){
	const Rectangle bound {FIRST_TILE_X_POS, FIRST_TILE_Y_POS, BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE};
	return bound.isPointInside(absPos);
}
