#ifndef SDL_EVENT_H_
#define SDL_EVENT_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "utils/input/EventDefines.h"
#include "utils/drawing/Point.h"

//Forward declarations
union SDL_Event;

namespace sd{

class Event {
public:
  int32_t init();
  void deinit();
  bool pollEvent();
  bool checkForExitRequest() const;

  /* Holds event position on the screen */
  Point pos = Point::UNDEFINED;

  /* See EventDefines.h for more information */
  int32_t key = Keyboard::KEY_UNKNOWN;
  uint8_t mouseButton = Mouse::UNKNOWN;
  TouchEvent type = TouchEvent::UNKNOWN;

private:
  void setEventTypeInternal();

  /** Holds the OS communication event system */
  SDL_Event *_sdlEvent = nullptr;

};
}

#endif /* SDL_EVENT_H_ */
