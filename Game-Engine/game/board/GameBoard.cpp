#include "game/board/GameBoard.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

int32_t GameBoard::init(int32_t boardRsrcId, int32_t targetRsrcId){
	_boardImg.create(boardRsrcId);
	_targetImg.create(targetRsrcId);
	_targetImg.hide();
	return EXIT_SUCCESS;
}
void GameBoard::draw(){
	_boardImg.draw();
	_targetImg.draw();
}

void GameBoard::onPieceGrabbed(const BoardPos& boardPos) {
	_targetImg.show();
	_targetImg.setPos(BoardUtils::getAbsPos(boardPos));
}
void GameBoard::onPieceUngrabbed() {
	_targetImg.hide();
}
