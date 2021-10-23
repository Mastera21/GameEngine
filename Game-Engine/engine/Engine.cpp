
#include "Engine.h"

//C system headers

//C++ system headers

#include <iostream>
#include <cstring>

//Other libraries headers

//Own components headers
#include "engine/config/EngineConfig.h"
#include "utils/time/Time.h"
#include "utils/thread/ThreadUtils.h"
#include "sdl/Texture.h"


int32_t Engine::init(const EngineConfig& cfg){

	if(EXIT_SUCCESS != _window.init(cfg.windowCfg)){
		std::cerr<<"window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _render.init(_window.getWindow())){
		std::cerr<<"_render.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _imgContainer.init(cfg.imageContainerCfg)){
		std::cerr<<"_imgContainer.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _textContainer.init(cfg.textContainerCfg)){
		std::cerr<<"_textContainer.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _event.init()){
		std::cerr<<"_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _game.init(cfg.gameCfg, &_imgContainer)){
		std::cerr<<"_game.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit(){
	_game.deinit();
	_event.deinit();
	_imgContainer.deinit();
	_textContainer.deinit();
	_render.deinit();
	_window.deinit();
}

void Engine::main(){
	Time time;

	while(true){
		time.getElapsed();
		const bool wantToExit = processFrame();
		if(wantToExit){
			break;
		}

		limitFPS(time.getElapsed().toMicroseconds());
	}

}
void Engine::drawFrame(){
	_render.clearScreen();
	std::vector<DrawParams> images;
	_game.draw(images);

	//This is for images.
	SDL_Texture* texture = nullptr;
	for(const DrawParams& i : images){
		texture = _imgContainer.getImageTexture(i.rsrcId);
		_render.renderTexture(texture, i);
	}

	_render.finishFrame();

}
bool Engine::processFrame(){
	while(_event.pollEvent()){
		if(_event.checkForExitRequest()){
			return true;
		}
		handleEvent();
	}
	//-----------------------Drawing -----------------------
	drawFrame();
	return false;
}
void Engine::handleEvent(){
	_game.handleEvent(_event);
}
void Engine::limitFPS(int64_t elapsedTimeMicroSeconds){
	constexpr auto maxFrames = 60;
	constexpr auto microSecondsInASecond = 1000000;
	constexpr auto microSecondsPerFrame = microSecondsInASecond / maxFrames;
	const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;
	if(sleepDurationMicroSeconds > 0){
		Threading::sleepFor(sleepDurationMicroSeconds);
	}
}

