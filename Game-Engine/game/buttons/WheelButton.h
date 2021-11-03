#ifndef GAME_BUTTONS_WHEELBUTTON_H_
#define GAME_BUTTONS_WHEELBUTTON_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "manager/buttonBase/ButtonBase.h"
#include "game/buttonInterface/ButtonInterface.h"
#include "sdl/Event.h"
//Forward declarations
class ButtonInterface;

class WheelButton : public ButtonBase{
public:
	int32_t init(ButtonInterface* gameProxy, int32_t buttonId);

	void handleEvent(const sd::Event &e) final;
private:
	ButtonInterface* _gameProxy = nullptr;
	int32_t _buttonId { 0 };
};

#endif /* GAME_BUTTONS_WHEELBUTTON_H_ */
