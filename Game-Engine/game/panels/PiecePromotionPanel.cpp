
#include "game/panels/PiecePromotionPanel.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "game/interfaces/GameInterface.h"
#include "sdl/Event.h"

int32_t PiecePromotionPanel::init(const PiecePromotionPanelCfg& cfg, GameInterface* gameInterface){
	if(gameInterface == nullptr){
		std::cerr<<"Error, gameInterface is nullptr in PieceHandler.cpp\n";
		return EXIT_FAILURE;
	}
	_gameInterface = gameInterface;

	PiecePromotionButtonCfg btnCfg;
	btnCfg.onBtnClicked = [this](PieceType pieceType){
		onButtonClicked(pieceType);
	};

	btnCfg.buttonBgrRsrcId = cfg.buttonBgrRsrcId;
	btnCfg.buttonWhitePieceRsrcId = cfg.whitePiecesRsrcId;
	btnCfg.buttonBlackPieceRsrcId = cfg.blackPiecesRsrcId;
	btnCfg.bgrWidth = cfg.buttonBgrWidth;
	btnCfg.bgrHeight = cfg.buttonBgrHeight;
	btnCfg.width = cfg.buttonWidth;
	btnCfg.height = cfg.buttonHeight;

	constexpr std::array<PieceType, BUTTONS_COUNT> pieceTypes {
		PieceType::QUEEN, PieceType::ROOK, PieceType::BISHOP, PieceType::KNIGHT
	};

	constexpr auto btnOffset = 50;
	const auto startX = (cfg.gameBoardWidth - (BUTTONS_COUNT * (cfg.buttonWidth + btnOffset))) / 2 ;
	btnCfg.bgrPos.y = (cfg.gameBoatdHeight - cfg.buttonBgrHeight)/ 2 ;

	for(int32_t i = 0; i < BUTTONS_COUNT; ++i){
		btnCfg.pieceType = pieceTypes[i];
		btnCfg.bgrPos.x = startX + (i * (cfg.buttonWidth + btnOffset));

		if(EXIT_SUCCESS != _promotionBtns[i].init(btnCfg)){
			std::cerr<<"Error, _promotionBtns[].init() failed for id: "<< i <<"\n";
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
void PiecePromotionPanel::onButtonClicked(PieceType pieceType){
	_gameInterface->promotePiece(pieceType);
	_isActive = false;
}
void PiecePromotionPanel::handleEvent(const Event& e){
	for(auto& btn : _promotionBtns){
		if(btn.isInputUnlocked() && btn.containsEvent(e)){
			btn.handleEvent(e);
			break;
		}
	}
}
void PiecePromotionPanel::draw(){
	if(!_isActive){
		return;
	}
	for(auto& btn : _promotionBtns){
		btn.draw();
	}
}
void PiecePromotionPanel::activate(int32_t playerId){
	_isActive = true;
	for(auto& btn : _promotionBtns){
		btn.activate(playerId);
	}
}
bool PiecePromotionPanel::isActive() const{
	return _isActive;
}
