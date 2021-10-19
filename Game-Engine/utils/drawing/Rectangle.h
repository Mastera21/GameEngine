#ifndef UTILS_RECTANGLE_H_
#define UTILS_RECTANGLE_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers


//Own components headers
#include "utils/drawing/Point.h"

//Forward declarations

class Rectangle {
public:
	Rectangle() = default;
	Rectangle(int32_t inputX,int32_t inputY,int32_t inputWidth,int32_t inputHeight);

	int32_t x = 0;
	int32_t y = 0;
	int32_t w = 0;
	int32_t h = 0;

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool isPointInside(const Point& point) const;

	static const Rectangle ZERO;
	static const Rectangle UNDEFINED;
};

#endif /* UTILS_RECTANGLE_H_ */
