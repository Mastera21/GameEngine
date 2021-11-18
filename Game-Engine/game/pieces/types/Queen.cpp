#include "game/pieces/types/Queen.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>
#include <unordered_map>
//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

std::vector<MoveDirection> Queen::getBoardMoves() const{
	constexpr auto allowedDirs = 8;
	constexpr std::array<Defines::Direction, allowedDirs> queenDirs{
		Defines::UP, Defines::DOWN, Defines::LEFT, Defines::RIGHT,
		Defines::UP_LEFT, Defines::UP_RIGHT, Defines::DOWN_LEFT, Defines::DOWN_RIGHT
	};

	constexpr auto maxQueenMoves = 8;
	std::vector<MoveDirection>boardMoves(maxQueenMoves);

	BoardPos futurePos;
	for (int32_t dirIdx = 0; dirIdx < allowedDirs; ++dirIdx) {
		boardMoves[dirIdx].reserve(maxQueenMoves);
		futurePos = _boardPos;
		futurePos = BoardUtils::getAdjacentPos(queenDirs[dirIdx], futurePos);
		while(BoardUtils::isInsideBoard(futurePos)){
			boardMoves[dirIdx].push_back(futurePos);
			futurePos = BoardUtils::getAdjacentPos(queenDirs[dirIdx], futurePos);
		}
	}
	return boardMoves;
}

std::vector<TileData> Queen::getMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const {
	std::vector<TileData> moveTiles;
		const std::vector<MoveDirection> boardMoves = getBoardMoves();
		const auto opponentId = BoardUtils::getOpponentId(_playerId);

	for (const auto& moveDir : boardMoves) {
		if (moveDir.empty()) {
			continue;
		}

		  for(const auto& boardPos : moveDir){
		  	const TileType tileType = BoardUtils::getTileType(boardPos, activePieces[_playerId], activePieces[opponentId]);

		  	TileData tileData;
		  	tileData.boardPos = boardPos;
		  	tileData.tileType = tileType;
		  	moveTiles.push_back(tileData);
		  	if(TileType::MOVE != tileType){
		  		break;
		  	}
		 }
	}
	return moveTiles;
}
