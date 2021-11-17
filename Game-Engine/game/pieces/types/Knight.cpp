#include "game/pieces/types/Knight.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

std::vector<TileData> Knight::getMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const {
	if(Defines::WHITE_PLAYER_ID == _playerId){
		return getWhiteMoveTiles(activePieces);
	}
	return getBlackMoveTiles(activePieces);
}

std::vector<TileData> Knight::getWhiteMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const{
	const std::unordered_map<Defines::Direction, MoveDirection> boardMoves = getWhiteBoardMoves();
	std::vector<TileData> moveTile;
	moveTile.reserve(boardMoves.size());
	const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

	std::unordered_map<Defines::Direction, MoveDirection>::const_iterator it = boardMoves.find(Defines::UP);
	if(it != boardMoves.end()){
		for(const auto& pos : it->second){
			const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);

			TileData tileData;
			tileData.boardPos = pos;
			tileData.tileType = tileType;

			moveTile.push_back(tileData);
		}
	}

	//Take piece
	constexpr auto diagonalMovesCount = 2;
	const std::array<Defines::Direction, diagonalMovesCount> diagonalMoves {
		Defines::UP_LEFT, Defines::UP_RIGHT
	};

	for(const Defines::Direction move : diagonalMoves){
		it = boardMoves.find(move);
		if(it != boardMoves.end()){
			for(const auto& pos : it->second){
				const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
				if(TileType::MOVE != tileType){
					TileData tileData;
					tileData.boardPos = pos;
					tileData.tileType = tileType;

					moveTile.push_back(tileData);
				}
			}
		}
	}
	return moveTile;
}

std::unordered_map<Defines::Direction, MoveDirection> Knight::getWhiteBoardMoves() const{
	constexpr auto allowedCount = 3;
	std::unordered_map<Defines::Direction, MoveDirection> boardMoves(allowedCount);

	BoardPos futurePos;
	futurePos = BoardUtils::getAdjacentPos(Defines::UP, BoardPos(_boardPos.row - 1 , _boardPos.col - 1));
	if(BoardUtils::isInsideBoard(futurePos)){
		boardMoves[Defines::UP].emplace_back(futurePos);
	}
	futurePos = BoardUtils::getAdjacentPos(Defines::UP, BoardPos(_boardPos.row - 1, _boardPos.col + 1));
	if(BoardUtils::isInsideBoard(futurePos)){
		boardMoves[Defines::UP].emplace_back(futurePos);
	}


	//TODO



	return boardMoves;
}

std::vector<TileData> Knight::getBlackMoveTiles([[maybe_unused]]const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const{
	const std::unordered_map<Defines::Direction, MoveDirection> boardMoves = getBlackBoardMoves();
	std::vector<TileData> moveTile;
	moveTile.reserve(boardMoves.size());

	return moveTile;
}

std::unordered_map<Defines::Direction, MoveDirection> Knight::getBlackBoardMoves() const{
	constexpr auto allowedCount = 3;
	std::unordered_map<Defines::Direction, MoveDirection> boardMoves(allowedCount);

	return boardMoves;
}
