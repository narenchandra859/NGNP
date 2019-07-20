#ifndef SPRITE_H
#define SPRITE_H
using namespace std;
#include <SDL.h>
#include <string>
class Graphics;
class Sprite {
	public:
		Sprite();
		Sprite(Graphics &graphics, const string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
		virtual ~Sprite();			
		virtual void update();		// overriden in animated stuff so its virtual
		void draw(Graphics& graphics, int x, int y);
	protected:
		SDL_Rect _sourceRect;
		SDL_Texture* _spriteSheet;
		float _x, _y;
};
#endif