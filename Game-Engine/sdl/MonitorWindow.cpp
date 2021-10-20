#include "MonitorWindow.h"

#include <iostream>

#include "SDL_video.h"

int32_t sd::MonitorWindow::init(const MonitorWindowCofg& cfg){
	Point finalPos;
	if(cfg.windowPos == Point::UNDEFINED){
		finalPos.x = SDL_WINDOWPOS_UNDEFINED;
		finalPos.y = SDL_WINDOWPOS_UNDEFINED;
	}else{
		finalPos = cfg.windowPos;
	}

	_window = SDL_CreateWindow(cfg.windowName.c_str(), finalPos.x, finalPos.y, cfg.windowWidth,  cfg.windowHeight, cfg.windowFlags);

	if(_window == nullptr){
		std::cerr<<"SDL_CreateWindow() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void sd::MonitorWindow::deinit(){
	if(_window != nullptr){
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
}

sd::MonitorWindow::~MonitorWindow(){
	deinit();
}

void sd::MonitorWindow::updateWindowSurface(){
	if(EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)){
		std::cerr<<"SDL_UpdateWindowSurface() failed. Reason: "<< SDL_GetError() << "\n";
	}
}

SDL_Window* sd::MonitorWindow::getWindow(){
	return _window;
}

