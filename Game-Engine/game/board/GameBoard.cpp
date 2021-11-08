#include "game/board/GameBoard.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers

int32_t GameBoard::init(int32_t boardRsrcId){
	_boardImg.create(boardRsrcId);
	return EXIT_SUCCESS;
}
void GameBoard::draw(){
	_boardImg.draw();
}
