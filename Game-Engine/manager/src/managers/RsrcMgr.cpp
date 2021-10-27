#include "manager/managers/RsrcMgr.h"

//C system headers

//C++ system headers

#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/config/RsrcMgrCfg.h"

RsrcMgr* gRsrcMgr = nullptr;

int32_t RsrcMgr::init(const RsrcMgrCfg& cfg){
	if(EXIT_SUCCESS != ImageContainer::init(cfg.imageContainerCfg)){
		std::cerr<<"_imgContainer.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != TextContainer::init(cfg.textContainerCfg)){
		std::cerr<<"_textContainer.init() failed" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void RsrcMgr::deinit(){
	ImageContainer::deinit();
	TextContainer::deinit();
}
void RsrcMgr::process(){

}
