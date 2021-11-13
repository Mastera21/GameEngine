#include "game/pieces/PieceHandler.h"

//C system headers

//C++ system headers
#include <iostream>

#include "game/interfaces/GameBoardInterface.h"
//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "game/utils/BoardUtils.h"

int32_t PieceHandler::init(GameBoardInterface* gameBoardInterface, int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId, int32_t unfinishedPieceFontId){

	if(gameBoardInterface == nullptr){
		std::cerr<<"Error, gameBoardInterface is nullptr in PieceHandler.cpp\n";
		return EXIT_FAILURE;
	}
	_gameBoardInterface = gameBoardInterface;

	if(EXIT_SUCCESS != PieceHandlerPopulator::init(whitePiecesRsrcId, blackPiecesRsrcId, unfinishedPieceFontId, _pieces)){
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
void PieceHandler::handleEvent(const Event& event){
	_isPieceGrabbed ? handlePieceGrabbedEvent(event) : handlePieceUngrabbedEvent(event);
}
void PieceHandler::handlePieceGrabbedEvent(const Event& event){
	if(event.type != TouchEvent::TOUCH_RELEASE){
		return;
	}

	if(!BoardUtils::isInsideBoard(event.pos)){
		return;
	}

	_isPieceGrabbed = false;
	const BoardPos boardPos = BoardUtils::getBoardPos(event.pos);
	if(!_gameBoardInterface->isMoveAllowed(boardPos)){
		return;
	}

	doMovePiece(boardPos);
}
void PieceHandler::handlePieceUngrabbedEvent(const Event& event){
	if(event.type != TouchEvent::TOUCH_RELEASE){
		return;
	}

	int32_t currPlayerid = Defines::WHITE_PLAYER_ID;
	for(const auto& i : _pieces){
		int32_t relativePieceid = 0;
		for(const auto& piece : i){
			if(piece->selectFigure(event)){
				_selectedPieceId = relativePieceid;
				_selectedPiecePlayerId = currPlayerid;
				_isPieceGrabbed = true;

				const auto moveTile = _pieces[_selectedPiecePlayerId][_selectedPieceId]->getMoveTiles(_pieces);
				_gameBoardInterface->onPieceGrabbed(BoardUtils::getBoardPos(event.pos), moveTile);
				return;
			}
			++relativePieceid;
		}
		++currPlayerid;
	}
}

void PieceHandler::doMovePiece(const BoardPos& boardPos){
	_pieces[_selectedPiecePlayerId][_selectedPieceId]->setBoardPos(boardPos);
	const auto opponrntId = BoardUtils::getOpponentId(_pieces[_selectedPiecePlayerId][_selectedPieceId]->getPlayerId());
	int32_t collisionIndex = -1;
	if(BoardUtils::doCollideWithPiece(boardPos, _pieces[opponrntId], collisionIndex)){
		_pieces[opponrntId].erase(_pieces[opponrntId].begin() + collisionIndex);
	}

	_gameBoardInterface->onPieceUngrabbed();
}
