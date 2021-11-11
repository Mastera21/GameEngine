#include "game/pieces/types/UnfinishedPiece.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

int32_t UnfinishedPiece::init(const ChessPieceCfg& cfg){

	if(EXIT_SUCCESS != ChessPiece::init(cfg)){
		std::cerr<<"ChessPiece::init() failed\n";
		return EXIT_FAILURE;
	}
	const auto pieceAbsPos = BoardUtils::getAbsPos(_boardPos);
	_notReadyText.create("!",cfg.unfinishedPieceFontId, Colors::RED, pieceAbsPos);

	return EXIT_SUCCESS;
}
void UnfinishedPiece::draw() {
	ChessPiece::draw();
	_notReadyText.draw();
}
void UnfinishedPiece::setBoardPos(const BoardPos& pos) {
	ChessPiece::setBoardPos(pos);
	const auto pieceAbsPos = BoardUtils::getAbsPos(_boardPos);
	_notReadyText.setPos(pieceAbsPos);
}
