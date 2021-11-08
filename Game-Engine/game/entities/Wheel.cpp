#include "game/entities/Wheel.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers

Wheel::~Wheel(){
	if(isActiveTimerId(_rotateAnimTimerId)){
		stopTimer(_rotateAnimTimerId);
	}
}

int32_t Wheel::init(int32_t wheelRsrcId, int32_t rotateAnimTimerId){

	_imgWheel.create(wheelRsrcId, Point(0,0));
	_imgWheel.setWidth(150);
	_imgWheel.setHeight(150);

	_rotateAnimTimerId = rotateAnimTimerId;

	return EXIT_SUCCESS;
}

void Wheel::deinit(){

}

void Wheel::draw(){
	_imgWheel.draw();
}

void Wheel::handleEvent(const Event& event){
	if(TouchEvent::KEYBOARD_PRESS != event.type){
		return;
	}

	switch(event.key){
	case Keyboard::KEY_E:
		_imgWheel.rotateRight(5);
		break;
	case Keyboard::KEY_Q:
		_imgWheel.rotateLeft(5);
		break;
	default:
		break;
	}
}

void Wheel::startAnim(){
	if(isActive){
		std::cerr<<"Wheel anim is already active\n";
		return;
	}
	isActive = true;

	startTimer(20, _rotateAnimTimerId, TimerType::PULSE);
}
void Wheel::stopAnim(){
	if(!isActive){
		std::cerr<<"Wheel anim was not active\n";
		return;
	}
	isActive = false;

	stopTimer(_rotateAnimTimerId);
}

void Wheel::onTimeout(int32_t timerId){
	if(timerId == _rotateAnimTimerId){
		processRotAnim();
	}else{
		std::cerr<<"Received unsupported timerId: "<<timerId<<"\n";
	}
}

void Wheel::processRotAnim(){
	_imgWheel.rotateRight(2);
}


