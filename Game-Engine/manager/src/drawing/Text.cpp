#include "manager/drawing/Text.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/managers/RsrcMgr.h"

Text::~Text(){
	if(_isCreated && !_isDestroyed){
		destroy();
	}
}
void Text::create(const std::string& text,  int32_t fontId, const Color& color, const Point &pos){
	if(_isCreated){
		std::cerr<<"Error, text with rsrcId: "<<fontId<<"was already created.\n";
		return;
	}
	gRsrcMgr->createText(text, color, fontId, _drawParams.rsrcId, _drawParams.width, _drawParams.height);

	_drawParams.frameRect.x = 0;
	_drawParams.frameRect.y = 0;
	_drawParams.frameRect.w = _drawParams.width;
	_drawParams.frameRect.h = _drawParams.height;

	_drawParams.pos = pos;
	_drawParams.widgetType = WidgetType::TEXT;

	 _textContent = text;
	 _color = color;
	 _fontId = fontId;

	_isCreated = true;
	_isDestroyed = false;

}
void Text::destroy(){
	if(!_isCreated){
		std::cerr<<"Error, image was already destroy.\n";
		return;
	}
	_isCreated = false;
	_isDestroyed = true;

	if(gRsrcMgr){
		gRsrcMgr->unloadText(_drawParams.textId);
	}

	Widget::reset();
}
void Text::setText(const std::string& text){
	if(text == _textContent){
		return;
	}

	_textContent = text;
	gRsrcMgr->reloadText(text, _color, _fontId, _drawParams.rsrcId, _drawParams.width, _drawParams.height);

	_drawParams.frameRect.w = _drawParams.width;
	_drawParams.frameRect.h = _drawParams.height;
}
void Text::setColor(const Color& color){
	if(color == _color){
		return;
	}
	_color = color;
	gRsrcMgr->reloadText(_textContent, _color, _fontId, _drawParams.rsrcId, _drawParams.width, _drawParams.height);

	_drawParams.frameRect.w = _drawParams.width;
	_drawParams.frameRect.h = _drawParams.height;
}
std::string Text::getTextContent() const{
	return _textContent;
}
