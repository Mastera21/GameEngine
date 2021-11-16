#include "game/board/boardAnim/GameBoardAnim.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/interfaces/GameInterface.h"


int32_t GameBoardAnim::init(GameInterface* gameInterface, Image* boardImg){
	if(gameInterface == nullptr){
		std::cerr<<"Error, gameInterface is nullptr in GameBoardAnim.cpp\n";
		return EXIT_FAILURE;
	}
	_gameInterface = gameInterface;

	if(boardImg == nullptr){
		std::cerr<<"Error, boardImg is nullptr in GameBoardAnim.cpp\n";
		return EXIT_FAILURE;
	}
	_boardImg = boardImg;
	const Point rotCenter(_boardImg->getWidth() / 2, _boardImg->getHeight() / 2);
	_boardImg->setRotationCenter(rotCenter);

	return EXIT_SUCCESS;
}
void GameBoardAnim::startAnim(int32_t playerId){
	if(Defines::WHITE_PLAYER_ID == playerId){
		_targetFlipType = WidgetFlip::HORIZONTAL_AND_VERTICAL;
	}else{
		_targetFlipType = WidgetFlip::NONE;
	}
	_boardImg->setFlipType(_targetFlipType);
	_gameInterface->setWidgetFlip(_targetFlipType);

	_gameInterface->onBoardAnimFinished();
}
