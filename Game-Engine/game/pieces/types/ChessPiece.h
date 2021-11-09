#ifndef GAME_PIECES_TYPES_CHESSPIECE_H_
#define GAME_PIECES_TYPES_CHESSPIECE_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/utils/BoardPos.h"
#include "game/defines/ChessDefines.h"
#include "manager/drawing/Image.h"

struct ChessPieceCfg{
	BoardPos boardPos {};
	int32_t playerId {};
	int32_t rsrcId = INVALID_RSRC_ID;
	PieceType pieceType = PieceType::UNKNOWN;
};

//Forward declarations
struct Event;

class ChessPiece {
public:
	int32_t init(const ChessPieceCfg& cfg);
	void draw();
	bool selectFigure(const Event& event) const;

	BoardPos getBoardPos() const;
	void setBoardPos(const BoardPos& pos);

	int32_t getPlayerId() const;

private:
	Image _pieceImg;
	BoardPos _boardPos;
	int32_t _playerId;
	PieceType _pieceType;
};
#endif /* GAME_PIECES_TYPES_CHESSPIECE_H_ */
