#ifndef MANAGER_INCLUDE_MANAGER_MANAGERS_DRAWMGR_H_
#define MANAGER_INCLUDE_MANAGER_MANAGERS_DRAWMGR_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "manager/managers/MgrBase.h"
#include "sdl/MonitorWindow.h"
#include "sdl/Renderer.h"
//Forward declarations
struct DrawMgrCfg;

class DrawMgr: public MgrBase {
public:
	DrawMgr() = default;
	DrawMgr(const DrawMgr& other) = delete;
	DrawMgr(DrawMgr&& other) = delete;

	DrawMgr& operator=(const DrawMgr& other) = delete;
	DrawMgr& operator=(DrawMgr&& other) = delete;

	int32_t init(const DrawMgrCfg& cfg);
	int64_t getMaxFrams() const;
	int32_t getActiveWidgets() const;

	void deinit() final;
	void process() final;

	void clearScreen();

	void finishFrame();

	void addDrawCmd(const DrawParams& drawParams);

	void setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode);
	void setWidgetOpacity(const DrawParams& drawParams, int32_t opacity);

private:
	Renderer _render;
	sd::MonitorWindow _window;
	//Hold maximum frame rate cap

	int64_t _maxFrames { 0 };
	SDL_Texture* getTextureinternal(const DrawParams& drawParams) const;
};
extern DrawMgr* gDrawMgr;
#endif /* MANAGER_INCLUDE_MANAGER_MANAGERS_DRAWMGR_H_ */
