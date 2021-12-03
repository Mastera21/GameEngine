//C system headers

//C++ system headers
#include <cstdint>
#include <vector>
//Other libraries headers

//Own components headers

//Forward declarations
struct SDL_Texture;
class Color;

class FboContainer {
public:
    void createFbo(int32_t fboWidth, int32_t fboHeight, int32_t &outFboId);
    void unloadFbo(int32_t fboId);
    SDL_Texture* getFboTexture(int32_t fboId) const;

protected:
	int32_t init();
	void deinit();

private:
    //the textures we'll be drawing
	std::vector<SDL_Texture*> _textures;

  	void occupyFreeSlotIndex(int32_t& outIdx, SDL_Texture* texture);
	void freeSlotIndex(int32_t index);
};