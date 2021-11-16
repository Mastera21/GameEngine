#ifndef GAME_INTERFACES_GAMEINTERFACE_H_
#define GAME_INTERFACES_GAMEINTERFACE_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/defines/ChessDefines.h"
//Forward declarations

class GameInterface{
public:
	virtual ~GameInterface() = default;
	virtual void finishTurn() = 0;
	virtual void onPawnPromotion() = 0;
	virtual void promotePiece(PieceType pieceType) = 0;
	virtual void onBoardAnimFinished() = 0;

};

#endif /* GAME_INTERFACES_GAMEINTERFACE_H_ */
