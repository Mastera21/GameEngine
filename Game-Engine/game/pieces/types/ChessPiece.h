#ifndef GAME_PIECES_TYPES_CHESSPIECE_H_
#define GAME_PIECES_TYPES_CHESSPIECE_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
#include <memory>
//Other libraries headers

//Own components headers
#include "game/defines/ChessDefines.h"
#include "game/defines/ChessStructs.h"
#include "game/utils/BoardPos.h"
#include "manager/drawing/Image.h"

struct ChessPieceCfg{
	BoardPos boardPos {};
	int32_t playerId {};
	int32_t rsrcId = INVALID_RSRC_ID;
	PieceType pieceType = PieceType::UNKNOWN;

	int32_t unfinishedPieceFontId;
};

//Forward declarations
struct Event;

class ChessPiece {
public:
	using PlayerPieces = std::vector<std::unique_ptr<ChessPiece>>;

    virtual ~ChessPiece() = default;

	virtual int32_t init(const ChessPieceCfg& cfg);
	virtual void draw();
	virtual void setBoardPos(const BoardPos& pos);
	virtual std::vector<TileData> getMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const = 0;

	BoardPos getBoardPos() const;
	int32_t getPlayerId() const;
	int32_t getRsrcId() const;

	bool selectFigure(const Event& event) const;
	void setWidgetFlip(WidgetFlip flipType);

protected:
	Image _pieceImg;
	BoardPos _boardPos;
	int32_t _playerId;
	PieceType _pieceType;
};
#endif /* GAME_PIECES_TYPES_CHESSPIECE_H_ */
