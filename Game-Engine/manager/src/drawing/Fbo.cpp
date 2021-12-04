#include "manager/drawing/Fbo.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/managers/RsrcMgr.h"
#include "manager/managers/DrawMgr.h"

 FBO::~FBO(){
    if(_isCreated && !_isDestroyed){
		destroy();
	}
}
void FBO::create(int32_t width, int32_t height, const Point &pos, const Color &clearColor){
    if(_isCreated){
		std::cerr<<"Error, FBO with fboId: "<<_drawParams.fboId<<" was already created.\n";
		return;
	}

    _drawParams.width = width;
	_drawParams.height = height;

	_drawParams.frameRect.x = 0;
	_drawParams.frameRect.y = 0;
	_drawParams.frameRect.w = _drawParams.width;
	_drawParams.frameRect.h = _drawParams.height;

    gRsrcMgr->createFbo(width, height, _drawParams.fboId);
	_drawParams.pos = pos;
	_drawParams.widgetType = WidgetType::FBO;
    _clearColor = clearColor;

	_isCreated = true;
	_isDestroyed = false;
}
void FBO::destroy(){
    if(!_isCreated){
		std::cerr<<"Error, fbo was already destroy.\n";
		return;
	}
	_isCreated = false;
	_isDestroyed = true;

    _storedItems.clear();
    _clearColor = Colors::BLACK;
    _isLocked = true;

	Widget::reset();
}
void FBO::unlock(){
    if(!_isLocked){
		std::cerr<<"Error, FBO was not locked in the firs place.\n";
        return;
	}
	_isLocked = false;
    if(EXIT_SUCCESS != gDrawMgr->unlockRenderer()){
        std::cerr<<"Error, gDrawMgr->unlockRenderer() failed.\n";
    }
    gDrawMgr->setRendererTarget(_drawParams.fboId);

}
void FBO::lock(){
    if(_isLocked){
		std::cerr<<"Error, FBO was already locked.\n";
        return;
	}
	_isLocked = true;
    if(EXIT_SUCCESS != gDrawMgr->lockRenderer()){
        std::cerr<<"Error, gDrawMgr->lockRenderer() failed.\n";
    }
    gDrawMgr->resetRendererTarget();

}
void FBO::reset(){
    gDrawMgr->clearCurrentRendererTarget(_clearColor);
    _storedItems.clear();
}
void FBO::addWidget(const Widget &widget){
    if(!widget.isCreated()){
        std::cerr<<"Error, trying to add not createed widget for FBO whit id: "<<_drawParams.fboId<<"\n";
        return;
    }
    _storedItems.push_back(widget.getDrawParams());
}
void FBO::update() const{
    for(const auto& i : _storedItems){
        gDrawMgr->addDrawCmd(i);
    }
}