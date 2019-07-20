// Implementation of our main game loop 
#include "game.h"
#include <algorithm>
#include <SDL.h>
#include "graphics.h"
#include "input.h"
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);	// Initializes everything
	gameLoop();
}
Game::~Game() {

}
namespace {
	const int FPS = 60;		// limits FPS
	const int MAX_FRAME_TIME = 6 * 1000 / FPS; // max time per frame
}
void Game::gameLoop() {
	Graphics graphics;
	SDL_Event event;		// SDL checks for all types of events and stores it here
	Input input;
	player = Sprite(graphics, "Content/Sprites/MyChar.png", 0, 0, 16, 16, 250, 250);
	int LAST_UPDATE_TIME = SDL_GetTicks(); // number of ms before SDL was init'd
	while (1) {	
		input.beginNewFrame();			// at start of each frame, start a new frame
		if (SDL_PollEvent(&event)) {	// SDL finds out what event
			if (event.type == SDL_QUIT) {		// for exiting game
				return;
			}
			else if (event.type == SDL_KEYDOWN) {	// SDL tells us a key is pressed
				if (event.key.repeat == 0) {	// checks if its held down or single press
					input.keyDownEvent(event);	// pass the event if its a single press
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {	
			return;											// pressing ESC also closes the game now
		}
	// before the loop ends, we need to set the time
	const int CURRENT_TIME_MS = SDL_GetTicks();
	// diff b/w curr_time_ms and last_upd_time = how long this frame took.
	int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;		

	update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));		// here, if elapsed time < max frame time, its fine
														// if it took more time, just use our max time so
														// it doesn't go over 50 fps (slow PC vs fast PC -> fast PC will win if we don't)
														// so we get the same dist on both fast and slow PCs (physics has to be same)
	LAST_UPDATE_TIME = CURRENT_TIME_MS;
	draw(graphics);
	}
}
void Game::draw(Graphics& graphics) {
	graphics.clear();
	player.draw(graphics, 250, 250);
	graphics.flip();
}
void Game::update(float elapsedTime) {

}