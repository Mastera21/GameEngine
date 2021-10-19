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
	std::string windowName;
	Point windowPos = Point::UNDEFINED;
	int32_t windowWidth = 0;
	int32_t windowHeight = 0;
	WindowFlags windowFlags = WINDOW_SHOWN;
};

#endif /* SDL_CONFIG_MONITORWINDOWCFG_H_ */
