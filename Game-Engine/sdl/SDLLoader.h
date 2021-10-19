#ifndef SDL_SDLLOADER_H_
#define SDL_SDLLOADER_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers

//Forward declarations

class SDLLoader {
public:
  //forbid the default constructor
  SDLLoader() = delete;

  static int32_t init();

  static void deinit();
};

#endif /* SDL_SDLLOADER_H_ */
