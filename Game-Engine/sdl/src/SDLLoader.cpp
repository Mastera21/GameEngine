//Corresponding header
#include "sdl/SDLLoader.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SDL.h>
#include <SDL_video.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Own components headers

int32_t SDLLoader::init() {
  if (-1 == TTF_Init()) {
    std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: "
              << TTF_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  if (0 > SDL_Init(SDL_INIT_VIDEO)) {
    std::cerr << "SDL could not be initialised! SDL Error: " << SDL_GetError()
              << std::endl;
    return EXIT_FAILURE;
  }

  //Initialise PNG loading
  constexpr int32_t imgFlags = IMG_INIT_PNG;
  if (! (IMG_Init(imgFlags) & imgFlags)) {
    std::cerr << "SDL_image could not be initialised! "
              "SDL_image Error: "
              << IMG_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  if (0 > SDL_Init(SDL_INIT_TIMER)) {
    std::cerr << "SDL TIMER could not be initialised! "
              "SDL Error: "
              << SDL_GetError() << std::endl;

    return EXIT_FAILURE;
  }

  if (0 > SDL_Init(SDL_INIT_AUDIO)) {
    std::cerr << "SDL Audio could not be initialised! "
              "SDL Error: "
              << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  if (0 > Mix_OpenAudio(44100,              //sound frequency
          MIX_DEFAULT_FORMAT, //sample format
          2,                  //stereo hardware channels
          2048))              //chunk size
          {
    std::cerr << "SDL_mixer could not initialised! "
              "SDL_mixer Error: "
              << Mix_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void SDLLoader::deinit() {
  //Quit SDL subsystems
  IMG_Quit();
  TTF_Quit();
  Mix_Quit();
  SDL_Quit();
}

