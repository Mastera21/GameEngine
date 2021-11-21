#include "manager/drawing/Widget.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/managers/DrawMgr.h"

int32_t Widget::getOpacity() const{
	return _drawParams.opacity;
}

Point Widget::getPos() const{
	return _drawParams.pos;
}

int32_t Widget::getWidth() const{
	return _drawParams.width;
}
int32_t Widget::getHeight()const{
	return _drawParams.height;
}

int32_t Widget::getX() const{
	return _drawParams.pos.x;
}
int32_t Widget::getY() const{
	return _drawParams.pos.y;
}

int32_t Widget::getRsrcId() const{
	return _drawParams.rsrcId;
}

double Widget::getRotation() const{
	return _drawParams.rotationAngle;
}

bool Widget::containsPoint(const Point& pos) const{
	const Rectangle bound(_drawParams.pos.x, _drawParams.pos.y, _drawParams.width, _drawParams.height);
	return bound.isPointInside(pos);
}

bool Widget::isVisible() const{
	return _isVisible;
}
bool Widget::isCreated() const{
	return _isCreated;
}

void Widget::draw(){
	if(_isVisible){
		gDrawMgr->addDrawCmd(_drawParams);
	}
}

void Widget::reset(){
	_isDestroyed = true;
	_isCreated = false;
	_isVisible = true;
	_isAlphaModulationEnabled = false;
	_drawParams.reset();
}

void Widget::setPos(const Point& pos){
	_drawParams.pos = pos;
}

void Widget::setPos(int32_t x, int32_t y){
	_drawParams.pos.x = x;
	_drawParams.pos.y = y;
}

void Widget::setOpacity(int32_t opacity){
	if(!_isAlphaModulationEnabled){
		std::cerr<<"alpha modulation was not enabled for rsrcId: "<<_drawParams.rsrcId<<" .Will not change opacity"<<"\n";
		return;
	}
	_drawParams.opacity = opacity;
	gDrawMgr->setWidgetOpacity(_drawParams, opacity);
}

void Widget::activateAlphaModulation(){
	if(_isAlphaModulationEnabled){
		std::cerr<<"alpha modulation was already enabled for rsrcId: "<<_drawParams.rsrcId<<"\n";
		return;
	}
	gDrawMgr->setWidgetBlendMode(_drawParams, BlendMode::BLEND);
}

void Widget::deactivateAlphaModulation(){
	if(!_isAlphaModulationEnabled){
			std::cerr<<"alpha modulation was not enabled for rsrcId: "<<_drawParams.rsrcId<<"\n";
			return;
	}
	_isAlphaModulationEnabled = false;
	gDrawMgr->setWidgetBlendMode(_drawParams, BlendMode::NONE);
}

void Widget::setFlipType(WidgetFlip flipType){
	_drawParams.fliType = flipType;
}

void Widget::setRotation(double angle){
	_drawParams.rotationAngle = angle;
}

void Widget::rotateRight(double radius){
	_drawParams.rotationAngle += radius;

	while(_drawParams.rotationAngle > FULL_ROTATION){
		_drawParams.rotationAngle -= FULL_ROTATION;
	}
}
void Widget::rotateLeft(double radius){
	_drawParams.rotationAngle -= radius;

	while(_drawParams.rotationAngle < 0){
		_drawParams.rotationAngle += FULL_ROTATION;
	}
}

void Widget::setRotationCenter(const Point& pos){
	_drawParams.rotationCenter = pos;
}

void Widget::show(){
	_isVisible = true;
}
void Widget::hide(){
	_isVisible = false;
}

void Widget::moveUp(int32_t y){
	_drawParams.pos.y -= y;
}

void Widget::moveDown(int32_t y){
	_drawParams.pos.y += y;
}

void Widget::moveLeft(int32_t x){
	_drawParams.pos.x -= x;
}

void Widget::moveRight(int32_t x){
	_drawParams.pos.x += x;
}
void Widget::setWidth(int32_t width){
	_drawParams.width = width;
}
void Widget::setHeight(int32_t height){
	_drawParams.height = height;
}
