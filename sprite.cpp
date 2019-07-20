#include "sprite.h"
#include "graphics.h"
#include <iostream>
#include "globals.h"
using namespace std;
Sprite::Sprite() {}		// default const
Sprite::Sprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	_x(posX), _y(posY)
{
	_sourceRect.x = sourceX;		// all this is just positioning of our sprite
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;
	
	_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (_spriteSheet == NULL) {					// for filepath issues 
		cout << "Error image not loaded";
	}
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics& graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, _sourceRect.w * globals::SPRITE_SCALE, _sourceRect.h * globals::SPRITE_SCALE};	
	graphics.blitSurface(_spriteSheet, &_sourceRect, &destinationRectangle);	// draw!!
}

void Sprite::update() {}