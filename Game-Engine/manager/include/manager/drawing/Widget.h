#ifndef MANAGER_INCLUDE_MANAGER_DRAWING_WIDGET_H_
#define MANAGER_INCLUDE_MANAGER_DRAWING_WIDGET_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "utils/drawing/DrawParams.h"
//Forward declarations

struct Widget {
public:
	void draw();

	//setters & getters

	void reset();
	void setPos(const Point& pos);
	void setPos(int32_t x, int32_t y);
	void setOpacity(int32_t opacity);

	int32_t getOpacity() const;
	Point getPos() const;

	void activateAlphaModulation();
	void deactivateAlphaModulation();
	void show();
	void hide();

	void moveUp(int32_t y);
	void moveDown(int32_t y);
	void moveLeft(int32_t x);
	void moveRight(int32_t x);

protected:
	DrawParams _drawParams;

	bool _isCreated = false;
	bool _isVisible = true;
	bool _isAlphaModulationEnabled = false;
};
#endif /* MANAGER_INCLUDE_MANAGER_DRAWING_WIDGET_H_ */
