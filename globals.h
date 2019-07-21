#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
	const int SCREEN_WIDTH = 1080;
	const int SCREEN_HEIGHT = 720;
	const float SPRITE_SCALE_W = 4.0f;	// sprites im using are ~50x37, no scaling
	const float SPRITE_SCALE_H = 2.0f;
}

enum Direction {
	LEFT, RIGHT, UP, DOWN
};

struct Vector2 {						// struct used for animated sprites
	int x, y;
	Vector2() : x(0), y(0) {}
	Vector2(int x, int y) : x(x), y(y) {}
	Vector2 zero() {
		return Vector2(0, 0);
	}
};

#endif