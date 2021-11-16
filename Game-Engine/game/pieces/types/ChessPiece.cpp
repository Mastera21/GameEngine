#include "game/pieces/types/ChessPiece.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"
#include "sdl/Event.h"

int32_t ChessPiece::init(const ChessPieceCfg& cfg){
	if(cfg.pieceType == PieceType::UNKNOWN){
		std::cerr<<"Error, invalid PieceType provided: "<< static_cast<int32_t>(cfg.pieceType);
		return EXIT_FAILURE;
	}
	if(cfg.rsrcId == INVALID_RSRC_ID){
		std::cerr<<"Error, invalid rsrcId provided:\n";
		return EXIT_FAILURE;
	}

	 _boardPos = cfg.boardPos;
	 _playerId = cfg.playerId;
	 _pieceType = cfg.pieceType;

	 _pieceImg.create(cfg.rsrcId, BoardUtils::getAbsPos(_boardPos));
	 _pieceImg.setFrame(static_cast<int32_t>(_pieceType));

	return EXIT_SUCCESS;
}

void ChessPiece::draw(){
	_pieceImg.draw();
}

bool ChessPiece::selectFigure(const Event& event) const{
	return _pieceImg.containsPoint(event.pos);
}
BoardPos ChessPiece::getBoardPos() const{
	return _boardPos;
}

int32_t ChessPiece::getPlayerId() const{
	return _playerId;
}

void ChessPiece::setBoardPos(const BoardPos& pos){
	_boardPos = pos;
	_pieceImg.setPos(BoardUtils::getAbsPos(_boardPos));
}
void ChessPiece::setWidgetFlip(WidgetFlip flipType){
	_pieceImg.setFlipType(flipType);
}

