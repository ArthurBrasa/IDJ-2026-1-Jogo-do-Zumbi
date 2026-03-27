#ifndef GAME_H
#define GAME_H

#include <string>

#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"

class Game {
    public:
        ~Game() = default;

        void run();
        SDL_Renderer* getRenderer();
        State& getState();
        static Game& getInstance();

    private:
        Game(std::string title, int width, int heigth);
};


#endif