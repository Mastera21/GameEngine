
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

	if(EXIT_SUCCESS != _wheel.init(cfg.wheelId, cfg.wheelRotateAnimTimerId)){
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

	//----------Options----------
	optionPage.create("Options", cfg.textFontId, Colors::CYAN, Point(490,0));
	back.create("Back", cfg.textFontId, Colors::WHITE, Point(50,500));

	buttonOption = false;

	optionPage.hide();

	//----------Buttons----------
	const int32_t buttonRsrcId[WHEEL_BTNS_COUNT] = {
			cfg.startButtonRsrcId, cfg.stopButtonRsrcId
	};
	const Point buttonStartPos[WHEEL_BTNS_COUNT] = {
			Point(500,500), Point(500,560)
	};


	for(int32_t i = 0; i < WHEEL_BTNS_COUNT; ++i){
		if(EXIT_SUCCESS !=_wheelButton[i].init(this, i)){
			std::cerr<<"_wheelButton["<<i<<"] failed.\n";
			return EXIT_FAILURE;
		}
		_wheelButton[i].create(buttonRsrcId[i],buttonStartPos[i]);

	}

	_wheelButton[WHEEL_STOP_BUTTON_IDX].unlockInput();

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
		//----------Buttons----------
		for(int32_t i = 0; i < WHEEL_BTNS_COUNT; ++i){
			_wheelButton[i].draw();
		}

		_wheel.draw();
		_hero.draw();
		back.draw();
		optionPage.draw();
	}


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

	for(int32_t i = 0; i < WHEEL_BTNS_COUNT; ++i){
		if(_wheelButton[i].isInputUnlocked() &&  _wheelButton[i].containsEvent(event)){
			_wheelButton[i].handleEvent(event);
			return;
		}
	}

	//----------Objects----------
	_hero.handleEvent(event);
	_wheel.handleEvent(event);
}

void Game::onButtonPressed(int32_t buttonId) {
	switch(buttonId){
	case WHEEL_START_BUTTON_IDX:
		_wheelButton[WHEEL_START_BUTTON_IDX].lockInput();
		_wheelButton[WHEEL_STOP_BUTTON_IDX].unlockInput();
		_wheel.startAnim();
		break;
	case WHEEL_STOP_BUTTON_IDX:
		_wheelButton[WHEEL_START_BUTTON_IDX].unlockInput();
		_wheelButton[WHEEL_STOP_BUTTON_IDX].lockInput();
		_wheel.stopAnim();
		break;
	default:
		std::cerr<<"Received unsupported buttonId: "<<buttonId<<"\n";
		break;
	}
}
