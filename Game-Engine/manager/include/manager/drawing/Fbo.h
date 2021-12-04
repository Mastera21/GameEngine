#ifndef MANAGER_INCLUDE_MANAGER_DRAWING_FBO_H_
#define MANAGER_INCLUDE_MANAGER_DRAWING_FBO_H_
//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
//Other libraries headers

//Own components headers
#include "manager/drawing/Widget.h"
#include "utils/drawing/Color.h"
//Forward declarations


class FBO : public Widget{ 
public:
    ~FBO();

    void create(int32_t width, int32_t height, const Point& pos, const Color& clearColor);
    void destroy();
    void unlock();
    void lock();
    void reset();
    void addWidget(const Widget &widget);
    void update() const;

private:
  std::vector<DrawParams> _storedItems;
  Color _clearColor = Colors::BLACK;
  bool _isLocked = true;

};
#endif /* MANAGER_INCLUDE_MANAGER_DRAWING_FBO_H_ */