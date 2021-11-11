#ifndef GAME_PIECES_PIECEHANDLER_H_
#define GAME_PIECES_PIECEHANDLER_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <array>
#include <vector>
//Other libraries headers

//Own components headers
#include "game/defines/ChessDefines.h"
#include "game/pieces/types/ChessPiece.h"
#include "game/pieces/PieceHandlerPopulator.h"
//Forward declarations
struct Event;
struct GameBoardInterface;

class PieceHandler {
public:
	int32_t init(GameBoardInterface* gameBoardInterface, int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId);
	void draw();
	void handleEvent(const Event& event);

private:
	using PlayerPieces = std::vector<ChessPiece>;
	std::array<PlayerPieces, Defines::PLAYERS_COUNT> _pieces;

	GameBoardInterface* _gameBoardInterface = nullptr;

	int32_t _selectedPieceId = 0;
	int32_t _selectedPiecePlayerId = 0;
	bool _isPieceGrabbed = false;

	void handlePieceGrabbedEvent(const Event& event);
	void handlePieceUngrabbedEvent(const Event& event);
};

#endif /* GAME_PIECES_PIECEHANDLER_H_ */
