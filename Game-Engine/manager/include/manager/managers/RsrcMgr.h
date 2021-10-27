#ifndef MANAGER_INCLUDE_MANAGER_MANAGERS_RSRCMGR_H_
#define MANAGER_INCLUDE_MANAGER_MANAGERS_RSRCMGR_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "manager/managers/MgrBase.h"
#include "sdl/containers/ImageContainer.h"
#include "sdl/containers/TextContainer.h"

//Forward declarations
struct RsrcMgrCfg;

class RsrcMgr: public MgrBase, public ImageContainer, public TextContainer{
public:
	RsrcMgr() = default;

	RsrcMgr(const RsrcMgr& other) = delete;
	RsrcMgr(RsrcMgr&& other) = delete;

	RsrcMgr& operator=(const RsrcMgr& other) = delete;
	RsrcMgr& operator=(RsrcMgr&& other) = delete;

	int32_t init(const RsrcMgrCfg& cfg);

	void deinit() final;
	void process() final;

};
extern RsrcMgr* gRsrcMgr;
#endif /* MANAGER_INCLUDE_MANAGER_MANAGERS_RSRCMGR_H_ */
