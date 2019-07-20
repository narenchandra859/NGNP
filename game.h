#ifndef GAME_H
#define GAME_H

class Graphics;		// forward declare, no incl. graphics.h

class Game {
	public:
		Game();
		~Game();
	private:
		void gameLoop();
		void draw(Graphics& graphics);
		void update(float elapsedTime);
};	
#endif