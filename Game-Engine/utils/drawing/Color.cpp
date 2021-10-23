#include "Color.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

sd::Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha){
	rgba.r = red;
	rgba.g = green;
	rgba.b = blue;
	rgba.a = alpha;
}

namespace Colors {
const sd::Color RED(255, 0, 0, 255);
const sd::Color GREEN(0, 255, 0, 255);
const sd::Color BLUE(0, 0, 255, 255);
const sd::Color BLACK(0, 0, 0, 255);
const sd::Color WHITE(255, 255, 255, 255);
const sd::Color GRAY(192, 192, 192, 255);
const sd::Color CYAN(0, 255, 255, 255);
const sd::Color MAGENTA(255, 0, 255, 255);
const sd::Color YELLOW(255, 255, 0, 255);
const sd::Color ORANGE(255, 128, 0, 255);
const sd::Color PURPLE(128, 0, 128, 255);
const sd::Color FULL_TRANSPARENT(0, 0, 0, 0);
} //namespace Colors
