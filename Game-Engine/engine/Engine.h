#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers
#include "sdl/Event.h"
#include "sdl/MonitorWindow.h"
#include "sdl/Renderer.h"
#include "game/Game.h"


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
	Renderer _render;
	Game _game;

	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();
	void limitFPS(int64_t elapsedTimeMicroSeconds);
};

#endif /* ENGINE_ENGINE_H_ */
