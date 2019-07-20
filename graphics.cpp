// Implementation of the graphics class
#include "SDL_image.h"
#include "graphics.h"
// All info regarding graphics of our game
#include <SDL.h>
#include "globals.h"
using namespace std;

// Constructor creates the window and sets the title

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &_window, &_renderer); // Game window is 1080x720
	SDL_SetWindowTitle(_window, "NGNP");
}
// Destructor just destroys the window
Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
}

SDL_Surface* Graphics::loadImage(const string& filePath) {
	if (_spriteSheets.count(filePath) == 0) {					// tells how many exist with the specific key
		_spriteSheets[filePath] = IMG_Load(filePath.c_str());	// if its 0, we load the image
	}
	return _spriteSheets[filePath];
}

/*
SDL_RenderCopy -> copies whatever you pass to the renderer
*/
void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}
/*
SDL_RenderPresent -> just draws it (renderer) to the screen
*/
void Graphics::flip() {
	SDL_RenderPresent(_renderer);
}
/*
SDL_RenderClear -> clears the renderer out
*/
void Graphics::clear() {
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
	return _renderer;
}