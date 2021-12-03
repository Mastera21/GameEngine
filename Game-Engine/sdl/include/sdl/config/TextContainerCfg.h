#ifndef SDL_CONFIG_TEXTCONTAINERCFG_H_
#define SDL_CONFIG_TEXTCONTAINERCFG_H_

//C system headers

//C++ system headers
#include <cstring>
#include <unordered_map>
//Other libraries headers

//Own components headers

//Forward declarations

struct FontCfg {
  std::string location;
  int32_t fontSize = 0;
};

struct TextContainerCfg {
  std::unordered_map<int32_t, FontCfg> fontConfigs;
};
#endif /* SDL_CONFIG_TEXTCONTAINERCFG_H_ */
