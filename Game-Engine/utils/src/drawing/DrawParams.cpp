
#include "utils/drawing/DrawParams.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers


void DrawParams::reset(){
	pos = Point::UNDEFINED;
	frameRect = Rectangle::ZERO;
	fliType = WidgetFlip::NONE;
	widgetType = WidgetType::UNKNOWN;

	//Draw dimensions of the texture
	width = 0;
	height = 0;

	opacity = FULL_OPACITY;

	rsrcId = INVALID_RSRC_ID;
}
