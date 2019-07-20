// Implementation of input class (keyboard handling)
#include "input.h"
// called at end of each frame to reset keys (that are not relevent)
void Input::beginNewFrame() {
	_pressedKeys.clear();
	_releasedKeys.clear();
}
// called when a key is pressed
void Input::keyDownEvent(const SDL_Event& event) {
	_pressedKeys[event.key.keysym.scancode] = true;		// set the pressed keys scancode to TRUE in map
	_heldKeys[event.key.keysym.scancode] = true;		// same holds for held key
}
// called when key is released
void Input::keyUpEvent(const SDL_Event& event) {
	_releasedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = false;		
}
 
bool Input::wasKeyPressed(SDL_Scancode key) {
	return _pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return _releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
	return _heldKeys[key];
}