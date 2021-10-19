#include "../application/Application.h"

//C system headers

//C++ system headers
#include <stdint.h>

//Other libraries headers
#include "SDL.h"

//Own components headers
#include "sdl/SDLLoader.h"

int32_t Application::loadResources(){
	std::string filePath = "../assets/hello.bmp";
	_image = SDL_LoadBMP(filePath.c_str());

	if(_image == nullptr){
		std::cerr<<"SDL_LoadBMP() failed. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
int32_t Application::init(MonitorWindow& window){

	//TODO


	if(EXIT_SUCCESS != loadResources()){
		std::cerr<<"loadResources() failed. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void Application::draw(MonitorWindow& window){
	SDL_BlitSurface(_image,nullptr,_screenSurface, nullptr);

	window.updateWindowSurface();

	SDL_Delay(3000);
}
void Application::deinit(MonitorWindow& window){
	window.deinit();

	if(_screenSurface != nullptr){
		SDL_FreeSurface(_screenSurface);
		_screenSurface = nullptr;
	}
	SDL_Quit();
}

int32_t runApplication(){
	MonitorWindow window;
	SDL_Surface* image = nullptr;

	if(EXIT_SUCCESS != init(window,image)){
		std::cerr<<"init() failed. "<<SDL_GetError()<<"\n";
	}

	draw(window);
	deinit(window);
	return EXIT_SUCCESS;

}

void Application::run(){
	if(EXIT_SUCCESS != SDLLoader::init()){
		std::cerr<<"SDLLoader::init() failed. "<<SDL_GetError()<<"\n";
	}

	if(EXIT_SUCCESS != runApplication()){
			std::cerr<<"runApplication() failed. "<<SDL_GetError()<<"\n";
	}
}
