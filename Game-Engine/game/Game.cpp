
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

	if(EXIT_SUCCESS != _movePlayersId.init(cfg.textId)){
		std::cerr<<"_movePlayersId.init() failed.\n";
		return EXIT_FAILURE;
	}

	_gameFbo.create(cfg.piecePromotionPanelCfg.gameBoardWidth, cfg.piecePromotionPanelCfg.gameBoatdHeight, Point::ZERO, Colors::FULL_TRANSPARENT);
	_gameFbo.activateAlphaModulation();
	regenerateGameFbo();

	return EXIT_SUCCESS;
}
void Game::deinit(){

}
void Game::draw(){
	_gameFbo.draw();
	//_pieceHandler.draw();
	_board.draw();
	_piecePromotionPanel.draw();
	_movePlayersId.draw();
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
	_isPromotionActive = false;
	onBoardAnimFinished();
}
void Game::finishTurn(){
	regenerateGameFbo();
	_gameBoardAnim.startAnim(_gameLogic.getActivePlayerId());
	if(Defines::WHITE_PLAYER_ID == _gameLogic.getActivePlayerId()){
		_movePlayersId.updatePlayerText(_gameLogic.getActivePlayerId());
	}
	_movePlayersId.updatePlayerText(_gameLogic.getActivePlayerId());
	
}
void Game::onPawnPromotion() {
	regenerateGameFbo();
	_isPromotionActive = true;
	_piecePromotionPanel.activate(_gameLogic.getActivePlayerId());
}
void Game::onBoardAnimFinished(){
	if(_isPromotionActive){
		return;
	}
	_gameLogic.finishTurn();
	_pieceHandler.setCurrPlayerId(_gameLogic.getActivePlayerId());
	regenerateGameFbo();
}
void Game::regenerateGameFbo() {
  _gameFbo.unlock();
  _gameFbo.reset();

  _board.drawGameBoardFbo(_gameFbo);
  _pieceHandler.drawOnFbo(_gameFbo);

  _gameFbo.update();
  _gameFbo.lock();
}

