#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>

//Other libraries headers

//Own components headers
#include "utils/drawing/DrawParams.h"
#include "utils/drawing/Color.h"
//Forward declarations
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer {
public:
	Renderer() = default;

	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) = delete;

	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;

	int32_t init(SDL_Window* window);
	void deinit();
	void clearScreen();
	void finishFrame();
	void renderTexture(SDL_Texture* texture, const DrawParams& drawParams);

	void setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode);
	void setWidgetOpacity(SDL_Texture* texture, int32_t opacity);

	void setBackgroundColor(const Color& color);

	int32_t getActiveWidgets() const;
	
	int32_t clearCurrentRendererTarget(const Color& color);
	int32_t setRendererTarget(SDL_Texture* target);
	int32_t resetRendererTarget();

	int32_t lockRenderer();
	int32_t unlockRenderer();

private:
	SDL_Renderer* _sdlRenderer = nullptr;
	Color _clearColor = Colors::BLACK;

	void drawImage(const DrawParams& drawParams, SDL_Texture *texture);
	void drawTextureInternal(const DrawParams& drawParams, SDL_Texture *texture);

	int32_t _activeWidgets = 0;
	bool _isRendererLocked = true; //allows or forbids changing to different renderer target
};

#endif /* SDL_RENDERER_H_ */
