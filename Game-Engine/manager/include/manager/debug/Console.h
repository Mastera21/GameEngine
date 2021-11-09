#ifndef MANAGER_INCLUDE_MANAGER_DEBUG_CONSOLE_H_
#define MANAGER_INCLUDE_MANAGER_DEBUG_CONSOLE_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "manager/drawing/Text.h"
//Own components headers
class Event;

enum DebugTextId {
	FPS_TEXT_IDX, ACTIVE_TIMER_IDX, DEBUG_TEXTS_COUNT
};

class Console {
public:
	int32_t init(int64_t maxFrame, int32_t fontId);
	void handleEvent(const Event& e);
	void update(int64_t elapsedMicroseconds, size_t activeTimers);
	void draw();
	bool isActive() const;

private:
	Text _fpsText[DEBUG_TEXTS_COUNT];
	int64_t _maxFrames = 0;    //used to determine the current FPS
	int32_t _updateCounter = 0; //used for skipping turns
	bool _isActive = false;
};

#endif /* MANAGER_INCLUDE_MANAGER_DEBUG_CONSOLE_H_ */
