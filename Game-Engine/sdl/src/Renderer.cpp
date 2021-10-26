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
	_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverId, SDL_RENDERER_ACCELERATED);

	if(_sdlRenderer == nullptr){
		std::cerr<<"SDL_CreateRenderer() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	//Background colors
	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE)){
		std::cerr<<"SDL_SetRenderDrawColor() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	Texture::setRenderer(_sdlRenderer);

	return EXIT_SUCCESS;
}
void Renderer::deinit(){
	if(_sdlRenderer != nullptr){
		SDL_DestroyRenderer(_sdlRenderer);
		_sdlRenderer = nullptr;
	}
}

void Renderer::clearScreen(){
	if(EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)){
		std::cerr<<"SDL_RenderClear(_sdlRenderer) failed. Reason: "<< SDL_GetError() << "\n";
	}
}
void Renderer::finishFrame(){
	SDL_RenderPresent(_sdlRenderer);
}
void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams){
	if(WidgetType::IMAGE == drawParams.widgetType){
		drawImage(drawParams, texture);
	}else if(WidgetType::TEXT == drawParams.widgetType){
		drawText(drawParams, texture);
	}else{
		std::cerr<<"Error, received unsupported WidgetType: "<<static_cast<int32_t>(drawParams.widgetType)
				 <<" for rsrcId: "<<drawParams.rsrcId<<"\n";
	}
}

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture* texture){
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,
							   .w = drawParams.width, .h = drawParams.height};

	int32_t err = EXIT_SUCCESS;
	if(FULL_OPACITY == drawParams.opacity){
		err = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);
	}else{
		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
			std::cerr<<"Texture::setAlphaTexture() failed for drawParams.rsrcId: "<< drawParams.rsrcId << "\n";
		}
		err = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);

		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, FULL_OPACITY)){
			std::cerr<<"Texture::setAlphaTexture() failed for drawParams.rsrcId: "<< drawParams.rsrcId << "\n";
		}
	}

	if(EXIT_SUCCESS != err){
		std::cerr<<"SDL_RenderCopy() failed for drawParams.rsrcId: "<< drawParams.rsrcId <<". Reason: "<< SDL_GetError() << "\n";
	}
}
void Renderer::drawText(const DrawParams& drawParams, SDL_Texture* texture){
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,
							   .w = drawParams.width, .h = drawParams.height};

	//TODO Do no set alpha every time.
	if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
		std::cerr<<"Texture::setAlphaTexture() failed for drawParams.rsrcId: "<< drawParams.rsrcId << "\n";
	}

	const  int32_t err = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);
	if(EXIT_SUCCESS != err){
		std::cerr<<"SDL_RenderCopy() failed for drawParams.rsrcId: "<< drawParams.rsrcId <<". Reason: "<< SDL_GetError() << "\n";
	}
}
