#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_


//C system headers

//C++ system headers
#include <cstdint>
#include <unordered_map>

//Other libraries headers

//Own components headers

enum GameImages {
	 UP, DOWN, LEFT, RIGHT, PRESS_KEYS, LAYER_2, COUNT
};

struct GameCfg{
	std::unordered_map<GameImages,std::string> imagesPaths;

};



#endif /* GAME_CONFIG_GAMECFG_H_ */
