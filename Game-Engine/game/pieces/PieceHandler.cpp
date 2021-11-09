#include "game/pieces/PieceHandler.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "game/utils/BoardUtils.h"

namespace {
constexpr auto STARTING_PIECES_COUNT = 16;
constexpr auto PAWNS_COUNT = 8;

constexpr auto WHITE_PLAYER_START_PAWN_ROW = 6;
constexpr auto BLACK_PLAYER_START_PAWN_ROW = 1;
};

int32_t PieceHandler::init(int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId){

	if(EXIT_SUCCESS != populateWhitePieces(whitePiecesRsrcId)){
		std::cerr<<"Error, populateWhitePieces() failed.\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != populateBlackPieces(blackPiecesRsrcId)){
		std::cerr<<"Error, populateBlackPieces() failed.\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
void PieceHandler::draw(){
	for(auto& i : _pieces){
		for(auto& piece : i){
			piece.draw();
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
	_pieces[_selectedPiecePlayerId][_selectedPieceId].setBoardPos(boardPos);

	std::cout<<"Piece is released\n";
}
void PieceHandler::handlePieceUngrabbedEvent(const Event& event){
	if(event.type != TouchEvent::TOUCH_RELEASE){
		return;
	}

	int32_t currPlayerid = Defines::WHITE_PLAYER_ID;
	for(const auto& i : _pieces){
		int32_t relativePieceid = 0;
		for(const auto& piece : i){
			if(piece.selectFigure(event)){
				_selectedPieceId = relativePieceid;
				_selectedPiecePlayerId = currPlayerid;
				_isPieceGrabbed = true;
				std::cout<<"Piece is grabbed\n";
				return;
			}
			++relativePieceid;
		}
		++currPlayerid;
	}
}
int32_t PieceHandler::populateWhitePieces(int32_t rsrcId){
	auto& white = _pieces[Defines::WHITE_PLAYER_ID];
	white.resize(STARTING_PIECES_COUNT);

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = WHITE_PLAYER_START_PAWN_ROW;
	pieceCfg.playerId = Defines::WHITE_PLAYER_ID;
	pieceCfg.rsrcId = rsrcId;
	pieceCfg.pieceType = PieceType::PAWN;

	for(auto i = 0; i < PAWNS_COUNT; ++i){
		pieceCfg.boardPos.col = i;
		if(EXIT_SUCCESS != white[i].init(pieceCfg)){
			std::cerr<<"Error, _piece.init() -> white, failed\n";
			return EXIT_FAILURE;
		}
	}

	constexpr auto nonPawnCount = PAWNS_COUNT;
	constexpr PieceType nonPownTypes[nonPawnCount] = {
		PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
		PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK
	};

	pieceCfg.boardPos.row = WHITE_PLAYER_START_PAWN_ROW + 1;
	for(auto i = nonPawnCount; i < STARTING_PIECES_COUNT; ++i){
		pieceCfg.boardPos.col = i - nonPawnCount;
		pieceCfg.pieceType = nonPownTypes[i - nonPawnCount];
		if(EXIT_SUCCESS != white[i].init(pieceCfg)){
			std::cerr<<"Error, _piece.init() -> white, failed\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
int32_t PieceHandler::populateBlackPieces(int32_t rsrcId){
	auto& black = _pieces[Defines::BLACK_PLAYER_ID];
	black.resize(STARTING_PIECES_COUNT);

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = BLACK_PLAYER_START_PAWN_ROW;
	pieceCfg.playerId = Defines::BLACK_PLAYER_ID;
	pieceCfg.rsrcId = rsrcId;
	pieceCfg.pieceType = PieceType::PAWN;

	for(auto i = 0; i < PAWNS_COUNT; ++i){
		pieceCfg.boardPos.col = i;
		if(EXIT_SUCCESS != black[i].init(pieceCfg)){
			std::cerr<<"Error, _piece.init() -> black, failed\n";
			return EXIT_FAILURE;
		}
	}

	constexpr auto nonPawnCount = PAWNS_COUNT;
	constexpr PieceType nonPownTypes[nonPawnCount] = {
			PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
			PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK
	};

	pieceCfg.boardPos.row = BLACK_PLAYER_START_PAWN_ROW - 1;
	for(auto i = nonPawnCount; i < STARTING_PIECES_COUNT; ++i){
		pieceCfg.boardPos.col = i - nonPawnCount;
		pieceCfg.pieceType = nonPownTypes[i - nonPawnCount];
		if(EXIT_SUCCESS != black[i].init(pieceCfg)){
			std::cerr<<"Error, _piece.init() -> black, failed\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

