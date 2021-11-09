#ifndef GAME_PROXIES_GAMEBOARDINTERFACE_H_
#define GAME_PROXIES_GAMEBOARDINTERFACE_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers

//Forward declarations
struct BoardPos;

class GameBoardInterface{
public:
	virtual ~GameBoardInterface() = default;

	virtual void onPieceGrabbed(const BoardPos& boardPos) = 0;
	virtual void onPieceUngrabbed() = 0;
};

#endif /* GAME_PROXIES_GAMEBOARDINTERFACE_H_ */
