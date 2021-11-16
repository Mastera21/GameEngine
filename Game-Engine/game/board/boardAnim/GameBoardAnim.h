#ifndef GAME_BOARD_BOARDANIM_GAMEBOARDANIM_H_
#define GAME_BOARD_BOARDANIM_GAMEBOARDANIM_H_
//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "manager/drawing/Image.h"

//Forward declarations
class GameInterface;

class GameBoardAnim {
public:
	int32_t init(GameInterface* gameInterface, Image* boardImg);
	void startAnim(int32_t playerId);

private:
	GameInterface* _gameInterface = nullptr;
	Image* _boardImg = nullptr;
	int32_t _currRotation { 0 };
	WidgetFlip _targetFlipType = WidgetFlip::NONE;
};

#endif /* GAME_BOARD_BOARDANIM_GAMEBOARDANIM_H_ */
