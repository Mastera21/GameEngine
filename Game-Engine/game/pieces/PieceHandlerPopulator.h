#ifndef GAME_PIECES_PIECEHANDLERPOPULATOR_H_
#define GAME_PIECES_PIECEHANDLERPOPULATOR_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <array>
#include <vector>
#include <memory>
//Other libraries headers

//Own components headers
#include "game/pieces/types/ChessPiece.h"
//Forward declarations

using PlayerPieces = std::vector<std::unique_ptr<ChessPiece>>;

class PieceHandlerPopulator {
public:
	PieceHandlerPopulator() = delete;
	~PieceHandlerPopulator() = default;

	static int32_t init(int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId, int32_t unfinishedPieceFontId, std::array<PlayerPieces,Defines::PLAYERS_COUNT>& outPieces);
};

#endif /* GAME_PIECES_PIECEHANDLERPOPULATOR_H_ */
