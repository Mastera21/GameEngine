#include "utils/drawing/Color.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers


namespace Colors {
const Color RED(255, 0, 0, 255);
const Color GREEN(0, 255, 0, 255);
const Color BLUE(0, 0, 255, 255);
const Color BLACK(0, 0, 0, 255);
const Color WHITE(255, 255, 255, 255);
const Color GRAY(192, 192, 192, 255);
const Color CYAN(0, 255, 255, 255);
const Color MAGENTA(255, 0, 255, 255);
const Color YELLOW(255, 255, 0, 255);
const Color ORANGE(255, 128, 0, 255);
const Color PURPLE(128, 0, 128, 255);
const Color FULL_TRANSPARENT(0, 0, 0, 0);
} //namespace Colors

Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha){
	rgba.r = red;
	rgba.g = green;
	rgba.b = blue;
	rgba.a = alpha;
}

bool Color::operator==(const Color& other) const{
	return (rgba.r == other.rgba.r) && (rgba.g == other.rgba.g) && (rgba.b == other.rgba.b) && (rgba.a == other.rgba.a);
}
bool Color::operator!=(const Color& other) const{
	return !Color::operator ==(other);
}

