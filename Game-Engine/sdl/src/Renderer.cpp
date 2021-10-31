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
	setBackgroundColor(Colors::BLACK);

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

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture* texture){
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,
							   .w = drawParams.width, .h = drawParams.height};

	const SDL_Rect* rect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);

	int32_t err = EXIT_SUCCESS;
	if(FULL_OPACITY == drawParams.opacity){
		err = SDL_RenderCopy(_sdlRenderer, texture, rect, &destRect);
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

	const SDL_Rect* rect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);

	const  int32_t err = SDL_RenderCopy(_sdlRenderer, texture, rect, &destRect);
	if(EXIT_SUCCESS != err){
		std::cerr<<"SDL_RenderCopy() failed for drawParams.rsrcId: "<< drawParams.rsrcId <<". Reason: "<< SDL_GetError() << "\n";
	}
}
