#ifndef GAME_LOGIC_GAMELOGIC_H_
#define GAME_LOGIC_GAMELOGIC_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers

//Forward declarations

class GameLogic{
public:
	GameLogic();

	int32_t getActivePlayerId() const;
	void finishTurn();

private:
	int32_t _activePlayerId;
};
#endif /* GAME_LOGIC_GAMELOGIC_H_ */
