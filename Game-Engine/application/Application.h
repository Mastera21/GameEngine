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
	int32_t init();
	void draw();
	void deinit();
};

#endif /* APPLICATION_APPLICATION_H_ */
