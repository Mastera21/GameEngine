#ifndef COMMON_COMMONDEFINES_H_
#define COMMON_COMMONDEFINES_H_

//C system headers

//C++ system headers

//Other libraries headers
#include <iostream>

//Own components headers

//Forward declarations
namespace TextureId{
enum ResourseId{
	 CHESS_BOARD, TARGET, WHITE_PIECES, BLACK_PIECES, MOVE_TAIL, PROMOTION_BUTTON
};
}//namespace TextureId

namespace FontId{
enum FontIdKeys{
	ANGELINE_VINTAGE
};
}//namespace FontId

namespace TimerId{
enum Keys{
	BLINK_TARGET_TIMER_ID
};
}//namespace TimerId

#endif /* COMMON_COMMONDEFINES_H_ */
