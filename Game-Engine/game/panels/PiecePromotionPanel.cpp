
#include "game/panels/PiecePromotionPanel.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/interfaces/GameInterface.h"
#include "sdl/Event.h"

int32_t PiecePromotionPanel::init([[maybe_unused]]const PiecePromotionPanelCfg& cfg, [[maybe_unused]]GameInterface* gameInterface){
	//TODO

	return EXIT_SUCCESS;
}
void PiecePromotionPanel::handleEvent([[maybe_unused]]const Event& e){
	/*for(const auto& i : _promotionBtns){
		if(i.isUnlocked()){

		}
	}*/

	//TODO
}
void PiecePromotionPanel::draw(){
	for(auto& i : _promotionBtns){
		i.draw();
	}
}
void PiecePromotionPanel::activate([[maybe_unused]]int32_t playerId){
	//TODO
}
bool PiecePromotionPanel::isActive() const{
	return _isActive;
}
