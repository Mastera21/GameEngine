#ifndef SDL_MONITORWINDOW_H_
#define SDL_MONITORWINDOW_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <string>

//Other libraries headers

//Own components headers
#include "sdl/config/MonitorWindowCfg.h"
//#include "sdl/Event.h"

//Forward declarations
struct SDL_Window;
struct SDL_Surface;


namespace sd{

class MonitorWindow {
public:
	MonitorWindow() = default;
	~MonitorWindow();

	MonitorWindow(const MonitorWindow& other) = delete;
	MonitorWindow(MonitorWindow&& other) = delete;

	MonitorWindow& operator=(const MonitorWindow& other) = delete;
	MonitorWindow& operator=(MonitorWindow&& other) = delete;

	int32_t init(const MonitorWindowCofg& cfg);

	void deinit();
	void updateWindowSurface();

	SDL_Window* getWindow();

private:
	SDL_Window* _window = nullptr;
};
}

#endif /* SDL_MONITORWINDOW_H_ */
