
#include "Engine.h"

//C system headers

//C++ system headers

#include <iostream>
#include <cstring>

//Other libraries headers

//Own components headers
#include "engine/config/EngineConfig.h"
#include "manager/managers/DrawMgr.h"
#include "utils/time/Time.h"
#include "utils/thread/ThreadUtils.h"
#include "sdl/Texture.h"


int32_t Engine::init(const EngineConfig& cfg){

	if(EXIT_SUCCESS != _managerHandler.init(cfg.managerHandlerCfg)){
		std::cerr<<"_managerHandler.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _event.init()){
		std::cerr<<"_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _game.init(cfg.gameCfg)){
		std::cerr<<"_game.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit(){
	_game.deinit();
	_event.deinit();
	_managerHandler.deinit();
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
	gDrawMgr->clearScreen();

	_game.draw();

	gDrawMgr->finishFrame();

}
bool Engine::processFrame(){
	_managerHandler.process();
	_game.process();

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

