#ifndef GAME_ENTITIES_HERO_H_
#define GAME_ENTITIES_HERO_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "manager/drawing/Image.h"
//Forward declarations

class Hero {
public:
	int32_t init(int32_t heroRsrcId);
	void deinit();
	void draw();
	void handleEvent(const sd::Event& event);

private:
	Image _img;
};

#endif /* GAME_ENTITIES_HERO_H_ */
