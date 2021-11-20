
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

	if(EXIT_SUCCESS != _pieceHandler.init(&_board, this, cfg.whitePiecesRsrcId, cfg.blackPiecesRsrcId, cfg.unfinishedPieceFontId)){
		std::cerr<<"_pieceHandler.init() failed.\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _piecePromotionPanel.init(cfg.piecePromotionPanelCfg, this)){
		std::cerr<<"_piecePromotionPanel.init() failed.\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _gameBoardAnim.init(this, &_board.getBoardImg())){
		std::cerr<<"_piecePromotionPanel.init() failed.\n";
		return EXIT_FAILURE;
	}
	std::cout<<"White player is on turn\n";

	return EXIT_SUCCESS;
}
void Game::deinit(){

}
void Game::draw(){
	_board.draw();
	_pieceHandler.draw();
	_piecePromotionPanel.draw();
}
void Game::handleEvent(Event& event){
	if(_piecePromotionPanel.isActive()){
		_piecePromotionPanel.handleEvent(event);
		return;
	}
	_pieceHandler.handleEvent(event);
}
void Game::promotePiece(PieceType pieceType){
	_pieceHandler.piecePromotion(pieceType);
}
void Game::finishTurn(){
	_gameBoardAnim.startAnim(_gameLogic.getActivePlayerId());
	if(Defines::WHITE_PLAYER_ID == _gameLogic.getActivePlayerId()){
		std::cout<<"White player is on turn\n";
	}else{
		std::cout<<"Black player is on turn\n";
	}
}
void Game::onPawnPromotion() {
	_piecePromotionPanel.activate(_gameLogic.getActivePlayerId());
}
void Game::onBoardAnimFinished(){
	_gameLogic.finishTurn();
	_pieceHandler.setCurrPlayerId(_gameLogic.getActivePlayerId());
}
