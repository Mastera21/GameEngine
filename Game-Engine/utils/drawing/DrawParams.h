#ifndef UTILS_DRAWING_DRAWPARAMS_H_
#define UTILS_DRAWING_DRAWPARAMS_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers


//Own components headers
#include "utils/drawing/Point.h"

//Forward declarations

inline constexpr auto INVALID_RSRC_ID = -1;

struct DrawParams {
  //Top left position of texture
  Point pos = Point::UNDEFINED;

  //Draw dimensions of the texture
  int32_t width = 0;
  int32_t height = 0;

  //unique resourceId
  int32_t rsrcId = INVALID_RSRC_ID;
};



#endif /* UTILS_DRAWING_DRAWPARAMS_H_ */
