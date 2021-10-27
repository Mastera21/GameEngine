#include "manager/managers/DrawMgr.h"

//C system headers

//C++ system headers

#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/config/DrawMgrCfg.h"

DrawMgr *gDrawMgr = nullptr;

int32_t DrawMgr::init(const DrawMgrCfg& cfg){

	if(EXIT_SUCCESS != _window.init(cfg.windowCfg)){
		std::cerr<<"window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _render.init(_window.getWindow())){
		std::cerr<<"_render.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void DrawMgr::deinit(){
	_render.deinit();
	_window.deinit();
}
void DrawMgr::process(){

}

void DrawMgr::clearScreen(){
	_render.clearScreen();
}

void DrawMgr::finishFrame(){
	_render.finishFrame();
}

void DrawMgr::addDrawCmd(const DrawParams& drawParams, SDL_Texture* text){
	_render.renderTexture(text, drawParams);
}
