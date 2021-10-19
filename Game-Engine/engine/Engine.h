#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "SDL.h"

#include "sdl/Event.h"
#include "sdl/MonitorWindow.h"

//Forward declarations
struct EngineConfig;

class Engine {
public:
	int32_t init(const EngineConfig& cfg);
	void deinit();
	void start();

private:
	MonitorWindow _window;
	Event _event;
	SDL_Surface* _screenSurface = nullptr;

	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();
	void limitFPS(int64_t elapsedTimeMicroSeconds);
};

#endif /* ENGINE_ENGINE_H_ */
