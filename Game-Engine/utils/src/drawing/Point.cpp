#include "utils/drawing/Point.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

const Point Point::ZERO(0,0);
const Point Point::UNDEFINED(10000,10000);

Point::Point(int32_t inputX,int32_t inputY) : x(inputX),y(inputY){}

bool Point::operator==(const Point& other) const{
	return (x == other.x) && (y == other.y);
}

bool Point::operator!=(const Point& other) const{
	return !operator==(other);
}
