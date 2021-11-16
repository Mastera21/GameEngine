
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

	if(EXIT_SUCCESS != _inputInverter.init(cfg.piecePromotionPanelCfg.gameBoardWidth, cfg.piecePromotionPanelCfg.gameBoatdHeight)){
		std::cerr<<"_piecePromotionPanel.init() failed.\n";
		return EXIT_FAILURE;
	}

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
	_inputInverter.invertEvent(event);
	if(_piecePromotionPanel.isActive()){
		_piecePromotionPanel.handleEvent(event);
		return;
	}
	_pieceHandler.handleEvent(event);
}
void Game::promotePiece(PieceType pieceType){
	std::cout<<"Received piecePromotion for pieceType: "<<static_cast<int32_t>(pieceType)<<"\n";
	_pieceHandler.piecePromotion(pieceType);
}
void Game::finishTurn(){
	_gameBoardAnim.startAnim(_gameLogic.getActivePlayerId());
}
void Game::onPawnPromotion() {
	_piecePromotionPanel.activate(_gameLogic.getActivePlayerId());
}
void Game::onBoardAnimFinished(){
	_gameLogic.finishTurn();
	_pieceHandler.setCurrPlayerId(_gameLogic.getActivePlayerId());
}
void Game::setWidgetFlip([[maybe_unused]]WidgetFlip flipType) {
	//_pieceHandler.setWidgetFlip(flipType);
	_inputInverter.setBoardFlipType(flipType);
}
