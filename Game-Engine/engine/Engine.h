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
#include "sdl/containers/ImageContainer.h"
#include "sdl/containers/TextContainer.h"

//Forward declarations
struct EngineConfig;

class Engine {
public:
	int32_t init(const EngineConfig& cfg);
	void deinit();
	void main();

private:
	sd::MonitorWindow _window;
	sd::Event _event;
	Renderer _render;
	ImageContainer _imgContainer;
	TextContainer _textContainer;
	Game _game;

	void drawFrame();
	bool processFrame();
	void handleEvent();
	void limitFPS(int64_t elapsedTimeMicroSeconds);
};

#endif /* ENGINE_ENGINE_H_ */
