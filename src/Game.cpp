#include <Game.h>
#include <Resources.h>
#include <InputManager.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "SDL_include.h"

Game* Game::instance = nullptr;

Game::~Game() {
    delete state;
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// construtor
Game::Game(std::string title, int width, int height)
    : screenWidth(width), screenHeight(height), frameStart(0), dt(0) {
    if (instance != nullptr) {
        std::cout << "Error: Game instance already exists!" << std::endl;
        exit(-1);
    }
    instance = this;

    std::cout << title << " - " << width << "x" << height << std::endl;


    // Inicializando o SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
        std::cout << "Failed to initialize SDL" << std::endl;

        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Audio initialization
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_TIF) < 0) {
        std::cout << "Failed to initialize SDL_Image" << std::endl;

        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;

        exit(-1);
    }

    // Mixer initialization
    if (Mix_Init(MIX_INIT_MP3) < 0) {
        std::cout << "Failed to initialize SDL_Mixer" << std::endl;

        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;

        exit(-1);
    }
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        std::cerr << "Erro Mix_OpenAudio: " << SDL_GetError() << std::endl;
    }
    Mix_AllocateChannels(32);

    // Criando Janela do Jogo
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );

    if (!window) {
        std::cout << "Failed to create window" << std::endl;

        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;

        exit(-1);
    }

    // Criando Renderizador da Janela
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cout << "Failed to create renderer" << std::endl;

        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;

        exit(-1);
    }

    state = new State();
};

// singleton
Game& Game::getInstance() {

    if (instance == nullptr) {
        instance = new Game("Arthur Brasa de Carvalho - 202006582", 1200, 900);
    }

    return *instance;
};


// 
void Game::calculateDeltaTime() {
    int now = (int)SDL_GetTicks();
    dt = (now - frameStart) / 1000.0f;
    frameStart = now;
}

float Game::getDeltaTime() const { return dt; }
int   Game::getWidth()     const { return screenWidth; }
int   Game::getHeight()    const { return screenHeight; }

void Game::run() {
    std::cout << "Running Game..." << std::endl;
    frameStart = (int)SDL_GetTicks();

    while (!state->quitRequested()) {
        calculateDeltaTime();
        InputManager::GetInstance().update();
        state->update(dt);
        state->render();

        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
};

//
SDL_Renderer* Game::getRenderer() {
    return renderer;
};

//
State& Game::getState() {
    return *state;
};