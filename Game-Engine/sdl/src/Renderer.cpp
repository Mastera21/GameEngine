#include "sdl/Renderer.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "SDL_render.h"
#include <SDL_hints.h>

//Own components headers
#include "sdl/Texture.h"
#include "utils/drawing/Color.h"

int32_t Renderer::init(SDL_Window* window){

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		std::cerr << "Warning: Linear texture filtering not enabled! "
		  "SDL_SetHint() failed. SDL Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr auto unspecifiedDriverId = -1;
	_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverId, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	if(_sdlRenderer == nullptr){
		std::cerr<<"SDL_CreateRenderer() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	//Background color
	setBackgroundColor(_clearColor);

	Texture::setRenderer(_sdlRenderer);

	return EXIT_SUCCESS;
}
void Renderer::deinit(){
	if(_sdlRenderer != nullptr){
		SDL_DestroyRenderer(_sdlRenderer);
		_sdlRenderer = nullptr;
	}
}
void Renderer::setBackgroundColor(const Color& color){
	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer,color.rgba.r,color.rgba.g,color.rgba.b,color.rgba.a)){
		std::cerr<<"SDL_SetRenderDrawColor() failed. Reason: "<< SDL_GetError() << "\n";
	}
}
void Renderer::clearScreen(){
	Texture::clearCurrentRendererTarget(_clearColor);
}
void Renderer::finishFrame(){
	if(!_isRendererLocked){
		std::cerr<<"WARNING, Renderer was unlocked. Self-locking locking renderer. Some FBO (Framebuffer) will be in a broke state.\n";
		_isRendererLocked = true;
		resetRendererTarget();
		return;
	}

	SDL_RenderPresent(_sdlRenderer);
	_activeWidgets = 0;
}
void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams){
	if(WidgetType::IMAGE == drawParams.widgetType){
		drawImage(drawParams, texture);
	}else if(WidgetType::TEXT == drawParams.widgetType || WidgetType::FBO == drawParams.widgetType){
		drawTextureInternal(drawParams, texture);
	}else{
		std::cerr<<"Error, received unsupported WidgetType: "<<static_cast<int32_t>(drawParams.widgetType)
				 <<" for rsrcId: "<<drawParams.rsrcId<<"\n";
		--_activeWidgets;
	}
	++_activeWidgets;
}
void Renderer::setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode){
	if(EXIT_SUCCESS != Texture::setBlendModeTexture(texture, blendMode)){
		std::cerr<<"setBlendModeTexture() failed for file: \n";
	}
}
void Renderer::setWidgetOpacity(SDL_Texture* texture, int32_t opacity){
	 if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, opacity)){
		 std::cerr<<"setAlphaTexture(texture, opacity) failed: \n";
	 }
}
int32_t Renderer::clearCurrentRendererTarget(const Color& color){
	return Texture::clearCurrentRendererTarget(color);
}
int32_t Renderer::setRendererTarget(SDL_Texture* target){
	return Texture::setRendererTarget(target);
}
int32_t Renderer::resetRendererTarget(){
	return Texture::resetRendererTarget();
}
void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture* texture){
	if(FULL_OPACITY == drawParams.opacity){
		drawTextureInternal(drawParams, texture);
	}else{
		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
			std::cerr<<"Texture::setAlphaTexture() failed for drawParams.rsrcId: "<< drawParams.rsrcId << "\n";
		}
		drawTextureInternal(drawParams, texture);

		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, FULL_OPACITY)){
			std::cerr<<"Texture::setAlphaTexture() failed for drawParams.rsrcId: "<< drawParams.rsrcId << "\n";
		}
	}
}
void Renderer::drawTextureInternal(const DrawParams& drawParams, SDL_Texture *texture){
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,
								   .w = drawParams.width, .h = drawParams.height};

	const SDL_Rect* rect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);
	//const SDL_Point* center = reinterpret_cast<const SDL_Point*>(&drawParams.rotationCenter);

	const int32_t err = SDL_RenderCopyEx(_sdlRenderer, texture, rect, &destRect,
										drawParams.rotationAngle,

										//If you want to rotate in the center on the image set nullptr,
										//or else if you want to rotate around some point set center
										nullptr,//center or nullptr

										static_cast<SDL_RendererFlip>(drawParams.fliType));

	if(EXIT_SUCCESS != err){
		std::cerr<<"SDL_RenderCopy() failed for drawParams.rsrcId: "<< drawParams.rsrcId <<". Reason: "<< SDL_GetError() << "\n";
	}
}
int32_t Renderer::getActiveWidgets() const {
	return _activeWidgets;
}
int32_t Renderer::lockRenderer(){
	if(_isRendererLocked){
		std::cerr<<"Error, isRendererLocked was already locked.\n";
		return EXIT_FAILURE;
	}
	_isRendererLocked = true;
	return EXIT_SUCCESS;
}
int32_t Renderer::unlockRenderer(){
	if(!_isRendererLocked){
		std::cerr<<"Error, isRendererLocked was not locked in the firs place.\n";
		return EXIT_FAILURE;
	}
	_isRendererLocked = false;
	return EXIT_SUCCESS;
}
