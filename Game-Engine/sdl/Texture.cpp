//Corresponding header
#include "sdl/Texture.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SDL_image.h>
#include <SDL_render.h>

//Own components headers
static SDL_Renderer* gRenderer = nullptr;

int32_t Texture::createSurfaceFormFile(const std::string& filePath, SDL_Surface*& outSurface){
	outSurface = IMG_Load(filePath.c_str());

	if(outSurface == nullptr){
		std::cerr<<"SDL_SetRenderDrawColor() failed. Reason: "<< SDL_GetError() << "\n";
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
