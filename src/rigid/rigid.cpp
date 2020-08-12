#include "rigid.hpp"
#include <iostream>
#include <vector>

std::vector<Rigid> Rigid::rigidObjects;

Rigid::Rigid(SDL_Renderer *renderer, int r, int g, int b, int x, int y, int w, int h): Sprite(renderer, r, g, b, x, y, w, h) {
	Rigid::rigidObjects.push_back(*this);
	for(int i = 0; i < Rigid::rigidObjects.size(); i++){
		std::cout << rigidObjects[i].rect.w << std::endl;
		std::cout << rigidObjects[i].rect.h << std::endl;
		std::cout << rigidObjects[i].rect.x << std::endl;
		std::cout << rigidObjects[i].rect.y << std::endl;
		
	}
	std::cout << "------" << std::endl;
}

bool Rigid::isCollidingTop(){
	for(int i = 0; i < rigidObjects.size(); i++){
		// Check if other object is above our sprite
		if(rigidObjects[i].rect.y < rect.y){
			if(rect.y <= rigidObjects[i].rect.y + rigidObjects[i].rect.h){
				return true;
			}
		}
	}
	return false;
}


bool Rigid::isCollidingBottom(){
	// TODO(#2): Colliding Bottom changes when jumping often
	for(int i = 0; i < rigidObjects.size(); i++){
		// Check if other object is above our sprite
		if(rigidObjects[i].rect.y > rect.y){
			if(rect.y + rect.h > rigidObjects[i].rect.y){
				return true;
			}
		}
	}
	return false;
}


bool Rigid::isCollidingRight(){
	for(int i = 0; i < rigidObjects.size(); i++){
		// Check if other object is right of our sprite
		if(rigidObjects[i].rect.x > rect.x){
			if(rect.x + rect.w >= rigidObjects[i].rect.x && (isCollidingBottom() == true && isCollidingTop() == true)){
				return true;
			}
		}
	}
	return false;
}


bool Rigid::isCollidingLeft(){
	for(int i = 0; i < rigidObjects.size(); i++){
		// Check if other object is left of our sprite
		if(rigidObjects[i].rect.x < rect.x){
			if(rect.x <= rigidObjects[i].rect.x + rigidObjects[i].rect.w && (isCollidingBottom() == true && isCollidingTop() == true)){
				return true;
			}
		}
	}
	return false;
}
