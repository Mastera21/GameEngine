#include "Application.h"

//C system headers

//C++ system headers
#include <cstdint>
#include <iostream>

//Other libraries headers

//Own components headers
#include "engine/EngineConfigLoader.h"
#include "sdl/SDLLoader.h"

int32_t Application::init(){

	if(EXIT_SUCCESS != SDLLoader::init()){
		std::cerr<<"SDLLoader::init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _engine.init(EngineConfigLoader::loadConfig())){
		std::cerr<<"EngineConfigLoader::loadConfig() failed" << std::endl;
		return EXIT_FAILURE;
	}

	_engine.main();
	_engine.deinit();

	SDLLoader::deinit();

	return EXIT_SUCCESS;
}

void Application::run(){
	if(EXIT_SUCCESS != init()){
		std::cerr<<"init() failed" << std::endl;
	}
}
