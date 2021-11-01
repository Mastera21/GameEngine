
#include "Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "utils/drawing/Color.h"

int32_t Game::init(const GameCfg cfg){

	if(EXIT_SUCCESS != _hero.init(cfg.runningGrilId)){
		std::cerr<<"Error, _hero.init() failed.\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _wheel.init(cfg.wheelId)){
		std::cerr<<"Error, _wheel.init() failed.\n";
		return EXIT_FAILURE;
	}

	//Images
	/*layer2Image.create(cfg.layer2Rsrcid);*/

	//Menu and Options									   	   	 //Pos
	mainMenu.create("Menu", cfg.textFontId, Colors::ORANGE, Point(490,0));
	optionPage.create("Options", cfg.textFontId, Colors::CYAN, Point(490,0));

	buttonOption = false;

	optionPage.hide();

	//MousePos
	_mousePos.create("_", cfg.textFontId, Colors::RED);
	_mousePos.hide();

	return EXIT_SUCCESS;
}

void Game::deinit(){
	_hero.deinit();
}

void Game::draw(){
	//----------Main Menu----------
	mainMenu.draw();

	//----------Option Menu----------
	if(buttonOption){
		optionPage.draw();
		_wheel.draw();
		_hero.draw();
	}

	//_mousePos.draw();
}

void Game::handleEvent(const sd::Event& event){
	if(TouchEvent::KEYBOARD_PRESS != event.type && TouchEvent::TOUCH_RELEASE != event.type){
		return;
	}

	//------------This is optional !!!----------------------

	//Refact keys
	switch(event.key){
		case Keyboard::KEY_M:
			buttonOption = true;
			optionPage.show();
			mainMenu.hide();
			break;
		case Keyboard::KEY_N:
			buttonOption = false;
			optionPage.hide();
			mainMenu.show();
			break;
		default:
			break;
	}

	_hero.handleEvent(event);
	_wheel.handleEvent(event);


	setMousePosText(event.pos);
}

void Game::setMousePosText(const Point& mousePos){
	_mousePos.show();
	_mousePos.setPos(mousePos);
	std::string text = "x: ";
	text.append(std::to_string(mousePos.x)).append(", y: ").append(std::to_string(mousePos.y));
	_mousePos.setText(text);
}

