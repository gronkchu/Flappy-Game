#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "headers/Game.hpp"
#include "headers/IEntity.hpp"

int main(int argc, char* argv[]) {

    Game game("Flappy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 1024, SDL_WINDOW_SHOWN);

    while (game.getGameState() != GameState::EXIT) {
        SDL_Event event;
        SDL_PollEvent(&event);

        game.clear();

        switch (event.type) {
            case SDL_QUIT:
                game.setGameState(GameState::EXIT);
                break;
            case SDL_KEYDOWN:
                break;
        }

		game.display();

    }

    return 0;
}