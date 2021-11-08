#ifndef GAME_UTILS_BOARDUTILS_H_
#define GAME_UTILS_BOARDUTILS_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "game/utils/BoardPos.h"
#include "utils/drawing/Point.h"
//Forward declarations

class BoardUtils {
public:
	static BoardPos getBoardPos(const Point &absPos);

	static Point getAbsPos(const BoardPos& boardPos);

	static bool isInsideBoard(const BoardPos& boardPos);

	static bool isInsideBoard(const Point& absPos);
};

#endif /* GAME_UTILS_BOARDUTILS_H_ */
