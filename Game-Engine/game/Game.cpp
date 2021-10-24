
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

//TODO Remove me later.
static int32_t gFontId;

int32_t Game::init([[maybe_unused]]const GameCfg cfg, const ImageContainer* _imgContainerInterface,
															TextContainer* _textContainerInterface){

	if(_imgContainerInterface == nullptr){
		std::cerr<<"Error, nullptr provided for _imgContainerInterface\n";
		return EXIT_FAILURE;
	}

	_imgContainer = _imgContainerInterface;

	gFontId = cfg.textFontId;

	if(_textContainerInterface == nullptr){
		std::cerr<<"Error, nullptr provided for _textContainerInterface\n";
		return EXIT_FAILURE;
	}

	_textContainer = _textContainerInterface;


	layer2Image.rsrcId = cfg.layer2Rsrcid;

	//Images

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

	//Menu and Options

	_textContainer->createText("Menu", Colors::ORANGE, cfg.textFontId, mainMenu.textId, mainMenu.width, mainMenu.height);
	mainMenu.pos = Point::ZERO;
	mainMenu.pos.x += 490;
	mainMenu.widgetType = WidgetType::TEXT;

	_textContainer->createText("Options", Colors::CYAN, cfg.textFontId, optionPage.textId, optionPage.width, optionPage.height);
	optionPage.pos = Point::ZERO;
	optionPage.pos.x += 490;
	optionPage.widgetType = WidgetType::TEXT;


	return EXIT_SUCCESS;
}

void Game::deinit(){
	_textContainer->unloadText(mainMenu.textId);
}

void Game::draw(std::vector<DrawParams>& images){
	//images.push_back(pressKeyImage);
	//images.push_back(layer2Image);

	if(isPressTextHidden){
		//Option Menu
		images.push_back(optionPage);
	}else{
		//Main Menu
		images.push_back(mainMenu);
	}
}

void Game::handleEvent([[maybe_unused]]const sd::Event& event){
	if(TouchEvent::KEYBOARD_PRESS != event.type){
		return;
	}

	//------------This is optional !!!----------------------

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

		case Keyboard::KEY_B:
			//_textContainer->reloadText("DICE", Colors::CYAN, gFontId, helloText.textId, helloText.width, helloText.height);
			break;

		case Keyboard::KEY_M:
			isPressTextHidden = true;
			break;
		case Keyboard::KEY_N:
			isPressTextHidden = false;
			break;
		default:
			break;
	}
}

