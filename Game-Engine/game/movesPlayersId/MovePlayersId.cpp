#include "game/movesPlayersId/MovePlayersId.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "sdl/Event.h"
#include "utils/drawing/Color.h"
//Own components headers

int32_t MovePlayersId::init(int32_t textId){
	Point textPos = Point(500,0);
	_movesWhiteText.create("Current player is White", textId, Colors::WHITE, textPos);
	_movesBlackText.create(" ", textId, Colors::WHITE, textPos);
	_isWhiteOnTurn = true;

	return EXIT_SUCCESS;
}
void MovePlayersId::updatePlayerText(int32_t activePlayer){
	std::string currentPlayer = "Current player is :";
	if(activePlayer == 0){
		_isWhiteOnTurn = true;
		currentPlayer.append("White");
		_movesWhiteText.setText(currentPlayer);
	}else{
		_isWhiteOnTurn = false;
		currentPlayer.append("Black");
		_movesBlackText.setText(currentPlayer);
	}
}
void MovePlayersId::draw(){
	if(_isWhiteOnTurn){
		_movesWhiteText.draw();
	}else{
		_movesBlackText.draw();
	}
}
