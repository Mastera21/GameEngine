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
struct TextContainer;

class Game {
public:

	int32_t init(const GameCfg cfg, const ImageContainer* _imgContainerInterface, TextContainer* _textContainerInterface);
	void deinit();
	void draw(std::vector<DrawParams>& images);
	void handleEvent(const sd::Event& event);

private:

	DrawParams pressKeyImage;//first image
	DrawParams layer2Image;//second image
	DrawParams helloText;

	DrawParams pressText;
	DrawParams hideText;

	bool isPressTextHidden = false;

	//TODO Remove me !!!
	const ImageContainer* _imgContainer = nullptr;
	TextContainer* _textContainer = nullptr;

};

#endif /* GAME_GAME_H_ */
