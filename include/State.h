#ifndef STATE_H
#define STATE_H
#include <SDL2/SDL.h>
#include <Music.h>
#include <Sprite.h>

class State {
    public:
        State(SDL_Renderer* renderer);
        // ~State();
        bool quitRequested();
        void loadAssets();
        void update(float dt);
        void render();
    private:
        Sprite  bg;
        Music   music;
        bool    quitRequestedFlag;
        SDL_Renderer* renderer;

};

#endif