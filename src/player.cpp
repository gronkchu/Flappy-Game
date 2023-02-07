#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>

#include "headers/Entities/PlayerEntity.hpp"
#include "Game.hpp"


PlayerEntity::PlayerEntity(Game p_game, const char* p_path)
    : IEntity(Vector2f(defaultX, defaultY), SDL_Rect{0, 0, PlayerEntity::defaultW, PlayerEntity::defaultH} , p_game.loadTexture(p_path))
{}

PlayerEntity::PlayerEntity(Game p_game, const char* p_path, int p_w, int p_h)
    : IEntity(Vector2f(defaultX, defaultY), SDL_Rect{0, 0, p_w, p_h} , p_game.loadTexture(p_path))
{}

const char* PlayerEntity::getPlayerPath(PlayerType p_name) {
    
    switch(p_name) {
        case PHOTO_ID:
            return "res/gfx/photo_id.png";
    }
    return "";
}

bool PlayerEntity::jump(float p_deltaTime) {
    this->getPos().y -= velocity * p_deltaTime + 1/2 * gravity * std::pow(p_deltaTime, 2);
    velocity += gravity * p_deltaTime;

    if (velocity <= -15.0f || this->getPos().y >= defaultY) {
        velocity = 15.0f;
        this->getPos().y = defaultY;
        return false;
    }
    return true;
}