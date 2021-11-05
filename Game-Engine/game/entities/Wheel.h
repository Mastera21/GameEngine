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

	void startAnim();
	void stopAnim();

	void process();

private:
	Image _imgWheel;

	bool isActive = false;

};
#endif /* GAME_ENTITIES_WHEEL_H_ */
