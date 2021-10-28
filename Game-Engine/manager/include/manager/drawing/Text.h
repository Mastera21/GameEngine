#ifndef MANAGER_INCLUDE_MANAGER_DRAWING_TEXT_H_
#define MANAGER_INCLUDE_MANAGER_DRAWING_TEXT_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <string>
//Other libraries headers

//Own components headers
#include "manager/drawing/Widget.h"
#include "utils/drawing/Color.h"
//Forward declarations

class Text : public Widget {
public:
	~Text();
	void create(const std::string& text,  int32_t fontId, const Color& color, const Point &pos = Point::ZERO);
	void destroy();
	void setText(const std::string& text);
	void setColor(const Color& color);
	std::string getTextContent() const;

private:
	std::string _textContent;
	Color _color = Colors::BLACK;
	int32_t _fontId = false;
};

#endif /* MANAGER_INCLUDE_MANAGER_DRAWING_TEXT_H_ */
