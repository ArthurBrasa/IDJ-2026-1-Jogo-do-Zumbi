#include <State.h>
#include <SDL2/SDL.h>


State::State(SDL_Renderer* renderer) {
    quitRequestedFlag = false;
    this->renderer = renderer;
};

bool State::quitRequested() {
    return quitRequestedFlag;
};

void State::loadAssets() {

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
    SDL_SetRenderDrawColor(renderer, 50, 100, 255, 255);  // Define a cor (Azul)
    SDL_RenderClear(renderer);                            // Limpa a tela com essa cor
};