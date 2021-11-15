#ifndef GAME_PANELS_PIECEPROMOTIONPANEL_H_
#define GAME_PANELS_PIECEPROMOTIONPANEL_H_
//C system headers

//C++ system headers
#include <cstdint>
#include <array>
//Other libraries headers

//Own components headers
#include "game/panels/buttons/PiecePromotionButton.h"
#include "game/panels/config/PiecePromotionPanelCfg.h"
//Forward declarations
class GameInterface;
class Event;

class PiecePromotionPanel {
public:
	int32_t init(const PiecePromotionPanelCfg& cfg, GameInterface* gameInterface);
	void handleEvent(const Event& e);
	void draw();
	void activate(int32_t playerId);
	bool isActive() const;
private:
	enum InternalDefines {
		BUTTONS_COUNT = 4
	};
	std::array<PiecePromotionButton, BUTTONS_COUNT> _promotionBtns;
	GameInterface* _gameInterface = nullptr;
	bool _isActive = false;
};
#endif /* GAME_PANELS_PIECEPROMOTIONPANEL_H_ */
