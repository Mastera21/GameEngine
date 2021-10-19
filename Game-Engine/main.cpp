//C system headers

//C++ system headers
#include <cstdint>
#include <iostream>

//Other libraries headers
#include <SDL.h>
#include <SDL_image.h>

//Own components headers
#include "sdl/SDLLoader.h"
#include "sdl/MonitorWindow.h"
#include "sdl/Texture.h"

static int32_t initApplication(MonitorWindow &window, SDL_Surface *&image) {
  //Screen dimension constants
  constexpr int SCREEN_WIDTH = 640;
  constexpr int SCREEN_HEIGHT = 480;

  MonitorWindowCfg windowCfg;
  windowCfg.displayMode = SDL_WINDOW_SHOWN;
  windowCfg.windowWidth = SCREEN_WIDTH;
  windowCfg.windowHeight = SCREEN_HEIGHT;
  windowCfg.windowName = "SDL_Runtime";

  if (EXIT_SUCCESS != window.init(windowCfg)) {
    std::cerr << "window.init() failed" << std::endl;
    return EXIT_FAILURE;
  }

  const char *fileName = "../assets/hello.png";
  if (EXIT_SUCCESS != Texture::loadSurfaceFromFile(fileName, image)) {
    std::cerr << "Texture::loadSurfaceFromFile() failed" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

static void deinitApplication(MonitorWindow &window, SDL_Surface *&image) {
  Texture::freeSurface(image);
  window.deinit();
}

static int32_t executeApplication(MonitorWindow &window, SDL_Surface *&image) {
  //Get window surface
  SDL_Surface *screenSurface = SDL_GetWindowSurface(window.getWindow());

  //Apply(update) the image
  SDL_BlitSurface(image, nullptr, screenSurface, nullptr);

  //Update the window surface
  if (EXIT_SUCCESS != SDL_UpdateWindowSurface(window.getWindow())) {
    std::cerr << "SDL_UpdateWindowSurface() failed. SDL_Error: "
              << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  //Wait three seconds before exiting
  SDL_Delay(3000);

  return EXIT_SUCCESS;
}

static int32_t runApplication() {
  MonitorWindow window;
  SDL_Surface * image = nullptr;

  if (EXIT_SUCCESS != initApplication(window, image)) {
    std::cerr << "initApplication() failed" << std::endl;
    return EXIT_FAILURE;
  }

  if (EXIT_SUCCESS != executeApplication(window, image)) {
    std::cerr << "executeApplication() failed" << std::endl;
    return EXIT_FAILURE;
  }

  deinitApplication(window, image);

  return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char *args[]) {
  if (EXIT_SUCCESS != SDLLoader::init()) {
    std::cerr << "Error in SDLLoader::init()" << std::endl;
    return EXIT_FAILURE;
  }

  if (EXIT_SUCCESS != runApplication()) {
    std::cerr << "Error in runApplication()" << std::endl;
    return EXIT_FAILURE;
  }

  //close SDL libraries
  SDLLoader::deinit();

  return EXIT_SUCCESS;
}
