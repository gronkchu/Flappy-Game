#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "IEntity.hpp"

enum GameState {PLAY, EXIT};

class Game {

public:
    Game(const char* p_title, int p_x, int p_y, int p_w, int p_h, Uint32 p_flags);

    GameState getGameState();
    void setGameState(GameState p_gameState);
    SDL_Texture* loadTexture(const char* p_filePath);
    void render(IEntity& p_entity);
    // void renderEntities();
    // void addEntity(IEntity p_entity);
    // void addEntities(std::vector<IEntity> p_entities);

    void clear();
    void display();
    void cleanUp();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    GameState gameState;

    // std::vector<IEntity> entities;
};