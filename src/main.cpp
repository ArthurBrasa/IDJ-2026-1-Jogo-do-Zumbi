#include <iostream>
#include <SDL2/SDL.h>
#include <Game.h>

using namespace std;


int main (int argc, char* argv[]) {
    // cout << "Start Game Engine" << endl;

    // // abrinfo janela 
    // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    //     cout << "Failed to initialize SDL \n";

    //     cout << "SDL_Error" << SDL_GetError() << endl;
    //     return -1;
    // }


    // SDL_Window *window = SDL_CreateWindow(
    //     "Game Engine",           // Título da janela
    //     SDL_WINDOWPOS_CENTERED,  // Posição X (centralizado)
    //     SDL_WINDOWPOS_CENTERED,  // Posição Y (centralizado)
    //     800,                     // Largura em pixels
    //     600,                     // Altura em pixels
    //     0                        // Flags extras (ex: Fullscreen) NAO PERMITIR O VALOR 1 ANTES DE TER UM BOTAO DE FECHAR GAME
    // );

    // if (!window) {
    //     cout << "Failed to create window \n";

    //     return -1;
    // }

    // // SDL_Surface *window_surface = SDL_GetWindowSurface(window); ATENCAO GERALMENTE MAIS LENTO NO MAC
    // SDL_Renderer *window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // if (!window_renderer) {
    //     cout << "Failed to create renderer \n";

    //     cout << "SDL_Error" << SDL_GetError() << endl;

    //     return -1;
    // }

    // bool running = true;
    // SDL_Event event;

    // while (running) {

    //     while (SDL_PollEvent(&event))      // Verifica se aconteceu algo (clique, tecla, etc)
    //     {
    //         if (event.type == SDL_QUIT) {  // Se o usuário clicou no "X" da janela
    //             running = false;           // Sai do loop
    //         }
    //     }

    //     // Limpa a tela com uma cor (opcional, mas ajuda a ver se funcionou)
    //     SDL_SetRenderDrawColor(window_renderer, 50, 100, 255, 255);  // Define a cor (Azul)
    //     SDL_RenderClear(window_renderer);                            // Limpa a tela com essa cor
    //     SDL_RenderPresent(window_renderer);                          // Mostra o resultado (o "Flip")
        
    // }


    // return 0;


    ///

    Game& game = Game::getInstance();
    game.run();
}