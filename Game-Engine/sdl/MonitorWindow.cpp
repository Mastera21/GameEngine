#include "MonitorWindow.h"

//C system headers

//C++ system headers
#include <stdint.h>
#include <iostream>
//Other libraries headers
#include <SDL_video.h>

//Own components headers


int32_t MonitorWindow::init(const MonitorWindowCofg& cfg){
	Point filanPos;
	if(cfg.windowPos == Point::UNDEFINED){
		filanPos.x = SDL_WINDOWPOS_UNDEFINED;
		filanPos.y = SDL_WINDOWPOS_UNDEFINED;
	}else {
		filanPos = cfg.windowPos;
	}

	_window = SDL_CreateWindow(cfg.windowName.c_str(), cfg.windowPos.x, cfg.windowPos.y, cfg.width, cfg.height, cfg.flag);

	if(_window == nullptr){
		std::cerr<<"SDL_CreateWindow() failed. "<<SDL_GetError()<<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void MonitorWindow::deinit(){
	if(_window != nullptr){
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
}
SDL_Surface* MonitorWindow::getWindowSurface(){
	SDL_Surface* _surface = SDL_GetWindowSurface(_window);

	if(_surface == nullptr){
		std::cerr<<"SDL_GetWindowSurface() failed. "<<SDL_GetError()<<"\n";
		return nullptr;
	}
	return _surface;
}
MonitorWindow::~MonitorWindow(){
	deinit();
}

void MonitorWindow::updateWindowSurface(){
	if(EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)){
		std::cerr<<"SDL_UpdateWindowSurface(_window) failed. "<<SDL_GetError()<<"\n";
	}
}

