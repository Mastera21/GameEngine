#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "engine/Engine.h"

//Forward declarations
struct SDLLoader;

class Application {
public:
	void run();

private:
	Engine _engine;

	int32_t init();
};

#endif /* APPLICATION_APPLICATION_H_ */
