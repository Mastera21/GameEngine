#ifndef UTILS_DRAWING_DRAWPARAMS_H_
#define UTILS_DRAWING_DRAWPARAMS_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "utils/drawing/Point.h"
#include "utils/drawing/Rectangle.h"

//Forward declarations

inline constexpr auto INVALID_RSRC_ID = -1;
inline constexpr auto FULL_OPACITY = 255;
inline constexpr auto ZERO_OPACITY = 0;

enum class WidgetType : uint8_t {
  IMAGE,
  TEXT,
  UNKNOWN
};

enum class BlendMode : uint8_t {
  NONE  = 0, //value for SDL_BLENDMODE_NONE
  BLEND = 1, //value for SDL_BLENDMODE_BLEND
  ADD   = 2, //value for SDL_BLENDMODE_ADD
  MOD   = 4  //value for SDL_BLENDMODE_MODE
};

struct DrawParams {
  //Top left position of texture
  Point pos = Point::UNDEFINED;

  Rectangle frameRect = Rectangle::ZERO;

  //Draw dimensions of the texture
  int32_t width = 0;
  int32_t height = 0;

  int32_t opacity = FULL_OPACITY;

  //unique resourceId
  union {
	  int32_t rsrcId = INVALID_RSRC_ID;
	  int32_t textId;
  };

  WidgetType widgetType = WidgetType::UNKNOWN;

  void reset();
};

#endif /* UTILS_DRAWING_DRAWPARAMS_H_ */
