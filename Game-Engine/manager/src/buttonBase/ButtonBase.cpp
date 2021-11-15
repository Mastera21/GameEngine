#include "manager/buttonBase/ButtonBase.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "sdl/Event.h"
//Own components headers

void ButtonBase::draw(){
	Image::draw();
}

void ButtonBase::lockInput(){
	_isInputUnlocked = false;
	Image::setFrame(DISABLED);
}

void ButtonBase::unlockInput(){
	_isInputUnlocked = true;
	Image::setFrame(UNCLICKED);
}

void ButtonBase::destroy(){
	_isInputUnlocked = false;
	Image::destroy();
}

bool ButtonBase::isInputUnlocked() const{
	return _isInputUnlocked;
}

bool ButtonBase::containsEvent(const Event &e){
	return Image::containsPoint(e.pos);
}
