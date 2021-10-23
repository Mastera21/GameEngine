
#include "Game.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers
#include "sdl/Event.h"
#include "sdl/containers/ImageContainer.h"

int32_t Game::init([[maybe_unused]]const GameCfg cfg, const ImageContainer* _imgContainerInterface){

	if(_imgContainerInterface == nullptr){
		std::cerr<<"Error, nullptr provided for _imgContainerInterface\n";
		return EXIT_FAILURE;
	}

	_imgContainer = _imgContainerInterface;

	layer2Image.rsrcId = cfg.layer2Rsrcid;

	Rectangle rect = _imgContainer->getImageFrame(layer2Image.rsrcId);
	layer2Image.width = rect.w;
	layer2Image.height = rect.h;
	layer2Image.pos = Point::ZERO;

	pressKeyImage.rsrcId = cfg.pressKeysRsrcId;
	rect = _imgContainer->getImageFrame(pressKeyImage.rsrcId);
	pressKeyImage.width = rect.w;
	pressKeyImage.height = rect.h;
	pressKeyImage.pos = Point::ZERO;
	pressKeyImage.pos.y += 20;

	return EXIT_SUCCESS;
}

void Game::deinit(){

}

void Game::draw(std::vector<DrawParams>& images){
	images.push_back(pressKeyImage);
	images.push_back(layer2Image);
}

void Game::handleEvent([[maybe_unused]]const sd::Event& event){
	if(TouchEvent::KEYBOARD_PRESS != event.type){
		return;
	}
	//Refact keys
	switch(event.key){
		case Keyboard::KEY_UP:
			pressKeyImage.pos.y -= 10;
			break;
		case Keyboard::KEY_DOWN:
			pressKeyImage.pos.y += 10;
			break;
		case Keyboard::KEY_LEFT:
			pressKeyImage.pos.x -= 10;
			break;
		case Keyboard::KEY_RIGHT:
			pressKeyImage.pos.x += 10;
			break;

		case Keyboard::KEY_Q:
			pressKeyImage.width -= 10;
			break;
		case Keyboard::KEY_W:
			pressKeyImage.width += 10;
			break;
		case Keyboard::KEY_E:
			pressKeyImage.height -= 10;
			break;
		case Keyboard::KEY_R:
			pressKeyImage.height += 10;
			break;

		case Keyboard::KEY_T:
			pressKeyImage.opacity -= 10;
			break;
		case Keyboard::KEY_Y:
			pressKeyImage.opacity += 10;
			break;
		default:
			break;
	}
}

