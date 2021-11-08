#include "sdl/Event.h"

#include <iostream>
#include <cstring>

//Other libraries headers
#include <SDL_events.h>

//Own components headers

int32_t Event::init(){
	_sdlEvent = new SDL_Event{};
	memset(_sdlEvent,0,sizeof(SDL_Event));
	if(_sdlEvent == nullptr){
		std::cerr<<"Bad alloc for SDL_Event()"<<"\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
void Event::deinit(){
	if(_sdlEvent != nullptr){
		delete _sdlEvent;
		_sdlEvent = nullptr;
	}
}
bool Event::pollEvent(){
	if(0 == SDL_PollEvent(_sdlEvent)){
		//no events currently
		return false;
	}
	SDL_GetMouseState(&pos.x,&pos.y);
	setEventTypeInternal();
	return true;
}
bool Event::checkForExitRequest() const{
	return (_sdlEvent->type ==  EventType::QUIT) || (type == TouchEvent::KEYBOARD_PRESS && Keyboard::KEY_ESCAPE == key);
}

void Event::setEventTypeInternal(){
	 switch (_sdlEvent->type) {

	  case EventType::KEYBOARD_PRESS:
		  key = _sdlEvent->key.keysym.sym;
		  mouseButton = Mouse::UNKNOWN;
		  type = TouchEvent::KEYBOARD_PRESS;
	    break;
	  case EventType::KEYBOARD_RELEASE:
		  key = _sdlEvent->key.keysym.sym;
		  mouseButton = Mouse::UNKNOWN;
		  type = TouchEvent::KEYBOARD_RELEASE;
	    break;

	    //NOTE: the fall-through is intentional
	  case EventType::MOUSE_PRESS:
		  key = Keyboard::KEY_UNKNOWN;
		  mouseButton = _sdlEvent->button.button;
		  type = TouchEvent::TOUCH_PRESS;
		  break;
	  case EventType::FINGER_PRESS:
		  key = Keyboard::KEY_UNKNOWN;
		  mouseButton = Mouse::UNKNOWN;
		  type = TouchEvent::TOUCH_PRESS;
	    break;

	  case EventType::MOUSE_RELEASE:
		  key = Keyboard::KEY_UNKNOWN;
		  mouseButton = _sdlEvent->button.button;
		  type = TouchEvent::TOUCH_RELEASE;
		  break;
	  case EventType::FINGER_RELEASE:
		  key = Keyboard::KEY_UNKNOWN;
		  mouseButton = Mouse::UNKNOWN;
		  //type = TouchEvent::TOUCH_RELEASE;
		  type = TouchEvent::TOUCH_PRESS;
	    break;

	    //X is pressed on the window (or CTRL-C signal is sent)
	  case EventType::QUIT:
		  key = Keyboard::KEY_UNKNOWN;
		  mouseButton = Mouse::UNKNOWN;
		  type = TouchEvent::UNKNOWN;
	    break;

	  default:
		  key = Keyboard::KEY_UNKNOWN;
		  mouseButton = Mouse::UNKNOWN;
		  type = TouchEvent::UNKNOWN;
	    break;
	 }
}


