
#include "game/Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "utils/drawing/Color.h"

int32_t Game::init([[maybe_unused]]const GameCfg cfg){

	return EXIT_SUCCESS;
}

void Game::deinit(){

}

void Game::draw(){

}

void Game::handleEvent([[maybe_unused]]const Event& event){

}
