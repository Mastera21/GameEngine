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

class Texture {
public:
	Texture() = delete;

	static int32_t createSurfaceFormFile(const std::string& filePath, SDL_Surface*& outSurface);

	static int32_t createTextureFormFile(const std::string& filePath, SDL_Texture*& outTexture);

	static int32_t createTextureFormSurface(SDL_Surface*& inOutSurface, SDL_Texture*& outTexture);

	static int32_t setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode);

	static int32_t setAlphaTexture(SDL_Texture *texture, int32_t alpha);

	static void freeSurface(SDL_Surface*& outSurface);

	static void freeTexture(SDL_Texture*& outTexture);

	static void setRenderer(SDL_Renderer* renderer);
};

#endif /* SDL_TEXTURE_H_ */
