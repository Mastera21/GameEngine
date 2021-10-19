//C system headers

//C++ system headers
#include <cstdint>
#include <iostream>

//Other libraries headers

//Own components headers
#include "engine/Engine.h"
//#include "engine/EngineConfigLoader.h"
#include "sdl/SDLLoader.h"

static int32_t runApplication() {
	Engine app;

	//TODO

	app.start();
	app.deinit();

	return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char *args[]) {

	if(EXIT_SUCCESS != SDLLoader::init()){
		std::cerr<<"SDLLoader::init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != runApplication()){
			std::cerr<<"runApplication() failed" << std::endl;
		return EXIT_FAILURE;
	}

	SDLLoader::deinit();

	return EXIT_SUCCESS;
}
