#include "game/entities/Wheel.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers

int32_t Wheel::init(int32_t wheelRsrcId){

	_imgWheel.create(wheelRsrcId, Point(0,0));
	_imgWheel.setWidth(200);
	_imgWheel.setHeight(200);

	return EXIT_SUCCESS;
}
void Wheel::deinit(){

}
void Wheel::draw(){
	_imgWheel.draw();
}
void Wheel::handleEvent(const sd::Event& event){
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
