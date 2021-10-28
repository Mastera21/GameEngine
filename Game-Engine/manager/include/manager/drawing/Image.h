#ifndef MANAGER_INCLUDE_MANAGER_DRAWING_IMAGE_H_
#define MANAGER_INCLUDE_MANAGER_DRAWING_IMAGE_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "manager/drawing/Widget.h"
//Forward declarations

class Image : public Widget{
public:
	~Image();

	void create(int32_t rsrcId, const Point& pos = Point::ZERO);
	void destroy();
};

#endif /* MANAGER_INCLUDE_MANAGER_DRAWING_IMAGE_H_ */
