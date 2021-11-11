#include "game/utils/BoardUtils.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "utils/drawing/Rectangle.h"

namespace{
constexpr auto BOARD_SIZE = 8;

constexpr auto FIRST_TILE_X_POS = 58;
constexpr auto FIRST_TILE_Y_POS = 60;

constexpr auto TILE_SIZE = 98;
}

BoardPos BoardUtils::getBoardPos(const Point &absPos){
	return {(absPos.y - FIRST_TILE_Y_POS) / TILE_SIZE, (absPos.x - FIRST_TILE_X_POS) / TILE_SIZE };
}

Point BoardUtils::getAbsPos(const BoardPos& boardPos){
	return {(boardPos.col * TILE_SIZE) + FIRST_TILE_X_POS, (boardPos.row * TILE_SIZE) + FIRST_TILE_Y_POS };
}

bool BoardUtils::isInsideBoard(const BoardPos& boardPos){
	const Rectangle bound {0, 0, BOARD_SIZE, BOARD_SIZE};
	const Point pos {boardPos.col, boardPos.row};
	return bound.isPointInside(pos);
}

bool BoardUtils::isInsideBoard(const Point& absPos){
	const Rectangle bound {FIRST_TILE_X_POS, FIRST_TILE_Y_POS, BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE};
	return bound.isPointInside(absPos);
}

int32_t BoardUtils::getOpponentId(int32_t activePlayerId){
	if(Defines::WHITE_PLAYER_ID == activePlayerId){
		return Defines::BLACK_PLAYER_ID;
	}
	return Defines::WHITE_PLAYER_ID;
}

BoardPos BoardUtils::getAdjacentPos(Defines::Direction dir,const BoardPos& currPos){
	BoardPos pos = currPos;
	switch(dir){
	case Defines::UP_LEFT:
		--pos.row;
		--pos.col;
		break;
	case Defines::UP:
		--pos.row;
		break;
	case Defines::UP_RIGHT:
		--pos.row;
		++pos.col;
		break;
	case Defines::RIGHT:
		++pos.col;
		break;
	case Defines::DOWN_RIGHT:
		++pos.row;
		++pos.col;
		break;
	case Defines::DOWN:
		++pos.row;
		break;
	case Defines::DOWN_LEFT:
		++pos.row;
		--pos.col;
		break;
	case Defines::LEFT:
		--pos.col;
		break;
	default:
		std::cerr<<"Invalid dir: "<< dir<<"\n";
		break;
	}
	return pos;
}

bool BoardUtils::doCollideWithPiece(const BoardPos& selectedPos, const ChessPiece::PlayerPieces& pieces, int32_t& outCollisionRelativeId){
	const size_t size = pieces.size();
	for(size_t i = 0; i < size; ++i){
		if(selectedPos == pieces[i]->getBoardPos()){
			outCollisionRelativeId = static_cast<int32_t>(i);
			return true;
		}
	}
	return false;
}

TileType BoardUtils::getTileType(const BoardPos& boardPos, const ChessPiece::PlayerPieces& playerPieces, const ChessPiece::PlayerPieces& enemyPieces){
	int32_t collisionId = -1;
	if(doCollideWithPiece(boardPos, playerPieces, collisionId)){
		return TileType::GUARD;
	}
	if(doCollideWithPiece(boardPos, enemyPieces, collisionId)){
		return TileType::TAKE;
	}
	return TileType::MOVE;
}
