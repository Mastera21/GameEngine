#ifndef GAME_PIECES_TYPES_PAWN_H_
#define GAME_PIECES_TYPES_PAWN_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
//Other libraries headers
#include "game/pieces/types/ChessPiece.h"
//Own components headers

//Forward declarations

class Pawn : public ChessPiece{
public:
	std::vector<TileData> getMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const final;
private:
	std::vector<MoveDirection> getBoardMoves() const;
};

#endif /* GAME_PIECES_TYPES_PAWN_H_ */
