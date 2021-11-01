#ifndef GAME_ENTITIES_WHEEL_H_
#define GAME_ENTITIES_WHEEL_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "manager/drawing/Image.h"
//Forward declarations

class Wheel {
public:
	int32_t init(int32_t wheelRsrcId);
	void deinit();
	void draw();
	void handleEvent(const sd::Event& event);

private:
	Image _imgWheel;
};
#endif /* GAME_ENTITIES_WHEEL_H_ */
