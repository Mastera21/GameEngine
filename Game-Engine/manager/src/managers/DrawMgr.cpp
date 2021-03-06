#include "manager/managers/DrawMgr.h"

//C system headers

//C++ system headers

#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/config/DrawMgrCfg.h"
#include "manager/managers/RsrcMgr.h"

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
	_maxFrames = cfg.maxFrameRate;
	return EXIT_SUCCESS;
}

int64_t DrawMgr::getMaxFrams() const{
	return _maxFrames;
}

int32_t DrawMgr::getActiveWidgets() const{
	return _render.getActiveWidgets();
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

void DrawMgr::addDrawCmd(const DrawParams& drawParams){
	SDL_Texture* texture = getTextureinternal(drawParams);
	_render.renderTexture(texture, drawParams);
}

SDL_Texture* DrawMgr::getTextureinternal(const DrawParams& drawParams) const{
	//This is for images.
	if(WidgetType::IMAGE == drawParams.widgetType){
		return gRsrcMgr->getImageTexture(drawParams.rsrcId);
	}else if(WidgetType::TEXT == drawParams.widgetType){
		return gRsrcMgr->getTextTexture(drawParams.textId);
	}else if(WidgetType::FBO == drawParams.widgetType){
		return gRsrcMgr->getFboTexture(drawParams.fboId);
	}else{
		std::cerr<<"Error, received unsupported WidgetType: "<<static_cast<int32_t>(drawParams.widgetType)
				<<" for rsrcId: "<<drawParams.textId<<"\n";
	}
	return nullptr;
}

void DrawMgr::setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode){
	SDL_Texture* texture = getTextureinternal(drawParams);
	_render.setWidgetBlendMode(texture, blendMode);
}

void DrawMgr::setWidgetOpacity(const DrawParams& drawParams, int32_t opacity){
	if(drawParams.widgetType == WidgetType::IMAGE){
		return;
	}

	SDL_Texture* texture = getTextureinternal(drawParams);
	_render.setWidgetOpacity(texture, opacity);
}

int32_t DrawMgr::clearCurrentRendererTarget(const Color& color){
	return _render.clearCurrentRendererTarget(color);
}

int32_t DrawMgr::setRendererTarget(int32_t fboId){
	SDL_Texture* fboTexture = gRsrcMgr->getFboTexture(fboId);
	return _render.setRendererTarget(fboTexture);
}

int32_t DrawMgr::resetRendererTarget(){
	return _render.resetRendererTarget();
}

int32_t DrawMgr::lockRenderer(){
	return _render.lockRenderer();
}

int32_t DrawMgr::unlockRenderer(){
	return _render.unlockRenderer();
}

