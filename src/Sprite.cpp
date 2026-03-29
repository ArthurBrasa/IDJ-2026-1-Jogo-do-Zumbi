#include <Sprite.h>
#include <Game.h>

Sprite::Sprite() {
    texture = nullptr;
    width = 0;
    height = 0;
    clipRect = {0, 0, 0, 0};
}

Sprite::Sprite(std::string file) : Sprite() {
    open(file);
}

Sprite::~Sprite() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::open(std::string file) {
    if (texture) {
        SDL_DestroyTexture(texture);
    }

    SDL_Renderer* renderer = Game::getInstance().getRenderer();
    texture = IMG_LoadTexture(renderer, file.c_str());

    if (!texture) {
        std::cout << "Failed to load texture: " << file << std::endl;
        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    setClip(0, 0, width, height);
}

void Sprite::setClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;

    SDL_RenderCopy(Game::getInstance().getRenderer(), texture, &clipRect, &dst);
}

int Sprite::getWidth() {
    return width;
}

int Sprite::getHeight() {
    return height;
}

bool Sprite::isOpen() {
    return texture != nullptr;
}