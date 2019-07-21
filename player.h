#ifndef PLAYER_H
#define PLAYER_H
class Graphics;
using namespace std;
#include "animSprite.h"
#include "globals.h"
class Player : public AnimatedSprite {
	public:
		Player();
		Player(Graphics& graphics, float x, float y); // x,y start pos of player
		void draw(Graphics& graphics);
		void update(float elapsedTime);
		virtual void animationDone(string currentAnimation); // extended from AnimatedSprite
		virtual void setupAnimations();
		void moveLeft();	// move player left by -ve dx 
		void moveRight();	// move player right by dx
		void stopMoving();	// stops moving the player + play idle animation 
	private:
		float _dx, _dy;		// change in x and y positons during the frame
		Direction _facing;

};

#endif 