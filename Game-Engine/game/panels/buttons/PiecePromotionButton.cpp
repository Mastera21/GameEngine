
#include "game/panels/buttons/PiecePromotionButton.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers

int32_t PiecePromotionButton::init([[maybe_unused]]const PiecePromotionButtonCfg &cfg){

	return EXIT_SUCCESS;
}
void PiecePromotionButton::draw() {
	//_bgrImg.draw();
}
void PiecePromotionButton::handleEvent([[maybe_unused]]const Event& e) {
	//_bgrImg.setPos(e.pos);
}
void PiecePromotionButton::activate([[maybe_unused]]int32_t activePlayerId){
	//_bgrImg.create(activePlayerId, Point(20,20));
}
