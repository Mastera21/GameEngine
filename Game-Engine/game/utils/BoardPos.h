#ifndef GAME_UTILS_BOARDPOS_H_
#define GAME_UTILS_BOARDPOS_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers

//Forward declarations

struct BoardPos{
	BoardPos() = default;
	BoardPos(int32_t inputRow, int32_t inputCol) : row(inputRow), col(inputCol){}

	int32_t row = 0;
	int32_t col = 0;
};


#endif /* GAME_UTILS_BOARDPOS_H_ */
