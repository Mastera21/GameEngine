#ifndef GAME_DEFINES_CHESSSTRUCTS_H_
#define GAME_DEFINES_CHESSSTRUCTS_H_
//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
//Other libraries headers

//Own components headers
#include "game/defines/ChessDefines.h"
#include "game/utils/BoardPos.h"
//Forward declarations

struct TileData {
  BoardPos boardPos;
  TileType tileType = TileType::MOVE;
};

using MoveDirection = std::vector<BoardPos>;

#endif /* GAME_DEFINES_CHESSSTRUCTS_H_ */
