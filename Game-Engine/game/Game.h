#ifndef GAME_GAME_H_
#define GAME_GAME_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "manager/drawing/Image.h"
#include "manager/drawing/Text.h"
#include "manager/drawing/Fbo.h"
#include "game/board/GameBoard.h"
#include "game/board/boardAnim/GameBoardAnim.h"
#include "game/pieces/PieceHandler.h"
#include "game/logic/GameLogic.h"
#include "game/interfaces/GameInterface.h"
#include "game/panels/PiecePromotionPanel.h"
#include "game/movesPlayersId/MovePlayersId.h"


//Forward declarations
struct Event;

class Game : public GameInterface{
public:
	int32_t init(const GameCfg cfg);
	void deinit();
	void draw();
	void handleEvent(Event& event);

private:
	GameBoard _board;
	PieceHandler _pieceHandler;
	GameLogic _gameLogic;
	PiecePromotionPanel _piecePromotionPanel;
	GameBoardAnim _gameBoardAnim;
	MovePlayersId _movePlayersId;
	FBO _gameFbo;

	void finishTurn() final;
	void onPawnPromotion() final;
	void promotePiece(PieceType pieceType) final;
	void onBoardAnimFinished() final;
	void regenerateGameFbo();

	bool _isPromotionActive = false;
};

#endif /* GAME_GAME_H_ */
