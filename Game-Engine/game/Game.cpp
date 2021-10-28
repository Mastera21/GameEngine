
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

int32_t Game::init(const GameCfg cfg){

	//Images
	layer2Image.create(cfg.layer2Rsrcid);
	pressKeyImage.create(cfg.pressKeysRsrcId);
	pressKeyImage.activateAlphaModulation();

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

void Game::draw(){

	//pressKeyImage.draw();

	if(isPressTextHidden){
		//Option Menu
		gDrawMgr->addDrawCmd(optionPage);
	}else{
		//Main Menu
		gDrawMgr->addDrawCmd(mainMenu);
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
			pressKeyImage.moveUp(-10);
			break;
		case Keyboard::KEY_DOWN:
			pressKeyImage.moveDown(10);
			break;
		case Keyboard::KEY_LEFT:
			pressKeyImage.moveLeft(-10);
			break;
		case Keyboard::KEY_RIGHT:
			pressKeyImage.moveRight(10);
			break;

		case Keyboard::KEY_Q:
			pressKeyImage.setWidth(pressKeyImage.getWidth() - 10);
			break;
		case Keyboard::KEY_W:
			pressKeyImage.setHeight(pressKeyImage.getWidth() + 10);
			break;
		case Keyboard::KEY_E:
			pressKeyImage.setHeight(pressKeyImage.getHeight() - 10);
			break;
		case Keyboard::KEY_R:
			pressKeyImage.setHeight(pressKeyImage.getHeight() + 10);
			break;

		case Keyboard::KEY_T:
			pressKeyImage.setOpacity(pressKeyImage.getOpacity() - 10);
			break;
		case Keyboard::KEY_Y:
			pressKeyImage.setOpacity(pressKeyImage.getOpacity() + 10);
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

