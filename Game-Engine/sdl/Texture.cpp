//Corresponding header
#include "sdl/Texture.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SDL_image.h>

//Own components headers

int32_t Texture::loadSurfaceFromFile(const char *path,
                                     SDL_Surface *&outSurface) {
  freeSurface(outSurface);

  //Load image at specified path
  outSurface = IMG_Load(path);
  if (nullptr == outSurface) {
    std::cerr << "Unable to load image " << path << ". SDL_image Error: "
        << IMG_GetError() << std::endl;

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface *&surface) {
  if (surface) { //sanity check
    SDL_FreeSurface(surface);
    surface = nullptr;
  }
}
