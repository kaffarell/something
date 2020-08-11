#include <iostream>
#include "sprite.hpp"

Sprite::Sprite(SDL_Renderer *renderer, int r, int g, int b, int x, int y, int w, int h){
	this->r = r;
	this->g = g;
	this->b = b;
    rect.x = x;
    rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

void Sprite::move(SDL_Renderer *renderer, int x, int y) {
    rect.x = x;
    rect.y = y;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

