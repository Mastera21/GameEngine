#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>

//Other libraries headers

//Own components headers
#include "utils/drawing/DrawParams.h"
//Forward declarations
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;
struct Color;

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

private:
	SDL_Renderer *_sdlRenderer = nullptr;

	void drawImage(const DrawParams& drawParams, SDL_Texture *texture);
	void drawText(const DrawParams& drawParams, SDL_Texture *texture);

};

#endif /* SDL_RENDERER_H_ */
