#include "game/board/GameBoard.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/utils/BoardUtils.h"

int32_t GameBoard::init(int32_t boardRsrcId, int32_t targetRsrcId, int32_t blinkTimerId){
	_boardImg.create(boardRsrcId);
	_targetImg.create(targetRsrcId);
	_targetImg.hide();

	_blinkTimerId = blinkTimerId;
	return EXIT_SUCCESS;
}
void GameBoard::draw(){
	_boardImg.draw();
	_targetImg.draw();
}

void GameBoard::onPieceGrabbed(const BoardPos& boardPos, const std::vector<TileData>& moveTiles) {
	_targetImg.show();
	_targetImg.setPos(BoardUtils::getAbsPos(boardPos));
	_currMoveTiles = moveTiles;

	startTimer(800,_blinkTimerId, TimerType::PULSE);
}
void GameBoard::onPieceUngrabbed() {
	_targetImg.hide();
	_currMoveTiles.clear();

	if(isActiveTimerId(_blinkTimerId)){
		stopTimer(_blinkTimerId);
	}
}

bool GameBoard::isMoveAllowed(const BoardPos &pos) const {
	for(const auto& i : _currMoveTiles){
		if(i.boardPos == pos){
			if(i.tileType == TileType::MOVE || i.tileType == TileType::TAKE){
				return true;
			}
		}
	}
	return false;
}
void GameBoard::onTimeout(int32_t timerId) {
	if(_blinkTimerId == timerId){
		if(_targetImg.isVisible()){
			_targetImg.hide();
		}else{
			_targetImg.show();
		}
	}else{
		std::cerr<<"Received unsupported timerId: "<<timerId<<"\n";
	}
}
