#include "EngineConfigLoader.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

namespace {

constexpr auto WINDOW_WIDTH = 640;//1080
constexpr auto WINDOW_HEIGHT = 480;//640
constexpr auto WINDOW_NAME = "GameEngine";

}

static std::string getFilePath(const std::string relativePath){
#ifdef NDEBUG
	//Release mode
	return relativePath;
#else
	//Debug mode
	return "../" + relativePath;
#endif
}

static void populateMonitorConfig(MonitorWindowCofg& cfg){
	//Setup window;
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}


static void populateGameConfig(GameCfg& cfg){

	cfg.imagesPaths[UP] = getFilePath("assets/up.png");
	cfg.imagesPaths[DOWN] =  getFilePath("assets/down.png");
	cfg.imagesPaths[LEFT] =  getFilePath("assets/left.png");
	cfg.imagesPaths[RIGHT] =  getFilePath("assets/right.png");
	cfg.imagesPaths[PRESS_KEYS] =  getFilePath("assets/press_keys.png");
	cfg.imagesPaths[LAYER_2] =  getFilePath("assets/layer_2.png");
}

EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;
	populateMonitorConfig(cfg.windowCfg);
	populateGameConfig(cfg.gameCfg);
	return cfg;
}
