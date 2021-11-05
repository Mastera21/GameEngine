#include "game/entities/Wheel.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers

int32_t Wheel::init(int32_t wheelRsrcId){

	_imgWheel.create(wheelRsrcId, Point(0,0));
	_imgWheel.setWidth(150);
	_imgWheel.setHeight(150);

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

void Wheel::startAnim(){
	if(isActive){
		std::cerr<<"Wheel anim is already active\n";
		return;
	}
	isActive = true;


	std::cerr << "Wheel anim started\n";
}
void Wheel::stopAnim(){
	if(!isActive){
		std::cerr<<"Wheel anim was not active\n";
		return;
	}
	isActive = false;

	std::cerr << "Wheel anim stoped\n";
}

void Wheel::process(){
	while(!isActive){
		return;
	}
	_imgWheel.rotateRight(2);
}
