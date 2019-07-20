// Implementation of our sprite animations
#include "animSprite.h"
#include "graphics.h"
#include "sprite.h"
using namespace std;
AnimatedSprite::AnimatedSprite() {}
AnimatedSprite::AnimatedSprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),	// setup initial sprite
	_frameIndex(0),
	_timeElapsed(0),
	_timeToUpdate(timeToUpdate),
	_visible(true),
	_currentAnimationOnce(false),
	_currentAnimation("")
{}
void AnimatedSprite::addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset) {
	vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++) {								// loop through by offsetting width each time so in our png file we get diff sprites
		SDL_Rect newRect = { x + i * width, y, width, height };	// store in rectangles x+i * width as our anim doesn't start at 0,0 sometimes
		rectangles.push_back(newRect);
	}
	_animations.insert(pair<string, vector<SDL_Rect>>(name, rectangles));	// put it into the animations map
	_offsets.insert(pair<string, Vector2>(name, offset));
}
void AnimatedSprite::resetAnimations() {
	_animations.clear();
	_offsets.clear();
}
void AnimatedSprite::playAnimation(string animation, bool once) {
	_currentAnimation = once;
	if (_currentAnimation != animation) {	// if its not the animation, start playing it
		_currentAnimation = animation;
		_frameIndex = 0;
	}
}
void AnimatedSprite::setVisible(bool visible) {
	_visible = visible;
}
void AnimatedSprite::stopAnimation() {
	_frameIndex = 0;
	animationDone(_currentAnimation);
}
void AnimatedSprite::update(int elapsedTime) {
	Sprite::update();
	_timeElapsed = _timeElapsed + elapsedTime;
	if (_timeElapsed > _timeToUpdate) {		// we need to change frames (1->2->3 ... last frame -> first one)
		_timeElapsed = _timeElapsed - _timeToUpdate; // when we move to the next frame 
		if (_frameIndex < _animations[_currentAnimation].size() - 1) {		// frame index starts at 0, size starts at 1, so -1
			_frameIndex = _frameIndex + 1;
		}
		else {								// set it back to beginning if its the last frame, and finish it
			if (_currentAnimationOnce == true) {
				setVisible(false);
			}
			_frameIndex = 0;
			animationDone(_currentAnimation);
		}
	}
}
void AnimatedSprite::draw(Graphics& graphics, int x, int y) {		// similar to sprites draw fn
	if (_visible) {
		SDL_Rect destRectangle;
		destRectangle.x = x + _offsets[_currentAnimation].x;		// add the x offset
		destRectangle.y = y + _offsets[_currentAnimation].y;		// add the y offset
		destRectangle.w = _sourceRect.w * globals::SPRITE_SCALE;
		destRectangle.h = _sourceRect.h * globals::SPRITE_SCALE;
		// the correct rectangle we're drawing	
		SDL_Rect sourceRect = _animations[_currentAnimation][_frameIndex];
		graphics.blitSurface(_spriteSheet, &sourceRect, &destRectangle);
	}
}
void AnimatedSprite::animationDone(string currentAnimation) {
}
void AnimatedSprite::setupAnimations() {
	// impl in player class later
	addAnimation(5, 321, 11, "RunRight", 30, 41, Vector2(0, 0));
	addAnimation(5, 6, 10, "IdlePosition", 25, 41, Vector2(0, 0));
}