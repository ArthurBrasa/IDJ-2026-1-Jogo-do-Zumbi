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
        float           getDeltaTime() const;
        int             getWidth()     const;
        int             getHeight()    const;
        static Game&    getInstance();

    private:
        Game(std::string title, int width, int height);

        void calculateDeltaTime();

        static Game*    instance;
        SDL_Window*     window;
        SDL_Renderer*   renderer;
        State*          state;
        int             screenWidth;
        int             screenHeight;
        int             frameStart;
        float           dt;
};


#endif