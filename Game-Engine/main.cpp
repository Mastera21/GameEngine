//C system headers

//C++ system headers
#include <cstdint>
#include <cstdlib>
//Other libraries headers

//Own components headers
#include "application/Application.h"

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char** args) {

	Application app;
	app.run();

	return EXIT_SUCCESS;
}
