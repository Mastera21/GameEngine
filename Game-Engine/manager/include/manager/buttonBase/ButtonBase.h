#ifndef MANAGER_INCLUDE_MANAGER_BUTTONBASE_BUTTONBASE_H_
#define MANAGER_INCLUDE_MANAGER_BUTTONBASE_BUTTONBASE_H_

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "manager/drawing/Image.h"
#include "sdl/Event.h"
//Forward declarations

enum ButtonStates {
  UNCLICKED, CLICKED, DISABLED
};

class ButtonBase  : public Image{
public:

	virtual ~ButtonBase() = default;

	virtual void handleEvent(const sd::Event &e) = 0;

	virtual void draw();

	void lockInput();
	void unlockInput();

	bool isInputUnlocked() const;

	bool containsEvent(const sd::Event &e);

private:

	bool _isInputUnlocked = true;
};

#endif /* MANAGER_INCLUDE_MANAGER_BUTTONBASE_BUTTONBASE_H_ */
