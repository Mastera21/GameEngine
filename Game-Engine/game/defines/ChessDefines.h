#ifndef DEFINES_CHESSDEFINES_H_
#define DEFINES_CHESSDEFINES_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers

//Forward declarations

enum PlayerId {
  WHITE_PLAYER_ID, BLACK_PLAYER_ID,

  PLAYERS_COUNT
};

enum class PieceType : uint8_t {
  KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, UNKNOWN
};

#endif /* DEFINES_CHESSDEFINES_H_ */
