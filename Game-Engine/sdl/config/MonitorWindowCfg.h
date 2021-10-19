#ifndef SDL_CONFIG_MONITORWINDOWCFG_H_
#define SDL_CONFIG_MONITORWINDOWCFG_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <string>
//Other libraries headers

//Own components headers
#include "utils/drawing/Point.h"

//Forward declarations

enum WindowFlags{
	WINDOW_SHOWN = 4, //SDL_WINDOW_SHOWN
	WINDOW_FULLSCREEN_DESKTOP = 4097 // SDL_WINDOW_FULLSCREEN_DESKTOP
};

struct MonitorWindowCofg{
	const std::string displayMode = "Engine";
	Point windowPos = Point::UNDEFINED;
	const int32_t width = 640;
	const int32_t height = 480;
	WindowFlags flag = WINDOW_SHOWN;
};

#endif /* SDL_CONFIG_MONITORWINDOWCFG_H_ */
