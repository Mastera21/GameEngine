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

constexpr auto WINDOW_WIDTH = 900;//1080
constexpr auto WINDOW_HEIGHT = 900;//640
constexpr auto WINDOW_NAME = "GameEngine";

constexpr auto CHESS_PIRCES_FRAMES = 6;
constexpr auto CHESS_PIECES_WIDTH_HEIGHT = 96;

constexpr auto CHESS_BOARD_WIDTH_HEIGHT = 900;

constexpr auto TARGET_IMG_WIDTH_HEIGHT = 98;

constexpr auto ANGELINE_VINTAGE_40_FONT_SIZE = 40;

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
	fontCfg.fontSize = ANGELINE_VINTAGE_40_FONT_SIZE;
	cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE, fontCfg));
}

static void populateImageContainerConfig(ImageContainerCfg& cfg){
	ImageCfg imageCfg;

	constexpr auto buttonsCount = 2;
	const std::string buttonPaths[buttonsCount] = {
			"assets/p/whitePieces.png",
			"assets/p/blackPieces.png"
	};

	constexpr int32_t buttonRsrcIds[buttonsCount] = {
		TextureId::WHITE_PIECES, TextureId::BLACK_PIECES
	};
	for(int32_t i = 0; i < buttonsCount; ++i){
		imageCfg.location = getFilePath(buttonPaths[i]);
		for(auto frameId = 0; frameId < CHESS_PIRCES_FRAMES; ++frameId){
		//										x				y		w				h
			imageCfg.frames.emplace_back(frameId * CHESS_PIECES_WIDTH_HEIGHT, 0, CHESS_PIECES_WIDTH_HEIGHT, CHESS_PIECES_WIDTH_HEIGHT);
		}
		cfg.imageConfigs.emplace(buttonRsrcIds[i], imageCfg);
		imageCfg.frames.clear();
	}


	imageCfg.location = getFilePath("assets/p/chessBoard.jpg");
	imageCfg.frames.emplace_back(0, 0, CHESS_BOARD_WIDTH_HEIGHT, CHESS_BOARD_WIDTH_HEIGHT);
	cfg.imageConfigs.emplace(TextureId::CHESS_BOARD, imageCfg);
	imageCfg.frames.clear();

	imageCfg.location = getFilePath("assets/p/target.png");
	imageCfg.frames.emplace_back(0, 0, TARGET_IMG_WIDTH_HEIGHT, TARGET_IMG_WIDTH_HEIGHT);
	cfg.imageConfigs.emplace(TextureId::TARGET, imageCfg);
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
	cfg.chessBoardRsrcId = TextureId::CHESS_BOARD;
	cfg.whitePiecesRsrcId = TextureId::WHITE_PIECES;
	cfg.blackPiecesRsrcId = TextureId::BLACK_PIECES;
	cfg.targetRsrcId = TextureId::TARGET;

}

EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;
	populateMgrHandlerConfig(cfg.managerHandlerCfg);
	populateGameConfig(cfg.gameCfg);
	return cfg;
}
