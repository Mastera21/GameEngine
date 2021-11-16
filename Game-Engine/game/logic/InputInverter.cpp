#include "game/logic/InputInverter.h"
//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"

int32_t InputInverter::init(int32_t boardWidth, int32_t boardHeight){
	_boardWidth = boardWidth;
	_boardHeight = boardHeight;
	return EXIT_SUCCESS;
}
void InputInverter::setBoardFlipType(WidgetFlip flipType){
	_flipType = flipType;
}
void InputInverter::invertEvent(Event& e){
	switch(_flipType){
	case WidgetFlip::NONE:
		break;
	case WidgetFlip::HORIZONTAL:
		e.pos.y = _boardHeight - e.pos.y;
		break;
	case WidgetFlip::VERTICAL:
		e.pos.x = _boardWidth - e.pos.x;
		break;
	case WidgetFlip::HORIZONTAL_AND_VERTICAL:
		e.pos.y = _boardHeight - e.pos.y;
		e.pos.x = _boardWidth - e.pos.x;
		break;
	default:
		break;
	}
}
