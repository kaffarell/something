#ifndef RIGID_HPP
#define RIGID_HPP


#include "SDL.h"
#include "../sprite/sprite.hpp"
#include <vector>

class Rigid: public Sprite{
	private:
		static std::vector<Rigid> rigidObjects;

	public:
		Rigid(SDL_Renderer *renderer, int r, int g, int b, int x, int y, int w, int h);
		bool isCollidingTop();
		bool isCollidingBottom();
		bool isCollidingRight();
		bool isCollidingLeft();
};

#endif
