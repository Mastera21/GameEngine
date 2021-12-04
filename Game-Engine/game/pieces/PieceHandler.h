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
class GameInterface;
class FBO;

class PieceHandler {
public:
	int32_t init(GameBoardInterface* gameBoardInterface, GameInterface* gameInterface, int32_t whitePiecesRsrcId, int32_t blackPiecesRsrcId, int32_t unfinishedPieceFontId);
	void drawOnFbo(FBO& fbo) const;
	void draw();
	void handleEvent(const Event& event);
	void setCurrPlayerId(int32_t currPlayerId);
	void piecePromotion(PieceType pieceType);

private:
	std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> _pieces;

	GameBoardInterface* _gameBoardInterface = nullptr;
	GameInterface* _gameInterface = nullptr;

	int32_t _selectedPieceId = 0;
	int32_t _currPlayerId = 0;
	bool _isPieceGrabbed = false;

	void doMovePiece(const BoardPos& boardPos);
	void handlePieceGrabbedEvent(const Event& event);
	void handlePieceUngrabbedEvent(const Event& event);
};

#endif /* GAME_PIECES_PIECEHANDLER_H_ */
