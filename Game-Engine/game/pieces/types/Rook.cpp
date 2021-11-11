#include "game/pieces/types/Rook.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

std::vector<MoveDirection> Rook::getBoardMoves() const {
	constexpr auto allowedDirs = 4;
	constexpr std::array<Defines::Direction, allowedDirs> rookDirs { Defines::UP,
		Defines::RIGHT, Defines::DOWN, Defines::LEFT };

	constexpr auto maxRootMoves = 7;
	std::vector<MoveDirection> boardMoves(allowedDirs);

	BoardPos futurePos;
	for (int32_t dirIdx = 0; dirIdx < allowedDirs; ++dirIdx) {
		boardMoves[dirIdx].reserve(maxRootMoves);
		futurePos = _boardPos;
		futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
		while(BoardUtils::isInsideBoard(futurePos)){
			boardMoves[dirIdx].push_back(futurePos);
			futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
		}
	}
	return boardMoves;
}

std::vector<TileData> Rook::getMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const{
	std::vector<TileData> moveTiles;

	const std::vector<MoveDirection> boardMoves = getBoardMoves();

	  //...

	for (const auto& moveDir : boardMoves) {
	  if (moveDir.empty()) {
	    continue;
	  }
	  	  //TODO
	    //…
	}
	return moveTiles;
}
