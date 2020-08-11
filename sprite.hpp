#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"

class Sprite {
    public:
        SDL_Rect rect;
		int r, g, b;

        Sprite(SDL_Renderer *renderer, int r, int g, int b, int x, int y, int w = 48, int h = 64);
        void move(SDL_Renderer *renderer, int x, int y);
};

#endif
