#ifndef GAME_GAME_H_
#define GAME_GAME_H_


//C system headers

//C++ system headers
#include <cstdint>
#include <vector>

//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"

struct SDL_Texture;
struct Event;


class Game {
public:

	int32_t init(const GameCfg& cfg);
	void deinit();
	void draw(std::vector<SDL_Texture* >& images);
	void handleEvent(const Event& event);

private:

	SDL_Texture *_currChosenImage = nullptr;
	SDL_Texture *_imageSurfaces[COUNT] {};

	int32_t loadResources(const std::unordered_map<GameImages,std::string>& res);

};

#endif /* GAME_GAME_H_ */
