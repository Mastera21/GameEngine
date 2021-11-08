#ifndef GAME_ENTITIES_WHEEL_H_
#define GAME_ENTITIES_WHEEL_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "manager/drawing/Image.h"
#include "manager/time/TimerClient.h"
//Forward declarations

class Wheel : public TimerClient{
public:

	~Wheel();

	int32_t init(int32_t wheelRsrcId, int32_t rotateAnimTimerId);
	void deinit();
	void draw();
	void handleEvent(const Event& event);

	void startAnim();
	void stopAnim();

private:
	Image _imgWheel;

	int32_t _rotateAnimTimerId = -1;
	bool isActive = false;

	void processRotAnim();
	void onTimeout(int32_t timerId) final;
};
#endif /* GAME_ENTITIES_WHEEL_H_ */
