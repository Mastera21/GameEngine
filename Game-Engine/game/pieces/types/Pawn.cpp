
#include "game/pieces/types/Pawn.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>
#include <unordered_map>
//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

std::vector<TileData> Pawn::getMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const {
	if(Defines::WHITE_PLAYER_ID == _playerId){
		return getWhiteMoveTiles(activePieces);
	}
	return getBlackMoveTiles(activePieces);
}

std::vector<TileData> Pawn::getWhiteMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const{
	const std::unordered_map<Defines::Direction, MoveDirection> boardMoves = getWhiteBoardMoves();
	std::vector<TileData> moveTile;
	moveTile.reserve(boardMoves.size());
	const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

	std::unordered_map<Defines::Direction, MoveDirection>::const_iterator it = boardMoves.find(Defines::UP);
	if(it != boardMoves.end()){
		for(const auto& pos : it->second){
			const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);

			if(TileType::MOVE != tileType){
				break;
			}

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

std::unordered_map<Defines::Direction, MoveDirection> Pawn::getWhiteBoardMoves() const{
	constexpr auto allowedCount = 3;
	std::unordered_map<Defines::Direction, MoveDirection> boardMoves(allowedCount);

	BoardPos futurePos;
	futurePos = BoardUtils::getAdjacentPos(Defines::UP_LEFT, _boardPos);
	if(BoardUtils::isInsideBoard(futurePos)){
		boardMoves[Defines::UP_LEFT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::UP_RIGHT, _boardPos);
	if(BoardUtils::isInsideBoard(futurePos)){
		boardMoves[Defines::UP_RIGHT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::UP, _boardPos);
	boardMoves[Defines::UP].emplace_back(futurePos);

	if(Defines::WHITE_PLAYER_START_PAWN_ROW == _boardPos.row){
		futurePos = BoardUtils::getAdjacentPos(Defines::UP, futurePos);
		boardMoves[Defines::UP].emplace_back(futurePos);
	}

	return boardMoves;
}

std::vector<TileData> Pawn::getBlackMoveTiles(const std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const{
	const std::unordered_map<Defines::Direction, MoveDirection> boardMoves = getBlackBoardMoves();
	std::vector<TileData> moveTile;
	moveTile.reserve(boardMoves.size());
	const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

	std::unordered_map<Defines::Direction, MoveDirection>::const_iterator it = boardMoves.find(Defines::DOWN);
	if(it != boardMoves.end()){
		for(const auto& pos : it->second){
			const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);

			if(TileType::MOVE != tileType){
				break;
			}

			TileData tileData;
			tileData.boardPos = pos;
			tileData.tileType = tileType;

			moveTile.push_back(tileData);
		}
	}

	//Take piece
	constexpr auto diagonalMovesCount = 2;
	const std::array<Defines::Direction, diagonalMovesCount> diagonalMoves {
			Defines::DOWN_LEFT, Defines::DOWN_RIGHT
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

std::unordered_map<Defines::Direction, MoveDirection> Pawn::getBlackBoardMoves() const{
	constexpr auto allowedCount = 3;
	std::unordered_map<Defines::Direction, MoveDirection> boardMoves(allowedCount);

	BoardPos futurePos;
	futurePos = BoardUtils::getAdjacentPos(Defines::DOWN_LEFT, _boardPos);
	if(BoardUtils::isInsideBoard(futurePos)){
		boardMoves[Defines::DOWN_LEFT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::DOWN_RIGHT, _boardPos);
	if(BoardUtils::isInsideBoard(futurePos)){
		boardMoves[Defines::DOWN_RIGHT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::DOWN, _boardPos);
	boardMoves[Defines::DOWN].emplace_back(futurePos);

	if(Defines::BLACK_PLAYER_START_PAWN_ROW == _boardPos.row){
		futurePos = BoardUtils::getAdjacentPos(Defines::DOWN, futurePos);
		boardMoves[Defines::DOWN].emplace_back(futurePos);
	}

	return boardMoves;
}
