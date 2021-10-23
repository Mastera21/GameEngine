
#include "Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "sdl/containers/ImageContainer.h"
#include "sdl/containers/TextContainer.h"
#include "utils/drawing/Color.h"


int32_t Game::init([[maybe_unused]]const GameCfg cfg, const ImageContainer* _imgContainerInterface,
															TextContainer* _textContainerInterface){

	if(_imgContainerInterface == nullptr){
		std::cerr<<"Error, nullptr provided for _imgContainerInterface\n";
		return EXIT_FAILURE;
	}

	_imgContainer = _imgContainerInterface;

	if(_textContainerInterface == nullptr){
		std::cerr<<"Error, nullptr provided for _textContainerInterface\n";
		return EXIT_FAILURE;
	}

	_textContainer = _textContainerInterface;


	layer2Image.rsrcId = cfg.layer2Rsrcid;

	Rectangle rect = _imgContainer->getImageFrame(layer2Image.rsrcId);
	layer2Image.width = rect.w;
	layer2Image.height = rect.h;
	layer2Image.pos = Point::ZERO;
	layer2Image.widgetType = WidgetType::IMAGE;

	pressKeyImage.rsrcId = cfg.pressKeysRsrcId;
	rect = _imgContainer->getImageFrame(pressKeyImage.rsrcId);
	pressKeyImage.width = rect.w;
	pressKeyImage.height = rect.h;
	pressKeyImage.pos = Point::ZERO;
	pressKeyImage.widgetType = WidgetType::IMAGE;

	_textContainer->createText("Hllo, C++ dudes", Colors::ORANGE, cfg.textFontId, helloText.textId, helloText.width, helloText.height);
	helloText.pos = Point::ZERO;
	helloText.widgetType = WidgetType::TEXT;
	return EXIT_SUCCESS;
}

void Game::deinit(){
	_textContainer->unloadText(helloText.textId);
}

void Game::draw(std::vector<DrawParams>& images){
	//images.push_back(pressKeyImage);
	//images.push_back(layer2Image);
	images.push_back(helloText);
}

void Game::handleEvent([[maybe_unused]]const sd::Event& event){
	if(TouchEvent::KEYBOARD_PRESS != event.type){
		return;
	}
	//Refact keys
	switch(event.key){
		case Keyboard::KEY_UP:
			pressKeyImage.pos.y -= 10;
			break;
		case Keyboard::KEY_DOWN:
			pressKeyImage.pos.y += 10;
			break;
		case Keyboard::KEY_LEFT:
			pressKeyImage.pos.x -= 10;
			break;
		case Keyboard::KEY_RIGHT:
			pressKeyImage.pos.x += 10;
			break;

		case Keyboard::KEY_Q:
			pressKeyImage.width -= 10;
			break;
		case Keyboard::KEY_W:
			pressKeyImage.width += 10;
			break;
		case Keyboard::KEY_E:
			pressKeyImage.height -= 10;
			break;
		case Keyboard::KEY_R:
			pressKeyImage.height += 10;
			break;

		case Keyboard::KEY_T:
			pressKeyImage.opacity -= 10;
			break;
		case Keyboard::KEY_Y:
			pressKeyImage.opacity += 10;
			break;
		default:
			break;
	}
}

