//Corresponding header
#include "sdl/MonitorWindow.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SDL_video.h>

//Own components headers

MonitorWindow::~MonitorWindow() {
  deinit();
}

int32_t MonitorWindow::init(const MonitorWindowCfg &cfg) {
  Point initWindowPos = cfg.windowPos;

  if (Point::UNDEFINED == cfg.windowPos) {
    initWindowPos.x = SDL_WINDOWPOS_UNDEFINED;
    initWindowPos.y = SDL_WINDOWPOS_UNDEFINED;
  }

  _windowRect.w = cfg.windowWidth;
  _windowRect.h = cfg.windowHeight;

  //Create window
  _window = SDL_CreateWindow(cfg.windowName.c_str(), initWindowPos.x,
      initWindowPos.y, _windowRect.w, _windowRect.h, cfg.displayMode);

  if (nullptr == _window) {
    std::cerr << "Window could not be created! SDL Error: " << SDL_GetError()
              << std::endl;
    return EXIT_FAILURE;
  }

  //obtain real window coordinates after creation
  SDL_GetWindowPosition(_window, &_windowRect.x, &_windowRect.y);

  return EXIT_SUCCESS;
}

void MonitorWindow::deinit() {
  if (_window) //sanity check
  {
    SDL_DestroyWindow(_window);
    _window = nullptr;
  }
}

SDL_Window* MonitorWindow::getWindow() const {
  return _window;
}
