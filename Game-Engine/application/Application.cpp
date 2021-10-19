#include "../application/Application.h"

//C system headers

//C++ system headers
#include <stdint.h>

//Other libraries headers
#include "SDL.h"
#include "sdl/SDLLoader.h"

//Own components headers

int32_t Application::loadResources(){
	std::string filePath = "../assets/hello.bmp";
	_image = SDL_LoadBMP(filePath.c_str());

	if(_image == nullptr){
		std::cerr<<"SDL_LoadBMP() faild. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
int32_t Application::init(){
	if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO)){
		std::cerr<<"SDL_Init() faild. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	const std::string windowName = "Engine";
	const int32_t windowX = 0;
	const int32_t windowY = 0;
	const int32_t windowWidth = 640;
	const int32_t windowHeight = 480;

	_window = SDL_CreateWindow(windowName.c_str(), windowX, windowY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if(_window == nullptr){
		std::cerr<<"SDL_CreateWindow() faild. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	_screenSurface = SDL_GetWindowSurface(_window);

	if(_screenSurface == nullptr){
		std::cerr<<"SDL_GetWindowSurface() faild. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != loadResources()){
		std::cerr<<"loadResources() faild. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void Application::draw(){
	SDL_BlitSurface(_image,nullptr,_screenSurface, nullptr);

	if(EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)){
		std::cerr<<"SDL_UpdateWindowSurface() faild. "<<SDL_GetError()<<"\n";
	}
	SDL_Delay(3000);
}
void Application::deinit(){
	if(_window != nullptr){
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
	if(_screenSurface != nullptr){
		SDL_FreeSurface(_screenSurface);
		_screenSurface = nullptr;
	}
	SDL_Quit();
}

void Application::run(){

	if(EXIT_SUCCESS != SDLLoader::init()){
		std::cerr<<"SDLLoader::init() faild. "<<SDL_GetError()<<"\n";
	}

	if(EXIT_SUCCESS != init()){
		std::cerr<<"init() faild. "<<SDL_GetError()<<"\n";
	}

	draw();
	deinit();
}
