//Corresponding header
#include "sdl/Texture.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_ttf.h>

//Own includes
#include "utils/drawing/Color.h"

//Own components headers
static SDL_Renderer* gRenderer = nullptr;

int32_t Texture::createSurfaceFormFile(const std::string& filePath, SDL_Surface*& outSurface){
	outSurface = IMG_Load(filePath.c_str());

	if(outSurface == nullptr){
		std::cerr<<"IMG_Load() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int32_t Texture::createTextureFormFile(const std::string& filePath, SDL_Texture*& outTexture){
	SDL_Surface* surface = nullptr;

	if(EXIT_SUCCESS != createSurfaceFormFile(filePath, surface)){
		std::cerr<<"createSurfaceFormFile(filePath, surface) failed for filePath: "<< filePath << "\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != createTextureFormSurface(surface, outTexture)){
		std::cerr<<"createTextureFormSurface(surface,outTexture) failed for filePath: "<< filePath << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}

int32_t Texture::createTextureFormSurface(SDL_Surface*& inOutSurface, SDL_Texture*& outTexture){
	outTexture = SDL_CreateTextureFromSurface(gRenderer, inOutSurface);

	if(outTexture == nullptr){
		std::cerr<<"SDL_CreateTextureFromSurface() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	freeSurface(inOutSurface);

	return EXIT_SUCCESS;
}

int32_t Texture::createTextFromText(const std::string& text, const Color &color,
							TTF_Font* font,
							SDL_Texture*& outTexture,
							int32_t &outTextWidth,
							int32_t &outTextHeight){

	const SDL_Color* sdlColor = reinterpret_cast<const SDL_Color*>(&color.rgba);

	SDL_Surface* textSurface = TTF_RenderText_Blended(font,text.c_str(),*sdlColor);

	if(textSurface == nullptr){
		std::cerr<<"TTF_RenderText_Blended() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	outTextWidth = textSurface->w;
	outTextHeight = textSurface->h;

	if(EXIT_SUCCESS != Texture::createTextureFormSurface(textSurface, outTexture)){
		std::cerr<<"Texture::createTextureFormSurface() failed for text. Reason: "<< text <<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int32_t Texture::createEmptyTexture(int32_t width, int32_t height, SDL_Texture*& outTexture){
	outTexture =  SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	if(outTexture == nullptr){
		std::cerr<<"createEmptyTexture() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface*& outSurface){
	if(outSurface != nullptr){
		SDL_FreeSurface(outSurface);
		outSurface = nullptr;
	}
}

void Texture::freeTexture(SDL_Texture*& outTexture){
	if(outTexture != nullptr){
		SDL_DestroyTexture(outTexture);
		outTexture = nullptr;
	}
}

void Texture::setRenderer(SDL_Renderer* renderer){
	gRenderer = renderer;
}

int32_t Texture::setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode){
	if(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode))){
		std::cerr<<"SDL_SetTextureBlendMode failed: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int32_t Texture::setAlphaTexture(SDL_Texture *texture, int32_t alpha){
	if(ZERO_OPACITY > alpha || alpha > FULL_OPACITY){
		std::cerr<<"Error, invalid alpha value: " << alpha << " provided.\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, static_cast<uint8_t>(alpha))){
		std::cerr<<"SDL_SetTextureAlphaMod failed: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int32_t Texture::clearCurrentRendererTarget(const Color& color){
	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(gRenderer, color.rgba.r, color.rgba.g, color.rgba.b, color.rgba.a)){
		std::cerr<<"SDL_SetRenderDrawColor() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	
	if(EXIT_SUCCESS != SDL_RenderClear(gRenderer)){
		std::cerr<<"SDL_RenderClear() failed. Reason: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int32_t Texture::setRendererTarget(SDL_Texture* target){
	if(EXIT_SUCCESS != SDL_SetRenderTarget(gRenderer, target)){
		std::cerr<<"SDL_SetRenderTarget failed: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int32_t Texture::resetRendererTarget(){
	if(EXIT_SUCCESS != SDL_SetRenderTarget(gRenderer, nullptr)){
		std::cerr<<"SDL_SetRenderTarget failed: "<< SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
