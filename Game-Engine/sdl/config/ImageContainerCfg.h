#ifndef SDL_CONFIG_IMAGECONTAINERCFG_H_
#define SDL_CONFIG_IMAGECONTAINERCFG_H_

//C system headers

//C++ system headers
#include <cstring>
#include <unordered_map>
//Other libraries headers

//Own components headers

//Forward declarations

struct ImageCfg {
  std::string location;
  int32_t width = 0;
  int32_t height = 0;
};

struct ImageContainerCfg {
  std::unordered_map<int32_t, ImageCfg> imageConfigs;
};

#endif /* SDL_CONFIG_IMAGECONTAINERCFG_H_ */
