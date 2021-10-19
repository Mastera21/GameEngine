#ifndef SDL_TEXTURE_H_
#define SDL_TEXTURE_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers

//Forward declarations
struct SDL_Surface;

class Texture {
public:
  Texture() = delete;

  static int32_t loadSurfaceFromFile(const char *path,
                                     SDL_Surface *&outSurface);

  static void freeSurface(SDL_Surface *&surface);
};

#endif /* SDL_TEXTURE_H_ */
