
#include "game/logic/GameLogic.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/defines/ChessDefines.h"


GameLogic::GameLogic() : _activePlayerId(Defines::WHITE_PLAYER_ID){}

int32_t GameLogic::getActivePlayerId() const{
	return _activePlayerId;
}
void GameLogic::finishTurn(){
	if(_activePlayerId == Defines::WHITE_PLAYER_ID){
		_activePlayerId = Defines::BLACK_PLAYER_ID;
	}else {
		_activePlayerId = Defines::WHITE_PLAYER_ID;
	}
}
