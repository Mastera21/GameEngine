#ifndef GAME_PANELS_BUTTONS_PIECEPROMOTIONBUTTON_H_
#define GAME_PANELS_BUTTONS_PIECEPROMOTIONBUTTON_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/panels/config/PiecePromotionButtonCfg.h"
#include "manager/buttonBase/ButtonBase.h"
//Forward declarations

class PiecePromotionButton : public ButtonBase {
public:
	int32_t init(const PiecePromotionButtonCfg& cfg);
	void draw() final;
	void handleEvent(const Event& e) final;
	void activate(int32_t activePlayerId);
private:
	Image _bgrImg;
	PiecePromotionButtonCfg _cfg;
};
#endif /* GAME_PANELS_BUTTONS_PIECEPROMOTIONBUTTON_H_ */
