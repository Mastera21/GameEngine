#include "game/buttons/WheelButton.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "game/buttonInterface/ButtonInterface.h"
//Own components headers


int32_t WheelButton::init(ButtonInterface* gameProxy, int32_t buttonId){
	if(gameProxy == nullptr){
		std::cerr<<"nullptr provided for _gameProxy. ButtonId: " << _buttonId<< "\n";
		return EXIT_FAILURE;
	}
	_gameProxy = gameProxy;
	_buttonId = buttonId;

	return EXIT_SUCCESS;
}

void WheelButton::handleEvent(const sd::Event &e) {
	if(e.type == TouchEvent::TOUCH_PRESS){
		setFrame(CLICKED);
	}else if(e.type == TouchEvent::TOUCH_RELEASE){
		setFrame(UNCLICKED);
	}
	_gameProxy->onButtonPressed(_buttonId);
}
