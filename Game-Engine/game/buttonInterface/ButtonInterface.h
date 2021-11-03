#ifndef GAME_BUTTONINTERFACE_BUTTONINTERFACE_H_
#define GAME_BUTTONINTERFACE_BUTTONINTERFACE_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers

//Forward declarations

class ButtonInterface {
public:
  virtual ~ButtonInterface() = default;
  virtual void onButtonPressed(int32_t buttonId) = 0;
};

#endif /* GAME_BUTTONINTERFACE_BUTTONINTERFACE_H_ */
