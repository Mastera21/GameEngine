#include "EngineConfigLoader.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "common/CommonDefines.h"

namespace {

constexpr auto WINDOW_WIDTH = 1080;//1080
constexpr auto WINDOW_HEIGHT = 640;//640
constexpr auto WINDOW_NAME = "GameEngine";

constexpr auto PRESS_KEYS_WIDTH = 640;
constexpr auto PRESS_KEYS_HEIGHT = 480;

constexpr auto LAYER_2_IMAGE_WIDTH = 150;
constexpr auto LAYER_2_IMAGE_HEIGHT = 150;

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

static void populateMonitorConfig(MonitorWindowCofg& cfg){
	//Setup window;
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}

static void populateDrawMgrConfig(DrawMgrCfg& cfg){
	populateMonitorConfig(cfg.windowCfg);
	cfg.maxFrameRate = MAX_FRAME_RATE;
}
static void populateGameConfig(GameCfg& cfg){
	cfg.layer2Rsrcid = TextureId::LAYER_2;
	cfg.pressKeysRsrcId = TextureId::PRESS_KEYS;
	cfg.textFontId = FontId::ANGELINE_VINTAGE;
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
	imageCfg.location = getFilePath("assets/p/press_keys.png");
	imageCfg.width = PRESS_KEYS_WIDTH;
	imageCfg.height = PRESS_KEYS_HEIGHT;
	cfg.imageConfigs.insert(std::make_pair(TextureId::PRESS_KEYS, imageCfg));

	imageCfg.location = getFilePath("assets/p/layer_2.png");
	imageCfg.width = LAYER_2_IMAGE_WIDTH;
	imageCfg.height = LAYER_2_IMAGE_HEIGHT;
	cfg.imageConfigs.insert(std::make_pair(TextureId::LAYER_2, imageCfg));

}

EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;
	populateDrawMgrConfig(cfg.drawMgrCfg);
	populateImageContainerConfig(cfg.imageContainerCfg);
	populateTextContainerConfig(cfg.textContainerCfg);
	populateGameConfig(cfg.gameCfg);
	return cfg;
}
