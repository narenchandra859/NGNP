#ifndef INPUT_H
#define INPUT_H
using namespace std;
#include <map>		//	Standard STL map
#include <SDL.h>
class Input {
	public:
		void beginNewFrame();		// called at end of every frame
		void keyUpEvent(const SDL_Event& event);	// event handler for key being pressed
		void keyDownEvent(const SDL_Event& event);
		bool wasKeyPressed(SDL_Scancode key);		// pass any key to find out whether its being
		bool wasKeyReleased(SDL_Scancode key);		// held pressed or released
		bool isKeyHeld(SDL_Scancode key);
	private:
		map<SDL_Scancode, bool> _heldKeys;		// Scancode values reprt the keyboard keys
		map<SDL_Scancode, bool>	_pressedKeys;	// 3 maps to hold the inputs, for held, pressed and released
		map<SDL_Scancode, bool> _releasedKeys;	
};
#endif
