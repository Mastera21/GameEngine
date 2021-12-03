#include "sdl/containers/FboContainer.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "SDL_ttf.h"

//Own components headers
#include "sdl/Texture.h"
#include "utils/drawing/Color.h"


int32_t FboContainer::init(){
    //TODO

	return EXIT_SUCCESS;
}

void FboContainer::deinit(){
    for(auto& texture : _textures){
		if(texture){
			Texture::freeTexture(texture);
		}
	}
}

void FboContainer::createFbo(int32_t fboWidth, int32_t fboHeight, int32_t &outFboId){
    SDL_Texture* textTexture = nullptr;
	if(EXIT_SUCCESS != Texture::createEmptyTexture(fboWidth, fboHeight, textTexture)){
		std::cerr<<"Texture::createTextFromText() failed: \n";
		return;
	}

	occupyFreeSlotIndex(outFboId, textTexture);
}

void FboContainer::unloadFbo(int32_t fboId){
    if(0 > fboId || fboId >= static_cast<int32_t>(_textures.size())){
		std::cerr<<"Error, trying to unload non-existing fboId: "<< fboId <<"\n";
		return;
	}
	freeSlotIndex(fboId);
}

SDL_Texture* FboContainer::getFboTexture(int32_t fboId) const{
    if(0 > fboId || fboId >= static_cast<int32_t>(_textures.size())){
		std::cerr<<"Error, trying to get non-existing fboId: "<< fboId <<"\n";
		return nullptr;
	}

	return _textures[fboId];
}

void FboContainer::occupyFreeSlotIndex(int32_t& outIdx, SDL_Texture* texture){
    const int32_t size = static_cast<int32_t>(_textures.size());

	for(int32_t i = 0; i < size; ++i){
		if(_textures[i] == nullptr){//Free index found
			outIdx = i;
			_textures[i] = texture;
			return;
		}
	}

	_textures.push_back(texture);
	outIdx = size;
}

void FboContainer::freeSlotIndex(int32_t index){
    Texture::freeTexture(_textures[index]);
}