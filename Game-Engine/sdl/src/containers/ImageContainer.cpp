#include "sdl/containers/ImageContainer.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers
#include "sdl/Texture.h"

static const Frames EMPTY_FRAMES{Rectangle::ZERO};

int32_t ImageContainer::init(const ImageContainerCfg& cfg){
	for(const auto& pair : cfg.imageConfigs){
		const auto& elem = pair.second;
		const auto rsrcId = pair.first;

		if(EXIT_SUCCESS != loadSingleResource(elem, rsrcId)){
			std::cerr<<"loadSingleResource() failed" << elem.location << "\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
void ImageContainer::deinit(){
	for(auto& pair : _textures){
		Texture::freeTexture(pair.second);
	}
}
SDL_Texture* ImageContainer::getImageTexture(int32_t rsrcId) const{
	auto it = _textures.find(rsrcId);
	if(it == _textures.end()){
		std::cerr<<"Error, invalid rsrcId: "<<rsrcId<<" requested\n";
		return nullptr;
	}
	return it->second;
}
const Frames& ImageContainer::getImageFrame(int32_t rsrcId) const{
	auto it = _textureFrames.find(rsrcId);
	if(it == _textureFrames.end()){
		std::cerr<<"Error, invalid rsrcId: "<<rsrcId<<" requested. Returning  EMPTY_FRAMES\n";
		return EMPTY_FRAMES;
	}
	return it->second;
}
int32_t ImageContainer::loadSingleResource(const ImageCfg& resCfg,int32_t rsrcId){

	SDL_Texture* texture = nullptr;

	if(EXIT_SUCCESS != Texture::createTextureFormFile(resCfg.location, texture)){
		std::cerr<<"Texture::createTextureFormFile() failed" << resCfg.location << "\n";
		return EXIT_FAILURE;
	}
	_textures[rsrcId] = texture;
	_textureFrames[rsrcId] = resCfg.frames;

	return EXIT_SUCCESS;
}
