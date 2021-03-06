#ifndef SDL_CONTAINERS_IMAGECONTAINER_H_
#define SDL_CONTAINERS_IMAGECONTAINER_H_

//C system headers

//C++ system headers
#include <cstring>
#include <unordered_map>
#include <vector>
//Other libraries headers

//Own components headers
#include "utils/drawing/Rectangle.h"
#include "sdl/config/ImageContainerCfg.h"

//Forward declarations
struct SDL_Texture;

using Frames = std::vector<Rectangle>;

class ImageContainer {
public:
	SDL_Texture* getImageTexture(int32_t rsrcId) const;

	const Frames& getImageFrame(int32_t rsrcId) const;

protected:

	int32_t init(const ImageContainerCfg& cfg);
	void deinit();

private:
	//the textures we'll be drawing
	 std::unordered_map<int32_t, SDL_Texture*> _textures;

	 std::unordered_map<int32_t, Frames> _textureFrames;

	 int32_t loadSingleResource(const ImageCfg& resCfg, int32_t rsrcId);
};

#endif /* SDL_CONTAINERS_IMAGECONTAINER_H_ */
