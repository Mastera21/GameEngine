
#include "Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "utils/drawing/Color.h"

#include "manager/managers/DrawMgr.h"
#include "manager/managers/RsrcMgr.h"

int32_t Game::init([[maybe_unused]]const GameCfg cfg){

	//Images

	layer2Image.rsrcId = cfg.layer2Rsrcid;
	Rectangle rect = gRsrcMgr->getImageFrame(layer2Image.rsrcId);
	layer2Image.width = rect.w;
	layer2Image.height = rect.h;
	layer2Image.pos = Point::ZERO;
	layer2Image.widgetType = WidgetType::IMAGE;

	pressKeyImage.rsrcId = cfg.pressKeysRsrcId;
	rect = gRsrcMgr->getImageFrame(pressKeyImage.rsrcId);
	pressKeyImage.width = rect.w;
	pressKeyImage.height = rect.h;
	pressKeyImage.pos = Point::ZERO;
	pressKeyImage.widgetType = WidgetType::IMAGE;

	//Menu and Options

	gRsrcMgr->createText("Menu", Colors::ORANGE, cfg.textFontId, mainMenu.textId, mainMenu.width, mainMenu.height);
	mainMenu.pos = Point::ZERO;
	mainMenu.pos.x += 490;
	mainMenu.widgetType = WidgetType::TEXT;

	gRsrcMgr->createText("Options", Colors::CYAN, cfg.textFontId, optionPage.textId, optionPage.width, optionPage.height);
	optionPage.pos = Point::ZERO;
	optionPage.pos.x += 490;
	optionPage.widgetType = WidgetType::TEXT;


	return EXIT_SUCCESS;
}

void Game::deinit(){
	gRsrcMgr->unloadText(mainMenu.textId);
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
			//gRsrcMgr->reloadText("DICE", Colors::CYAN, gFontId, helloText.textId, helloText.width, helloText.height);
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

