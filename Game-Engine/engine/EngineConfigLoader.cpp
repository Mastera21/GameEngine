#include "EngineConfigLoader.h"

//C system headers

//C++ system headers
#include <string>
#include <array>
#include <iostream>
//Other libraries headers

//Own components headers
#include "common/CommonDefines.h"

namespace {

constexpr auto WINDOW_WIDTH = 1080;//1080
constexpr auto WINDOW_HEIGHT = 640;//640
constexpr auto WINDOW_NAME = "GameEngine";

constexpr auto RUNNING_GRIL_FRAMES = 6;
constexpr auto RUNNING_GRIL_IMG_WIDTH = 256;
constexpr auto RUNNING_GRIL_IMG_HEIGHT = 220;

constexpr auto BUTTON_FRAMES = 3;
constexpr auto BUTTON_WIDTH = 150;
constexpr auto BUTTON_HEIGHT = 50;

constexpr auto WHEEL_IMAGE_WIDTH_HEIGHT = 695;

constexpr auto MAX_FRAME_RATE = 60;
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
//This is for Menu
static void populateTextContainerConfig(TextContainerCfg& cfg){
	FontCfg fontCfg;
	fontCfg.location = getFilePath("assets/f/AngelineVintage.ttf");
	fontCfg.fontSize = 50;
	cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE, fontCfg));
}

static void populateImageContainerConfig(ImageContainerCfg& cfg){
	ImageCfg imageCfg;
	imageCfg.location = getFilePath("assets/p/sprites/running_girl.png");
	for(auto i = 0; i < RUNNING_GRIL_FRAMES; ++i){
		//										x				y		w							h
		imageCfg.frames.emplace_back(i * RUNNING_GRIL_IMG_WIDTH, 0, RUNNING_GRIL_IMG_WIDTH, RUNNING_GRIL_IMG_HEIGHT);
	}
	cfg.imageConfigs.emplace(TextureId::RUNNING_GIRL, imageCfg);
	imageCfg.frames.clear();

	constexpr auto buttonsCount = 2;
	const std::string buttonPaths[buttonsCount] = {
			"assets/p/buttons/button_start.png",
			"assets/p/buttons/button_end.png"
	};

	constexpr int32_t buttonRsrcIds[buttonsCount] = {
		TextureId::START_BUTTON, TextureId::STOP_BUTTON
	};
	for(int32_t i = 0; i < buttonsCount; ++i){
		imageCfg.location = getFilePath(buttonPaths[i]);
		for(auto frameId = 0; frameId < BUTTON_FRAMES; ++frameId){
		//										x				y		w				h
			imageCfg.frames.emplace_back(frameId * BUTTON_WIDTH, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		}
		cfg.imageConfigs.emplace(buttonRsrcIds[i], imageCfg);
		imageCfg.frames.clear();
	}


	imageCfg.location = getFilePath("assets/p/wheel.png");

	imageCfg.frames.emplace_back(0, 0, WHEEL_IMAGE_WIDTH_HEIGHT, WHEEL_IMAGE_WIDTH_HEIGHT);

	cfg.imageConfigs.emplace(TextureId::WHEEL, imageCfg);
	imageCfg.frames.clear();

}

static void populateMonitorConfig(MonitorWindowCofg& cfg){
	//Setup window;
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}

static void populateRsrcMgrConfig(RsrcMgrCfg& cfg){
	populateImageContainerConfig(cfg.imageContainerCfg);
	populateTextContainerConfig(cfg.textContainerCfg);
}

static void populateDrawMgrConfig(DrawMgrCfg& cfg){
	populateMonitorConfig(cfg.windowCfg);
	cfg.maxFrameRate = MAX_FRAME_RATE;
}

static void populateMgrHandlerConfig(ManagerHandlerCfg& cfg){
	populateDrawMgrConfig(cfg.drawMgrCfg);
	populateRsrcMgrConfig(cfg.rsrcMgrCfg);
}

static void populateGameConfig(GameCfg& cfg){
	cfg.runningGrilId = TextureId::RUNNING_GIRL;
	cfg.wheelId = TextureId::WHEEL;

	cfg.startButtonRsrcId = TextureId::START_BUTTON;
	cfg.stopButtonRsrcId = TextureId::STOP_BUTTON;

	cfg.textFontId = FontId::ANGELINE_VINTAGE;
}

EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;
	populateMgrHandlerConfig(cfg.managerHandlerCfg);
	populateGameConfig(cfg.gameCfg);
	return cfg;
}
