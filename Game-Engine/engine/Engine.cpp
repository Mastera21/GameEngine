
#include "Engine.h"

//C system headers

//C++ system headers

#include <iostream>
#include <cstring>

//Other libraries headers
#include <iostream>

//Own components headers
#include "engine/config/EngineConfig.h"

int32_t Engine::init(const EngineConfig& cfg){

	if(EXIT_SUCCESS != _window.init(cfg.windowCfg)){
		std::cerr<<"window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _event.init()){
		std::cerr<<"_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void Engine::deinit(){
	_event.deinit();
	_window.deinit();
}
void Engine::start(){
	//TODO
}

void Engine::mainLoop(){
	//TODO
}
void Engine::drawFrame(){
	//TODO
}
bool Engine::processFrame(){
	//TODO
	return true;
}
void Engine::handleEvent(){
	//TODO
}
void Engine::limitFPS(int64_t elapsedTimeMicroSeconds){
	//TODO
}
