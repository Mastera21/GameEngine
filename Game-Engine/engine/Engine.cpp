
#include "Engine.h"

//C system headers

//C++ system headers

#include <iostream>
#include <cstring>

//Other libraries headers
#include "SDL_ttf.h"

//Own components headers
#include "engine/config/EngineConfig.h"
#include "utils/time/Time.h"
#include "utils/thread/ThreadUtils.h"

#include "utils/drawing/Color.h"


#include "sdl/Texture.h"
int32_t textWidth = 0;
int32_t textHeight = 0;
SDL_Texture* gTexture = nullptr;


int32_t Engine::init(const EngineConfig& cfg){

	if(EXIT_SUCCESS != _window.init(cfg.windowCfg)){
		std::cerr<<"window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _render.init(_window.getWindow())){
		std::cerr<<"_render.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _imgContainer.init(cfg.imageContainerCfg)){
		std::cerr<<"_imgContainer.init() failed" << std::endl;
		return EXIT_FAILURE;
	}


	if(EXIT_SUCCESS != _event.init()){
		std::cerr<<"_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _game.init(cfg.gameCfg, &_imgContainer)){
		std::cerr<<"_game.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	loadText();

	return EXIT_SUCCESS;
}

void Engine::deinit(){
	_game.deinit();
	_event.deinit();
	_imgContainer.deinit();
	_render.deinit();
	_window.deinit();
}

void Engine::main(){
	Time time;

	while(true){
		time.getElapsed();
		const bool wantToExit = processFrame();
		if(wantToExit){
			break;
		}

		limitFPS(time.getElapsed().toMicroseconds());
	}

}
void Engine::drawFrame(){
	_render.clearScreen();
	std::vector<DrawParams> images;
	_game.draw(images);

	//This is for images.
	SDL_Texture* texture = nullptr;
	for(const DrawParams& i : images){
		texture = _imgContainer.getImageTexture(i.rsrcId);
		_render.renderTexture(texture, i);
	}

	//This is for text.
	DrawParams params;
	params.pos.x = 100;
	params.pos.y = 200;
	params.width = textWidth;
	params.height = textHeight;
	params.widgetType = WidgetType::TEXT;
	params.opacity = 120;
	_render.renderTexture(gTexture, params);

	_render.finishFrame();

}
bool Engine::processFrame(){
	while(_event.pollEvent()){
		if(_event.checkForExitRequest()){
			return true;
		}
		handleEvent();
	}
	//-----------------------Drawing -----------------------
	drawFrame();
	return false;
}
void Engine::handleEvent(){
	_game.handleEvent(_event);
}
void Engine::limitFPS(int64_t elapsedTimeMicroSeconds){
	constexpr auto maxFrames = 60;
	constexpr auto microSecondsInASecond = 1000000;
	constexpr auto microSecondsPerFrame = microSecondsInASecond / maxFrames;
	const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;
	if(sleepDurationMicroSeconds > 0){
		Threading::sleepFor(sleepDurationMicroSeconds);
	}
}

void Engine::loadText(){
	TTF_Font* font = TTF_OpenFont("../assets/f/AngelineVintage.ttf", 80);

	if(font == nullptr){
		std::cerr<<"TTF_OpenFont() failed: "<< SDL_GetError() << "\n";
		return;
	}

	 SDL_Color color = {.r = 127, .g = 127, .b = 127, .a = 255};

	 SDL_Surface *textSurface = TTF_RenderText_Blended(font, "Hello, World!", color);
	 if(textSurface == nullptr){
		 std::cerr<<"TTF_RenderText_Solid() failed: "<< SDL_GetError() << "\n";
	 }

	 textWidth = textSurface->w;
	 textHeight = textSurface->h;


	 if(EXIT_SUCCESS != Texture::createTextureFormSurface(textSurface, gTexture)){
		std::cerr<<"createTextureFormSurface() failed \n";
	 }

	 std::cout<<gTexture<<"\n";

	 TTF_CloseFont(font);
}

