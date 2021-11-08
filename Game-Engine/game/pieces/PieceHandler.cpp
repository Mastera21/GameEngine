#include "game/pieces/PieceHandler.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers

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
void PieceHandler::handleEvent([[maybe_unused]]const Event& event){

}

int32_t PieceHandler::populateWhitePieces([[maybe_unused]]int32_t rsrcId){
	auto& white = _pieces[Defines::WHITE_PLAYER_ID];
	white.resize(8);

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

	return EXIT_SUCCESS;
}
int32_t PieceHandler::populateBlackPieces([[maybe_unused]]int32_t rsrcId){
	auto& black = _pieces[Defines::BLACK_PLAYER_ID];
	black.resize(8);

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
	return EXIT_SUCCESS;
}

