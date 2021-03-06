#ifndef GAME_PIECES_PIECEHANDLERPOPULATOR_H_
#define GAME_PIECES_PIECEHANDLERPOPULATOR_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <array>
//Other libraries headers

//Own components headers
#include "game/pieces/types/ChessPiece.h"
//Forward declarations
class GameInterface;
class PieceHandlerPopulator {
public:
	PieceHandlerPopulator() = delete;
	~PieceHandlerPopulator() = default;

	static std::unique_ptr<ChessPiece> createPiece(PieceType type, GameInterface* gameInterface);

	static int32_t init(
			GameInterface* gameInterface,
			int32_t whitePiecesRsrcId,
			int32_t blackPiecesRsrcId,
			int32_t unfinishedPieceFontId,
			std::array<ChessPiece::PlayerPieces,Defines::PLAYERS_COUNT>& outPieces);
};

#endif /* GAME_PIECES_PIECEHANDLERPOPULATOR_H_ */
