#ifndef GRAPHICS_H		// include guard
#define GRAPHICS_H
#include <map>
#include <string>
using namespace std;
struct SDL_Window;		// forward declare 
struct SDL_Renderer;	// no need to incl SDL.h, diff to debug
						// not good to incl files in our headers
class Graphics {
	public:
		Graphics();
		~Graphics();
		
		SDL_Surface* loadImage(const std::string& filePath);	// Loads image into _spritesheets map
																// if it doesn't exist
		// Draws textures to the screen
		void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
		
		// Renders everything to screen
		void flip();

		// Clears screen
		void clear();

		/*
		For every frame, first we clear out the render 
		blitSurface draws to that render
		then flip renders it to the screen
		*/

		const SDL_Renderer* getRenderer(); // return the render to use it elsewhere

	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		map<string, SDL_Surface*> _spriteSheets;				// so we only load images once, not repeatedly
		
};

#endif