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
	/*if(_isCreated){
		std::cerr<<"Error, image with rsrcId: "<<rsrcId<<" was already created.\n";
		return;
	}*/

	const Frames& frames = gRsrcMgr->getImageFrame(rsrcId);
	_maxFrames = static_cast<int32_t>(frames.size());
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

void Image::setFrame(int32_t frameIdx){
	if(0 > frameIdx || frameIdx >= _maxFrames){
		std::cerr<<"Error, tryinh to set invalid frameId: "<<frameIdx<<" for Image with rsrcId: " <<_drawParams.rsrcId<<"\n";
		return;
	}
	const Frames& frames = gRsrcMgr->getImageFrame(_drawParams.rsrcId);
	_drawParams.frameRect = frames[frameIdx];

	_currFrame = frameIdx;

}
void Image::setNextFrame(){
	++_currFrame;
	if(_currFrame == _maxFrames){
		_currFrame = 0;
	}
	const Frames& frames = gRsrcMgr->getImageFrame(_drawParams.rsrcId);
	_drawParams.frameRect = frames[_currFrame];
}
void Image::setPrevFrame(){
	--_currFrame;
	if(_currFrame == -1){
		_currFrame = _maxFrames - 1;
	}
	const Frames& frames = gRsrcMgr->getImageFrame(_drawParams.rsrcId);
	_drawParams.frameRect = frames[_currFrame];
}
int32_t Image::getFrame() const{
	return _currFrame;
}
