
#include "game/Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "utils/drawing/Color.h"
#include "sdl/Event.h"
#include "game/defines/ChessDefines.h"

int32_t Game::init(const GameCfg cfg){

	if(EXIT_SUCCESS != _board.init(cfg.chessBoardRsrcId, cfg.targetRsrcId, cfg.moveTailId, cfg.blinkTargetId)){
		std::cerr<<"_board.init() failed.\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _pieceHandler.init(&_board, cfg.whitePiecesRsrcId, cfg.blackPiecesRsrcId, cfg.unfinishedPieceFontId)){
		std::cerr<<"_pieceHandler.init() failed.\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Game::deinit(){

}

void Game::draw(){
	_board.draw();
	_pieceHandler.draw();
}

void Game::handleEvent(const Event& event){
	_pieceHandler.handleEvent(event);
}
