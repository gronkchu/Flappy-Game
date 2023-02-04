#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class IEntity {

public:
	IEntity(Vector2f p_pos, SDL_Rect p_currentFrame, SDL_Texture* p_tex) 
		:pos(p_pos), currentFrame(p_currentFrame), tex(p_tex) 
	{}

	Vector2f& getPos() {
		return pos;
	}
	SDL_Rect getCurrentFrame() {
		return currentFrame;
	}
	SDL_Texture* getTex() {
		return tex;
	}
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};