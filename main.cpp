#include "SDL.h"
#include <iostream>
#include "rigid.hpp"
#include "helper.hpp"
#include <math.h>

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1200
// Compile: g++ main.cpp `pkg-config --cflags --libs sdl2`

using namespace std;


int main(){
	SDL_Init( SDL_INIT_EVERYTHING );
	
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
   	window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);

	if(renderer == NULL){
		cout << "There was an error initializing the renderer: " << SDL_GetError() << endl;
	}	
	if(window == NULL){
		cout << "There was an error initializing the window: " << SDL_GetError() << endl;
	}
	
	// Set size of renderer
	SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// Clear window
	SDL_RenderClear(renderer);
	// Update image
	SDL_RenderPresent(renderer);	
	
    
	float spriteX = 200;
    float spriteY = WINDOW_WIDTH/2;
	float floorX = 0;
	float floorY = 800;
    Rigid sprite = Rigid( renderer, 0, 255, 0, spriteX, spriteY, 80, 80);
	Rigid floor_scene = Rigid(renderer, 0, 0, 255, floorX, floorY, 1100, 20);

	Uint32 starting_tick;

	// main event loop
	SDL_Event event;
	bool running = true;
    bool jumping = false;
	int jumpingOffset = 0;

	while(running){
		starting_tick = SDL_GetTicks();

		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = false;
			}


            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_a:
						if(sprite.isCollidingLeft() == false){
                        	spriteX -= 10;
						}
                        break;
                    case SDLK_d:
						if(sprite.isCollidingRight() == false){
                        	spriteX += 10;
						}
                        break;
                    case SDLK_SPACE:
                        jumping = true;
						jumpingOffset = spriteY-100;
                        break;
                }
            }
		}

        if(jumping == true){
			if(spriteY < jumpingOffset) {
				jumping = false;
			}
			spriteY -= 8;	
        }else{
			if(sprite.isCollidingBottom() == false){
				spriteY += 3;
			}
		}

		// Update all elements
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        floor_scene.move(renderer, floorX, floorY);
		sprite.move(renderer, spriteX, spriteY);
		

		reduceFramerate(starting_tick);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
