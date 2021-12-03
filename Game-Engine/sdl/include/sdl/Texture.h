#ifndef SDL_TEXTURE_H_
#define SDL_TEXTURE_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <string>

//Other libraries headers

//Own components headers
#include "utils/drawing/DrawParams.h"

//Forward declarations
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
struct Color;
typedef struct _TTF_Font TTF_Font;

class Texture {
public:
	Texture() = delete;

	static int32_t createSurfaceFormFile(const std::string& filePath, SDL_Surface*& outSurface);

	static int32_t createTextureFormFile(const std::string& filePath, SDL_Texture*& outTexture);

	static int32_t createTextureFormSurface(SDL_Surface*& inOutSurface, SDL_Texture*& outTexture);

	static int32_t createTextFromText(const std::string& text, const Color &color,
							TTF_Font* font,
							SDL_Texture*& outTexture,
							int32_t &outTextWidth,
							int32_t &outTextHeight);

	static int32_t createEmptyTexture(int32_t width, int32_t height, SDL_Texture*& outTexture);						

	static int32_t setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode);

	static int32_t setAlphaTexture(SDL_Texture *texture, int32_t alpha);

	static void freeSurface(SDL_Surface*& outSurface);

	static void freeTexture(SDL_Texture*& outTexture);

	static void setRenderer(SDL_Renderer* renderer);

	static int32_t clearCurrentRendererTarget(const Color& color);

	static int32_t setRendererTarget(SDL_Texture* target);

	static int32_t resetRendererTarget();
};
#endif /* SDL_TEXTURE_H_ */
