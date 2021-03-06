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
	//setters & getters
	int32_t getOpacity() const;
	Point getPos() const;

	int32_t getWidth() const;
	int32_t getHeight()const;

	int32_t getX() const;
	int32_t getY() const;

	int32_t getRsrcId() const;
	double getRotation() const;

	DrawParams getDrawParams() const;

	bool containsPoint(const Point& pos) const;
	bool isVisible() const;
	bool isCreated() const;

	void draw();
	void reset();

	void setFlipType(WidgetFlip flipType);
	void setRotation(double angle);

	void setRotationCenter(const Point& pos);

	void setPos(const Point& pos);
	void setPos(int32_t x, int32_t y);
	void setOpacity(int32_t opacity);

	void rotateRight(double radius);
	void rotateLeft(double radius);

	void activateAlphaModulation();
	void deactivateAlphaModulation();

	void show();
	void hide();

	void moveUp(int32_t y);
	void moveDown(int32_t y);
	void moveLeft(int32_t x);
	void moveRight(int32_t x);

	void setWidth(int32_t width);
	void setHeight(int32_t height);

protected:
	DrawParams _drawParams;

	bool _isDestroyed = true;
	bool _isCreated = false;
	bool _isVisible = true;
	bool _isAlphaModulationEnabled = false;
};
#endif /* MANAGER_INCLUDE_MANAGER_DRAWING_WIDGET_H_ */
