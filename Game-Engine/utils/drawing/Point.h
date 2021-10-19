#ifndef UTILS_POINT_H_
#define UTILS_POINT_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers


//Own components headers


//Forward declarations


struct Point {
public:
	Point() = default;
	Point(int32_t x,int32_t y);

	int32_t x = 0;
	int32_t y = 0;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	static const Point ZERO;
	static const Point UNDEFINED;
};

#endif /* UTILS_POINT_H_ */
