#include "manager/drawing/Image.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/managers/RsrcMgr.h"

Image::~Image(){
	if(_isCreated && !_isDestroyed){
		destroy();
	}
}

void Image::create(int32_t rsrcId, const Point& pos){
	if(_isCreated){
		std::cerr<<"Error, image with rsrcId: "<<rsrcId<<"was already created.\n";
		return;
	}

	const Frames& frames = gRsrcMgr->getImageFrame(rsrcId);
	const auto firstFrame = frames.front();
	_drawParams.frameRect = firstFrame;

	_drawParams.rsrcId = rsrcId;
	_drawParams.width = _drawParams.frameRect.w;
	_drawParams.height = _drawParams.frameRect.h;
	_drawParams.pos = pos;
	_drawParams.widgetType = WidgetType::IMAGE;

	_isCreated = true;
	_isDestroyed = false;

}
void Image::destroy(){
	if(!_isCreated){
		std::cerr<<"Error, image was already destroy.\n";
		return;
	}
	_isCreated = false;
	_isDestroyed = true;
	Widget::reset();
}
