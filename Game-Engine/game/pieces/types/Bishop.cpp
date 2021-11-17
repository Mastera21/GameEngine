#include "game/pieces/types/Bishop.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

std::vector<MoveDirection> Bishop::getBoardMoves() const {
	constexpr auto allowedDirs = 4;
	constexpr std::array<Defines::Direction, allowedDirs> bishopDirs {
		Defines::UP_LEFT, Defines::UP_RIGHT, Defines::DOWN_LEFT, Defines::DOWN_RIGHT
	};

	constexpr auto maxBishopMoves = 7;
	std::vector<MoveDirection> boardMoves(allowedDirs);

	BoardPos futurePos;
	for (int32_t dirIdx = 0; dirIdx < allowedDirs; ++dirIdx) {
		boardMoves[dirIdx].reserve(maxBishopMoves);
		futurePos = _boardPos;
		futurePos = BoardUtils::getAdjacentPos(bishopDirs[dirIdx], futurePos);
		while(BoardUtils::isInsideBoard(futurePos)){
			boardMoves[dirIdx].push_back(futurePos);
			futurePos = BoardUtils::getAdjacentPos(bishopDirs[dirIdx], futurePos);
		}
	}
	return boardMoves;
}

std::vector<TileData> Bishop::getMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const{
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
