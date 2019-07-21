#ifndef ANIM_SPRITE_H
#define ANIM_SPRITE_H
#include "sprite.h"
#include "globals.h"	// vector2
#include <map>
#include <string>
#include <vector>
using namespace std;
// The animated sprite class -> extends (inherits) from the sprite class
class Graphics;
class AnimatedSprite : public Sprite {
	public:
		AnimatedSprite();
		AnimatedSprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
		// Most of this will pass onto the sprite class, except the new timeToUpdate -> how long till next frame in animation of the sprite

		// plays animation only if it isn't playing already
		void playAnimation(string animation, bool once = false);
		// updates animated sprite -> timer to keep track of how long before next frame
		void update(int elapsedTime);
		void draw(Graphics& graphics, int x, int y);
	protected:
		double _timeToUpdate;
		bool _currentAnimationOnce;
		string _currentAnimation;
		// Adding animation to the map 
		void addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset);
		// Clear out the map (resets the animations in the map for that sprite)
		void resetAnimations();
		// Stops the current animation
		void stopAnimation();
		// visibility change
		void setVisible(bool visible);
		// what happens when an animation ends
		virtual void animationDone(string currentAnimation) = 0;
		virtual void setupAnimations() = 0;	// pvf later after player class impl'd
	private:
		map<string, vector<SDL_Rect>> _animations;	// map to hold all the animations (string -> its animation)
													// vector of rect -> each spritesheet model for each frame
		map<string, Vector2> _offsets;				// what if we go over our pixel width for a single animation?
													// we can give an offset, and add it when drawing the sprites.

		int _frameIndex;			// which frame in animation we're at
		double _timeElapsed;	//	timer
		bool _visible;				// whether the animation is visible(?)
};
#endif

