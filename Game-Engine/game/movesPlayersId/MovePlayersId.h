#ifndef GAME_MOVESPLAYERSID_MOVEPLAYERSID_H_
#define GAME_MOVESPLAYERSID_MOVEPLAYERSID_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
//Own components headers
#include "manager/drawing/Text.h"
#include "game/config/GameCfg.h"
//Forward declarations

enum MovesTextId {
	WHITE_PLAYER_ID, BLACK_PLAYER_ID, COUNT_IDS
};

class MovePlayersId {
public:
	int32_t init(int32_t textId);
	void updatePlayerText(int32_t activePlayer);
	void draw();
private:
	Text _movesWhiteText;
	Text _movesBlackText;

	bool _isWhiteOnTurn = false;
};
#endif /* GAME_MOVESPLAYERSID_MOVEPLAYERSID_H_ */
