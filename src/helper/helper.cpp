#include "helper.hpp"
#define MAX_FPS 30

void reduceFramerate(Uint32 starting_tick){
	if((1000 / MAX_FPS) > SDL_GetTicks() - starting_tick){
		SDL_Delay(1000 / MAX_FPS - (SDL_GetTicks() - starting_tick));
	}
}