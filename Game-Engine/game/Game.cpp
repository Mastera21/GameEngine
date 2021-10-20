
#include "Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Texture.h"
#include "sdl/Event.h"

int32_t Game::loadResources(const std::unordered_map<GameImages,std::string>& res){
	for(const auto& i : res){
		const auto resId = i.first;
		const auto& location = i.second;

		if(EXIT_SUCCESS != Texture::createTextureFormFile(location, _imageSurfaces[resId])){
				std::cerr<<"Texture::createSurfaceFormFile() failed" << location << std::endl;
				return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

int32_t Game::init(const GameCfg& cfg){
	if(EXIT_SUCCESS != loadResources(cfg.imagesPaths)){
		std::cerr<<"loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	_currChosenImage = _imageSurfaces[PRESS_KEYS];

	return EXIT_SUCCESS;
}

void Game::deinit(){
	for(int64_t i = 0; i < COUNT; ++i){
		Texture::freeTexture(_imageSurfaces[i]);
	}
}

void Game::draw(std::vector<SDL_Texture*>& images){
	images.push_back(_currChosenImage);
	//images.push_back(_imageSurfaces[LAYER_2]);
}

void Game::handleEvent(const Event& event){
	if(TouchEvent::KEYBOARD_RELEASE == event.type){
		_currChosenImage = _imageSurfaces[PRESS_KEYS];
		return;
	}
	if(TouchEvent::KEYBOARD_PRESS != event.type){
		return;
	}

	switch(event.key){
		case Keyboard::KEY_UP:
			_currChosenImage = _imageSurfaces[UP];
			break;
		case Keyboard::KEY_DOWN:
			_currChosenImage = _imageSurfaces[DOWN];
			break;
		case Keyboard::KEY_LEFT:
			_currChosenImage = _imageSurfaces[LEFT];
			break;
		case Keyboard::KEY_RIGHT:
			_currChosenImage = _imageSurfaces[RIGHT];
			break;
		default:
			break;
	}
}

