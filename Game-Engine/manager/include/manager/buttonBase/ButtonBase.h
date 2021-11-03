#ifndef MANAGER_INCLUDE_MANAGER_BUTTONBASE_BUTTONBASE_H_
#define MANAGER_INCLUDE_MANAGER_BUTTONBASE_BUTTONBASE_H_

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "manager/drawing/Image.h"
//Forward declarations

enum ButtonStates {
  UNCLICKED, CLICKED, DISABLED
};

class ButtonBase {
  Image _buttonTexture;
  Rectangle _boundRect = Rectangle::ZERO;
  bool _isInputUnlocked = true;
};

#endif /* MANAGER_INCLUDE_MANAGER_BUTTONBASE_BUTTONBASE_H_ */
