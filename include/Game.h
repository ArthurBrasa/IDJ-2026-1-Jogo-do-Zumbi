#ifndef GAME_H
#define GAME_H

#include <string>

#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"

class Game {
    public:
        ~Game();

        void            run();
        SDL_Renderer*   getRenderer();
        State&          getState();
        static Game&    getInstance();

    private:
        Game(std::string title, int width, int heigth);

        static Game*    instance;
        SDL_Window*     window;
        SDL_Renderer*   renderer;
        State*          state;
};


#endif