
#include "game/panels/buttons/PiecePromotionButton.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"

int32_t PiecePromotionButton::init(const PiecePromotionButtonCfg &cfg){
	_cfg = cfg;
	_bgrImg.create(cfg.buttonBgrRsrcId, cfg.bgrPos);

	return EXIT_SUCCESS;
}
void PiecePromotionButton::draw() {
	_bgrImg.draw();
	ButtonBase::draw();
}
void PiecePromotionButton::handleEvent(const Event& e) {
	if(e.type == TouchEvent::TOUCH_RELEASE){
		_cfg.onBtnClicked(_cfg.pieceType);
	}
}
void PiecePromotionButton::activate(int32_t activePlayerId){
	const auto rsrcId = (activePlayerId == Defines::WHITE_PLAYER_ID) ? _cfg.buttonWhitePieceRsrcId : _cfg.buttonBlackPieceRsrcId;

	const int32_t X_Y_DELTA = (_bgrImg.getWidth() - _cfg.width) / 2;
	const Point btnPos = Point(_bgrImg.getX() + X_Y_DELTA, _bgrImg.getY() + X_Y_DELTA);

	ButtonBase::create(rsrcId, btnPos);
	setFrame(static_cast<int32_t>(_cfg.pieceType));
}
