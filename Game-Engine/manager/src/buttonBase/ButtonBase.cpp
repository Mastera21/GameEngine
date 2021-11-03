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

bool ButtonBase::isInputUnlocked() const{
	return _isInputUnlocked;
}

bool ButtonBase::containsEvent(const sd::Event &e){
	return Image::containsPoint(e.pos);
}

