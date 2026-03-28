#include <Game.h>
#include <iostream>

Game* Game::instance = nullptr;
// destrutor

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// construtor
Game::Game(std::string title, int width, int height) {
    std::cout << title << " - " << width << "x" << height << std::endl;
};

// singleton
Game& Game::getInstance() {

    if (instance == nullptr) {
        instance = new Game("Arthur Brasa de Carvalho - 202006582", 800, 600);
    }

    return *instance;
};


// 
void Game::run() {
    std::cout << "Running Game..." << std::endl;

};

//
SDL_Renderer* Game::getRenderer() {
    return renderer;
};

//
State& Game::getState() {
    return *state;
};