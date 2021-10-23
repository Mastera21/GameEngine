#include "TextContainer.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include "SDL_ttf.h"

//Own components headers

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
