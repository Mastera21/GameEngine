#ifndef GAME_BOARD_MOVESELECTOR_H_
#define GAME_BOARD_MOVESELECTOR_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <array>
//Other libraries headers

//Own components headers
#include "game/defines/ChessStructs.h"
#include "manager/drawing/Image.h"
//Forward declarations

class MoveSelector {
public:
	int32_t init(int32_t rsrcId);
	void draw();
	void marktTiles(const std::vector<TileData> &markedTiles);
	void unmarkTiles();
private:
  enum InternalDefines {
    MAX_ACTIVE_TILES = 28
  };

  std::array<Image, MAX_ACTIVE_TILES> _tileImgs;
  size_t _activeTiles { 0 };
};

#endif /* GAME_BOARD_MOVESELECTOR_H_ */
