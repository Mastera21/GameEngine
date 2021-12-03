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
    //TODO
}

void FboContainer::createFbo([[maybe_unused]]int32_t fboWidth, [[maybe_unused]]int32_t fboHeight, [[maybe_unused]]int32_t &outFboId){
    //TODO
}

void FboContainer::unloadFbo([[maybe_unused]]int32_t fboId){
    //TODO
}

SDL_Texture* FboContainer::getFboTexture([[maybe_unused]]int32_t fboId) const{
    //TODO
    return nullptr;
}

void FboContainer::occupyFreeSlotIndex([[maybe_unused]]int32_t& outIdx, [[maybe_unused]]SDL_Texture* texture){
    //TODO
}

void FboContainer::freeSlotIndex([[maybe_unused]]int32_t index){
    //TODO
}