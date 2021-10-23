#ifndef SDL_CONTAINERS_TEXTCONTAINER_H_
#define SDL_CONTAINERS_TEXTCONTAINER_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
#include <unordered_map>
//Other libraries headers

//Own components headers
#include "sdl/config/TextContainerCfg.h"
#include "utils/drawing/Color.h"

//Forward declarations
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

class TextContainer {
public:

	int32_t init(const TextContainerCfg& cfg);
	void deinit();

	void createText(const char *text, const sd::Color &color, int32_t fontId, int32_t &outTextId,
							int32_t &outTextWidth,
							int32_t &outTextHeight);

	void reloadText(const char *text, const sd::Color &color, int32_t fontId,
	                         int32_t textId, int32_t &outTextWidth,
	                         int32_t &outTextHeight);

	void unloadText(int32_t textId);

	SDL_Texture* getTextTexture(int32_t textId) const;

private:
  //the textures we'll be drawing
  std::vector<SDL_Texture*> _textures;

  std::unordered_map<int32_t, TTF_Font*> _fonts;
};

#endif /* SDL_CONTAINERS_TEXTCONTAINER_H_ */
