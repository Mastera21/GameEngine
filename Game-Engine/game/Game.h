#ifndef GAME_GAME_H_
#define GAME_GAME_H_


//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
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

	DrawParams mainMenu;
	DrawParams optionPage;

	bool isPressTextHidden = false;

};

#endif /* GAME_GAME_H_ */
