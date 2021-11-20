
#include "manager/debug/Console.h"


//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "sdl/Event.h"
#include "utils/drawing/Color.h"
//Own components headers


int32_t Console::init(int64_t maxFrame, int32_t fontId){
	_maxFrames = maxFrame;

	Point textPos = Point(0,40);
	_fpsText[FPS_TEXT_IDX].create("0", fontId, Colors::RED, textPos);

	textPos.y += 40;
	_fpsText[ACTIVE_TIMER_IDX].create("0", fontId, Colors::RED, textPos);

	textPos.y += 40;
	_fpsText[ACTIVE_WIDGETS_IDX].create("0", fontId, Colors::RED, textPos);
	return EXIT_SUCCESS;
}


void Console::handleEvent(const Event& e){
	if(e.type != TouchEvent::KEYBOARD_PRESS){
		return;
	}

	if(e.key == Keyboard::KEY_TILDA){
		_isActive = !_isActive;
	}
}
void Console::update(int64_t elapsedMicroseconds, size_t activeTimers){
	constexpr auto microSecondsInASecond = 1000000;
	auto currFps = microSecondsInASecond / elapsedMicroseconds;
	if(currFps > _maxFrames){
		currFps = _maxFrames;
	}
	std::string textContent = "FPS: ";
	textContent.append(std::to_string(currFps));
	_fpsText[FPS_TEXT_IDX].setText(textContent);
	textContent = "Active Timers: ";
	textContent.append(std::to_string(activeTimers));
	_fpsText[ACTIVE_TIMER_IDX].setText(textContent);

}
void Console::updateActiveWidgets(int32_t activeWidgets){
	std::string textContent = "Active Widgets: ";
	textContent.append(std::to_string(activeWidgets));
	_fpsText[ACTIVE_WIDGETS_IDX].setText(textContent);
}
void Console::draw(){
	for(int32_t i = 0; i < DEBUG_TEXTS_COUNT; ++i){
		_fpsText[i].draw();
	}
}
bool Console::isActive() const{
	return _isActive;
}
