#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Math.hpp"
#include "IEntity.hpp"
#include "Game.hpp"


enum PlayerType {PHOTO_ID};

class PlayerEntity : public IEntity {

public:
    PlayerEntity(Game p_game, const char* p_path);
    PlayerEntity(Game p_game, const char* p_path, int p_w, int p_h);
    static const char* getPlayerPath(PlayerType p_name);
    bool jump(float p_deltaTime);
private:
    static const int defaultW = 16;
	static const int defaultH = 32;
    static const int defaultX = 100;
    static const int defaultY = 384;

    float velocity = 15.0f; 
    float gravity = -0.6f;
};