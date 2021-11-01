
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

	//----------Menu----------									 //Pos
	mainMenu.create("Menu", cfg.textFontId, Colors::ORANGE, Point(490,0));
	play.create("Play", cfg.textFontId, Colors::WHITE, Point(50,180));
	optionText.create("Options", cfg.textFontId, Colors::WHITE, Point(50,250));
	quit.create("Quit", cfg.textFontId, Colors::WHITE, Point(50,320));

	//----------options----------
	optionPage.create("Options", cfg.textFontId, Colors::CYAN, Point(490,0));
	back.create("Back", cfg.textFontId, Colors::WHITE, Point(50,500));

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
	quit.draw();
	optionText.draw();
	play.draw();
	mainMenu.draw();

	//----------Option Menu----------
	if(buttonOption){
		_wheel.draw();
		_hero.draw();
		back.draw();
		optionPage.draw();
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

	//----------Option Menu----------
		case Keyboard::KEY_M:
			buttonOption = true;
			back.show();
			optionPage.show();
			quit.hide();
			optionText.hide();
			play.hide();
			mainMenu.hide();
			break;
	//----------Main Menu----------
		case Keyboard::KEY_N:
			buttonOption = false;
			back.hide();
			optionPage.hide();
			quit.show();
			optionText.show();
			play.show();
			mainMenu.show();
			break;
		default:
			break;
	}

	//----------Objects----------
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

