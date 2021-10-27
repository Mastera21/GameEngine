
#include "Engine.h"

//C system headers

//C++ system headers

#include <iostream>
#include <cstring>

//Other libraries headers

//Own components headers
#include "engine/config/EngineConfig.h"
#include "manager/managers/DrawMgr.h"
#include "manager/managers/RsrcMgr.h"
#include "utils/time/Time.h"
#include "utils/thread/ThreadUtils.h"
#include "sdl/Texture.h"


int32_t Engine::init(const EngineConfig& cfg){

	gDrawMgr = new DrawMgr();
	if(gDrawMgr == nullptr){
		std::cerr<<"Error, bad alloc for gDrawMgr\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != gDrawMgr->init(cfg.drawMgrCfg)){
		std::cerr<<"gDrawMgr->init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	gRsrcMgr = new RsrcMgr();
	if(gRsrcMgr == nullptr){
		std::cerr<<"Error, bad alloc for gRsrcMgr\n";
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != gRsrcMgr->init(cfg.rsrcMgrCfg)){
		std::cerr<<"gRsrcMgr->init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _event.init()){
		std::cerr<<"_event.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _game.init(cfg.gameCfg)){
		std::cerr<<"_game.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit(){
	_game.deinit();
	_event.deinit();

	gRsrcMgr->deinit();
	delete gRsrcMgr;
	gRsrcMgr = nullptr;

	gDrawMgr->deinit();
	delete gDrawMgr;
	gDrawMgr = nullptr;
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
	gDrawMgr->clearScreen();

	_game.draw();

	gDrawMgr->finishFrame();

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

