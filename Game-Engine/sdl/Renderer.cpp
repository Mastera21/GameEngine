#include "Renderer.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "SDL_render.h"
#include <SDL_hints.h>

//Own components headers
#include "sdl/Texture.h"

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

	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE)){
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
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,
							   .w = drawParams.width, .h = drawParams.height};

	if(EXIT_SUCCESS != SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect)){
		std::cerr<<"SDL_RenderCopy() failed. Reason: "<< SDL_GetError() << "\n";
	}
}
