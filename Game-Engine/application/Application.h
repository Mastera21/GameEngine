#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

//Other libraries headers


//Own components headers
#include "sdl/config/MonitorWindowCfg.h"
#include "sdl/MonitorWindow.h"


//Forward declarations
struct SDL_Window;
struct SDL_Surface;

class Application {
public:
	void run();

private:

	SDL_Window* _window = nullptr;
	SDL_Surface* _screenSurface = nullptr;
	SDL_Surface* _image = nullptr;


	int32_t loadResources();
	int32_t init(MonitorWindow& window);
	void draw(MonitorWindow& window);
	void deinit(MonitorWindow& window);
};

#endif /* APPLICATION_APPLICATION_H_ */
