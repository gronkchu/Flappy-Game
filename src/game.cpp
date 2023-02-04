#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Game.hpp"
#include "IEntity.hpp"

Game::Game(const char* p_title, int p_x, int p_y, int p_w, int p_h, Uint32 p_flags) {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(p_title, p_x, p_y, p_w, p_h, p_flags);
    if (window == NULL) {
        std::cout << "Failed to create window. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) { 
        std::cout << "Failed to create renderer. Error: " << SDL_GetError() << std::endl;
    }

    gameState = GameState::PLAY;
};

GameState Game::getGameState() {
    return gameState;
}

void Game::setGameState(GameState p_gameState) {
    gameState = p_gameState;
}


SDL_Texture* Game::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Game::render(IEntity& p_entity) {

    SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dest; 
	dest.x = p_entity.getPos().x;
	dest.y = p_entity.getPos().y;
	dest.w = p_entity.getCurrentFrame().w * 4;
	dest.h = p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer, p_entity.getTex(), NULL, &dest);
}

// void Game::renderEntities() {
    
//     for (IEntity entity : entities) {
//         this->render(entity);
//     }
// }

// void Game::addEntity(IEntity p_entity) {
//     IEntity &e = p_entity;
//     entities.push_back(e);
// }

// void Game::addEntities(std::vector<IEntity> p_entities) {

//     for (IEntity entity : p_entities) {
//         IEntity &e = entity;
//         entities.push_back(e);
//     }
// }

void Game::clear() {
    SDL_RenderClear(renderer);
}

void Game::cleanUp() {
    SDL_DestroyWindow(window);
}

void Game::display() {
    SDL_RenderPresent(renderer);
}
