#include "game/pieces/PieceHandlerPopulator.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/pieces/types/UnfinishedPiece.h"
namespace{
constexpr auto STARTING_PIECES_COUNT = 16;
constexpr auto PAWNS_COUNT = 8;

constexpr auto WHITE_PLAYER_START_PAWN_ROW = 6;
constexpr auto BLACK_PLAYER_START_PAWN_ROW = 1;

int32_t populateWhitePieces(int32_t rsrcId, int32_t unfinishedPieceFontId, ChessPiece::PlayerPieces& white){
	white.reserve(STARTING_PIECES_COUNT);

	for(auto i = 0; i < STARTING_PIECES_COUNT; ++i){
		white.push_back(std::make_unique<UnfinishedPiece>());
	}

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = WHITE_PLAYER_START_PAWN_ROW;
	pieceCfg.playerId = Defines::WHITE_PLAYER_ID;
	pieceCfg.rsrcId = rsrcId;
	pieceCfg.pieceType = PieceType::PAWN;
	pieceCfg.unfinishedPieceFontId = unfinishedPieceFontId;

	for(auto i = 0; i < PAWNS_COUNT; ++i){
		pieceCfg.boardPos.col = i;
		if(EXIT_SUCCESS != white[i]->init(pieceCfg)){
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
		if(EXIT_SUCCESS != white[i]->init(pieceCfg)){
			std::cerr<<"Error, _piece.init() -> white, failed\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
int32_t populateBlackPieces(int32_t rsrcId, int32_t unfinishedPieceFontId, ChessPiece::PlayerPieces& black){
	black.reserve(STARTING_PIECES_COUNT);

	for(auto i = 0; i < STARTING_PIECES_COUNT; ++i){
		black.push_back(std::make_unique<UnfinishedPiece>());
	}

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = BLACK_PLAYER_START_PAWN_ROW;
	pieceCfg.playerId = Defines::BLACK_PLAYER_ID;
	pieceCfg.rsrcId = rsrcId;
	pieceCfg.pieceType = PieceType::PAWN;
	pieceCfg.unfinishedPieceFontId = unfinishedPieceFontId;

	for(auto i = 0; i < PAWNS_COUNT; ++i){
		pieceCfg.boardPos.col = i;
		if(EXIT_SUCCESS != black[i]->init(pieceCfg)){
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
		if(EXIT_SUCCESS != black[i]->init(pieceCfg)){
			std::cerr<<"Error, _piece.init() -> black, failed\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
}

int32_t PieceHandlerPopulator::init(int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId, int32_t unfinishedPieceFontId,
									std::array<ChessPiece::PlayerPieces,Defines::PLAYERS_COUNT>& outPieces){
	auto& white = outPieces[Defines::WHITE_PLAYER_ID];
	if(EXIT_SUCCESS != populateWhitePieces(whitePiecesRsrcId, unfinishedPieceFontId, white)){
		std::cerr<<"Error, populateWhitePieces() failed.\n";
		return EXIT_FAILURE;
	}
	auto& black = outPieces[Defines::BLACK_PLAYER_ID];
	if(EXIT_SUCCESS != populateBlackPieces(blackPiecesRsrcId, unfinishedPieceFontId, black)){
		std::cerr<<"Error, populateBlackPieces() failed.\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


