#include "player.h"
#include "graphics.h"
using namespace std;

// find out why player is moving too fast, can't see all 4/4 frames in RunRight and RunLeft animations
// same with the idle animations

namespace player_constants {		// player physics
	const float WALK_SPEED = 0.3f;
}
Player::Player() {}
Player::Player(Graphics& graphics, float x, float y) :
	AnimatedSprite(graphics, "Content/Sprites/MyChar.png", 0, 0, 30, 41, x, y, 100)
{
	graphics.loadImage("Content/Sprites/MyChar.png");		// why?
	setupAnimations();
	playAnimation("RunRight");
}
void Player::setupAnimations() {
	addAnimation(4, 0, 0, "IdleRight", 50, 37, Vector2(0, 0));
	addAnimation(4, 500, 0, "IdleLeft", 50, 37, Vector2(0, 0));
	addAnimation(6, 50, 37, "RunRight", 50, 37, Vector2(0, 0));
	addAnimation(6, 350, 37, "RunLeft", 50, 37, Vector2(0, 0));
	
}
void Player::animationDone(string currentAnimation) {
}
void Player::moveLeft() {
	_dx = -player_constants::WALK_SPEED;
	playAnimation("RunLeft");
	_facing = LEFT;
}
void Player::update(float elapsedTime) {
	// move the player by dx
	_x += _dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}
void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, _x, _y);		// _x, _y from sprite class
}
void Player::moveRight() {
	_dx = player_constants::WALK_SPEED;
	playAnimation("RunRight");
	_facing = RIGHT;
}
void Player::stopMoving() {
	_dx = 0;
	playAnimation(_facing == RIGHT ? "IdleRight" : "IdleLeft");
}