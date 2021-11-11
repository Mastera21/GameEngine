#ifndef DEFINES_CHESSDEFINES_H_
#define DEFINES_CHESSDEFINES_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers

//Forward declarations

namespace Defines{
enum PlayerId {
  WHITE_PLAYER_ID, BLACK_PLAYER_ID,

  PLAYERS_COUNT
};

enum Direction {
  UP_LEFT,
  UP,
  UP_RIGHT,
  RIGHT,
  DOWN_RIGHT,
  DOWN,
  DOWN_LEFT,
  LEFT,
  DIRECTION_COUNT
};
}

enum class TileType : uint8_t {
  MOVE, GUARD, TAKE
};

enum class PieceType : uint8_t {
  KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, UNKNOWN
};

#endif /* DEFINES_CHESSDEFINES_H_ */
