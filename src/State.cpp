#include <State.h>
#include <SDL2/SDL.h>
#include <Game.h>


State::State() : bg(), music(), quitRequestedFlag(false) {
    loadAssets();
    music.play();
};

bool State::quitRequested() {
    return quitRequestedFlag;
};

void State::loadAssets() {
    bg.open("recursos/img/Background.png");
    music.open("recursos/audio/BGM.wav");
};

void State::update(float dt) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitRequestedFlag = true;
        }
    }
};

void State::render() {
    bg.render(0, 0);
};