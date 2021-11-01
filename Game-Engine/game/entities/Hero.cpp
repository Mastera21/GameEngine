#include "game/entities/Hero.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers

int32_t Hero::init(int32_t heroRsrcId){

	_img.create(heroRsrcId, Point(400,200));

	return EXIT_SUCCESS;
}
void Hero::deinit(){

}
void Hero::draw(){
	_img.draw();
}
void Hero::handleEvent(const sd::Event& event){
	if(TouchEvent::KEYBOARD_PRESS != event.type){
		return;
	}
	switch(event.key){
	case Keyboard::KEY_D:
		_img.setFlipType(WidgetFlip::NONE);
		_img.setNextFrame();
		_img.moveRight(10);
		break;
	case Keyboard::KEY_A:
		_img.setFlipType(WidgetFlip::HORIZONTAL);
		_img.setPrevFrame();
		_img.moveLeft(10);
		break;
	default:
		break;
	}
}
