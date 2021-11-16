#include "game/pieces/PieceHandler.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "game/utils/BoardUtils.h"
#include "game/interfaces/GameInterface.h"
#include "game/interfaces/GameBoardInterface.h"

int32_t PieceHandler::init(GameBoardInterface* gameBoardInterface, GameInterface* gameInterface, int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId, int32_t unfinishedPieceFontId){

	if(gameBoardInterface == nullptr){
		std::cerr<<"Error, gameBoardInterface is nullptr in PieceHandler.cpp\n";
		return EXIT_FAILURE;
	}
	_gameBoardInterface = gameBoardInterface;

	if(gameInterface == nullptr){
		std::cerr<<"Error, gameInterface is nullptr in PieceHandler.cpp\n";
		return EXIT_FAILURE;
	}
	_gameInterface = gameInterface;

	if(EXIT_SUCCESS != PieceHandlerPopulator::init(_gameInterface, whitePiecesRsrcId, blackPiecesRsrcId, unfinishedPieceFontId, _pieces)){
		std::cerr<<"Error, PieceHandlerPopulator::init -> PieceHandler.cpp\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void PieceHandler::draw(){
	for(auto& i : _pieces){
		for(auto& piece : i){
			piece->draw();
		}
	}
}

void PieceHandler::piecePromotion([[maybe_unused]]PieceType pieceType){
	//TODO
}

void PieceHandler::handleEvent(const Event& event){
	_isPieceGrabbed ? handlePieceGrabbedEvent(event) : handlePieceUngrabbedEvent(event);
}
void PieceHandler::setCurrPlayerId(int32_t currPlayerId){
	_currPlayerId = currPlayerId;
}
void PieceHandler::handlePieceGrabbedEvent(const Event& event){
	if(event.type != TouchEvent::TOUCH_RELEASE){
		return;
	}
	_isPieceGrabbed = false;

	if(!BoardUtils::isInsideBoard(event.pos)){
		_gameBoardInterface->onPieceUngrabbed();
		return;
	}

	const BoardPos boardPos = BoardUtils::getBoardPos(event.pos);
	if(!_gameBoardInterface->isMoveAllowed(boardPos)){
		_gameBoardInterface->onPieceUngrabbed();
		return;
	}

	doMovePiece(boardPos);
}
void PieceHandler::handlePieceUngrabbedEvent(const Event& event){
	if(event.type != TouchEvent::TOUCH_RELEASE){
		return;
	}
	int32_t relativePieceid = 0;
	for(const auto& piece : _pieces[_currPlayerId]){
		if(piece->selectFigure(event)){
			_selectedPieceId = relativePieceid;
			_isPieceGrabbed = true;

			const auto moveTile = _pieces[_currPlayerId][_selectedPieceId]->getMoveTiles(_pieces);
			_gameBoardInterface->onPieceGrabbed(BoardUtils::getBoardPos(event.pos), moveTile);
			return;
		}
		++relativePieceid;
	}
}
void PieceHandler::doMovePiece(const BoardPos& boardPos){
	_pieces[_currPlayerId][_selectedPieceId]->setBoardPos(boardPos);
	const auto opponrntId = BoardUtils::getOpponentId(_pieces[_currPlayerId][_selectedPieceId]->getPlayerId());
	int32_t collisionIndex = -1;
	if(BoardUtils::doCollideWithPiece(boardPos, _pieces[opponrntId], collisionIndex)){
		_pieces[opponrntId].erase(_pieces[opponrntId].begin() + collisionIndex);
	}

	_gameBoardInterface->onPieceUngrabbed();
	_gameInterface->finishTurn();
}
void PieceHandler::setWidgetFlip(WidgetFlip flipType){
	for(auto& playerpieces : _pieces){
		for(auto& pieces : playerpieces){
			pieces->setWidgetFlip(flipType);
		}
	}
}
