#include "TextContainer.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "SDL_ttf.h"

//Own components headers
#include "sdl/Texture.h"
#include "utils/drawing/Color.h"

int32_t TextContainer::init(const TextContainerCfg& cfg){
	TTF_Font* currFont = nullptr;

	for(const auto& pair : cfg.fontConfigs){
		const auto key = pair.first;
		const auto& fontCfg = pair.second;
		currFont = TTF_OpenFont(fontCfg.location.c_str(), fontCfg.fontSize);
		if(currFont == nullptr){
			std::cerr<<"TTF_OpenFont() failed for fontLocation: "<< fontCfg.location << SDL_GetError() << "\n";
			return EXIT_FAILURE;
		}

		_fonts[key] = currFont;
	}
	return EXIT_SUCCESS;
}

void TextContainer::deinit(){
	for(auto& pair : _fonts){
		 TTF_CloseFont(pair.second);
	}
}

void TextContainer::createText(const std::string& text, const Color &color, int32_t fontId, int32_t &outTextId,
						int32_t &outTextWidth,
						int32_t &outTextHeight){
	auto it = _fonts.find(fontId);
	if(it == _fonts.end()){
		std::cerr<<"Error, fontId " << fontId<< "could not be found. Will not create text: " << text<<"\n";
		return;
	}

	TTF_Font* font = it->second;
	SDL_Texture* textTexture = nullptr;
	if(EXIT_SUCCESS != Texture::createTextFromText(text, color, font, textTexture, outTextWidth, outTextHeight)){
		std::cerr<<"Texture::createTextFromText() failed for text: "<< text << "\n";
		return;
	}
}

void TextContainer::reloadText(const std::string& text, const Color &color, int32_t fontId,
                         int32_t textId, int32_t &outTextWidth,
                         int32_t &outTextHeight){
	//TODO
}

void TextContainer::unloadText(int32_t textId){
	//TODO
}

SDL_Texture* TextContainer::getTextTexture(int32_t textId) const{
	//TODO

	return nullptr;
}

void TextContainer::occupyFreeSlotIndex(int32_t& outIdx){
	//TODO
}
void TextContainer::freeSlotIndex(int32_t index){
	//TODO
}
