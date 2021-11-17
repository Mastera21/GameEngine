#ifndef GAME_PIECES_TYPES_KNIGHT_H_
#define GAME_PIECES_TYPES_KNIGHT_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
#include <unordered_map>
//Other libraries headers
#include "game/pieces/types/ChessPiece.h"
//Own components headers

//Forward declarations

class Knight : public ChessPiece{
public:
	std::vector<TileData> getMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const final;
private:
	std::vector<TileData> getWhiteMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const;
	std::vector<TileData> getBlackMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const;

	std::unordered_map<Defines::Direction, MoveDirection> getWhiteBoardMoves() const;
	std::unordered_map<Defines::Direction, MoveDirection> getBlackBoardMoves() const;

	void upDir(BoardPos& futurePos, std::unordered_map<Defines::Direction, MoveDirection>& boardMoves) const;
	void rightDir(BoardPos futurePos, std::unordered_map<Defines::Direction, MoveDirection> boardMoves) const;
};

#endif /* GAME_PIECES_TYPES_KNIGHT_H_ */
