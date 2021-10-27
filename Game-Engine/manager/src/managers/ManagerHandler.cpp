#include "manager/managers/ManagerHandler.h"

//C system headers

//C++ system headers

#include <iostream>

//Other libraries headers

//Own components headers
#include "manager/managers/DrawMgr.h"
#include "manager/managers/RsrcMgr.h"
#include "manager/config/ManagerHandlerCfg.h"

int32_t ManagerHandler::init(const ManagerHandlerCfg& cfg){
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
	_managers[DRAW_MGR_IDX] = static_cast<MgrBase*>(gDrawMgr);
	_managers[RSRC_MGR_IDX] = static_cast<MgrBase*>(gRsrcMgr);

	return EXIT_SUCCESS;
}

void ManagerHandler::deinit(){
	gRsrcMgr->deinit();
	delete gRsrcMgr;
	gRsrcMgr = nullptr;

	gDrawMgr->deinit();
	delete gDrawMgr;
	gDrawMgr = nullptr;

	for(int32_t i = MANAGERS_COUNT - 1; i >= 0; --i){
		_managers[i]->process();
		_managers[i] = nullptr;

		nullifyGlobalMgr(i);
	}
}

void ManagerHandler::process(){
	for(int32_t i = 0; i < MANAGERS_COUNT; ++i){
		_managers[i]->process();
	}
}

void  ManagerHandler::nullifyGlobalMgr(int32_t mgr){
	switch(mgr){
	case DRAW_MGR_IDX:
		delete gDrawMgr;
		gDrawMgr = nullptr;
		break;
	case RSRC_MGR_IDX:
		delete gRsrcMgr;
		gRsrcMgr = nullptr;
		break;
	default:
		std::cerr<<"Received invalid mgr: " << mgr<<"\n";
		break;
	}
}
