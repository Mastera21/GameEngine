#ifndef GAME_GAME_H_
#define GAME_GAME_H_


//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
#include "manager/drawing/Text.h"
#include "game/entities/Hero.h"
#include "game/entities/Wheel.h"
#include "sdl/Event.h"

//Forward declarations

class Game {
public:

	int32_t init(const GameCfg cfg);
	void deinit();
	void draw();
	void handleEvent(const sd::Event& event);

private:

	Image pressKeyImage;//first image
	Image layer2Image;//second image

	Text mainMenu;
	Text optionPage;
	Text _mousePos;

	Hero _hero;
	Wheel _wheel;

	bool buttonOption = false;

	void setMousePosText(const Point& mousePos);
};

#endif /* GAME_GAME_H_ */
