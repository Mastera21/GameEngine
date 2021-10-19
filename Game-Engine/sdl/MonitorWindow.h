#ifndef SDL_MONITORWINDOW_H_
#define SDL_MONITORWINDOW_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "sdl/config/MonitorWindowCfg.h"
#include "utils/drawing/Rectangle.h"

//Forward declarations
struct SDL_Window;
struct SDL_Surface;

class MonitorWindow {
public:
	MonitorWindow();
	virtual ~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete; //delete of copy constructor
	MonitorWindow(MonitorWindow&& other) = delete; //delete of move constructor

	MonitorWindow operator=(const MonitorWindow& other) = delete; // delete of copy and move operators
	MonitorWindow& operator=(MonitorWindow&& othre) = delete;

	int32_t init(const MonitorWindowCofg& cfg);

	void deinit();
	void updateWindowSurface();

	//TODO Remove me later
	SDL_Surface* getWindowSurface();

private:

	SDL_Window* _window = nullptr;
	Rectangle _windowRect;
};

#endif /* SDL_MONITORWINDOW_H_ */
