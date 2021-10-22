#ifndef GAME_GAME_H_
#define GAME_GAME_H_


//C system headers

//C++ system headers
#include <cstdint>
#include <vector>

//Other libraries headers

//Own components headers
#include "game/config/GameCfg.h"
#include "utils/drawing/DrawParams.h"
#include "sdl/Event.h"

//Forward declarations
struct ImageContainer;

class Game {
public:

	int32_t init(const GameCfg cfg, const ImageContainer* _imgContainerInterface);
	void deinit();
	void draw(std::vector<DrawParams>& images);
	void handleEvent(const sd::Event& event);

private:

	DrawParams pressKeyImage;//first image
	DrawParams layer2Image;//second image

	//TODO Remove me !!!
	const ImageContainer* _imgContainer = nullptr;

};

#endif /* GAME_GAME_H_ */
