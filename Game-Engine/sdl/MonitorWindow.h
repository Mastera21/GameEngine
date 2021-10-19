#ifndef SDL_MONITORWINDOW_H_
#define SDL_MONITORWINDOW_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <string>

//Other libraries headers

//Own components headers
#include "utils/drawing/Point.h"
#include "utils/drawing/Rectangle.h"

//Forward declarations
struct SDL_Window;

struct MonitorWindowCfg {
  //Window modes:
  //SDL_WINDOW_SHOWN - for windowed version
  //SDL_WINDOW_FULLSCREEN_DESKTOP - for fullscreen
  int32_t displayMode { 0 };
  int32_t windowWidth { 0 };
  int32_t windowHeight { 0 };
  Point windowPos = Point::UNDEFINED;
  std::string windowName;
};

class MonitorWindow {
public:
  MonitorWindow() = default;

  //forbid the copy and move constructors
  MonitorWindow(const MonitorWindow &other) = delete;
  MonitorWindow(MonitorWindow &&other) = delete;

  //forbid the copy and move assignment operators
  MonitorWindow& operator=(const MonitorWindow &other) = delete;
  MonitorWindow& operator=(MonitorWindow &&other) = delete;

  ~MonitorWindow();

  int32_t init(const MonitorWindowCfg &cfg);

  void deinit();

  SDL_Window *getWindow() const;

private:
  //The actual window
  SDL_Window *_window = nullptr;
  Rectangle _windowRect = Rectangle::UNDEFINED;
};

#endif /* SDL_MONITORWINDOW_H_ */
