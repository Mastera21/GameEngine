#ifndef SDL_SDLLOADER_H_
#define SDL_SDLLOADER_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers


//Own components headers


//Forward declarations

class SDLLoader {
	//We are using this class like interface only for functions nothing else.
public:
	SDLLoader();
	virtual ~SDLLoader();

	static int32_t init();
	static void deinit();

};

#endif /* SDL_SDLLOADER_H_ */
