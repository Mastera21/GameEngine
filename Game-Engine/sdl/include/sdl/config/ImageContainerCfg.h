#ifndef SDL_CONFIG_IMAGECONTAINERCFG_H_
#define SDL_CONFIG_IMAGECONTAINERCFG_H_

//C system headers

//C++ system headers
#include <cstring>
#include <unordered_map>
#include <vector>
//Other libraries headers

//Own components headers
#include "utils/drawing/Rectangle.h"
//Forward declarations

struct ImageCfg {
  std::string location;
  std::vector<Rectangle> frames;
};
struct ImageContainerCfg {
  std::unordered_map<int32_t, ImageCfg> imageConfigs;
};

#endif /* SDL_CONFIG_IMAGECONTAINERCFG_H_ */
