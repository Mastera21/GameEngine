
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

	if(EXIT_SUCCESS != _board.init(cfg.chessBoardRsrcId)){
		std::cerr<<"_board.init() failed.\n";
		return EXIT_FAILURE;
	}
	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = 7;
	pieceCfg.boardPos.col = 7;
	pieceCfg.playerId = BLACK_PLAYER_ID;
	pieceCfg.rsrcId = cfg.blackPiecesRsrcId;
	pieceCfg.pieceType = PieceType::ROOK;
	if(EXIT_SUCCESS != _piece.init(pieceCfg)){
		std::cerr<<"Error, _piece.init() failed\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Game::deinit(){

}

void Game::draw(){
	_board.draw();
	_piece.draw();
}

void Game::handleEvent([[maybe_unused]]const Event& event){
	if(event.type == TouchEvent::KEYBOARD_PRESS){
		if(event.key == Keyboard::KEY_M){
			_piece.setBoardPos({4,2});
		}
	}
}
