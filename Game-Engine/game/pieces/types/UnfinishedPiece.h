#ifndef GAME_PIECES_TYPES_UNFINISHEDPIECE_H_
#define GAME_PIECES_TYPES_UNFINISHEDPIECE_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "game/pieces/types/ChessPiece.h"
#include "manager/drawing/Text.h"
//Forward declarations

class UnfinishedPiece: public ChessPiece {
public:
	int32_t init(const ChessPieceCfg& cfg) final;
	void draw() final;
	void setBoardPos(const BoardPos& pos) final;
private:
	Text _notReadyText;
};

#endif /* GAME_PIECES_TYPES_UNFINISHEDPIECE_H_ */
