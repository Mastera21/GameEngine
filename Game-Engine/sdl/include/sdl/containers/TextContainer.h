#ifndef SDL_CONTAINERS_TEXTCONTAINER_H_
#define SDL_CONTAINERS_TEXTCONTAINER_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <string>
//Other libraries headers

//Own components headers
#include "sdl/config/TextContainerCfg.h"

//Forward declarations
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
struct Color;

class TextContainer {
public:

	void createText(const std::string& text, const Color &color, int32_t fontId, int32_t &outTextId,
							int32_t &outTextWidth,
							int32_t &outTextHeight);

	void reloadText(const std::string& text, const Color &color, int32_t fontId,
	                         int32_t textId, int32_t &outTextWidth,
	                         int32_t &outTextHeight);

	void unloadText(int32_t textId);

	SDL_Texture* getTextTexture(int32_t textId) const;

protected:

	int32_t init(const TextContainerCfg& cfg);
	void deinit();

private:
  //the textures we'll be drawing
	std::vector<SDL_Texture*> _textures;

  	std::unordered_map<int32_t, TTF_Font*> _fonts;

  	void occupyFreeSlotIndex(int32_t& outIdx, SDL_Texture* texture);
	void freeSlotIndex(int32_t index);
};

#endif /* SDL_CONTAINERS_TEXTCONTAINER_H_ */
