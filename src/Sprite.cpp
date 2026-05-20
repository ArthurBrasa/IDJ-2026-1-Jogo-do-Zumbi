#include <Sprite.h>
#include <Game.h>
#include <Resources.h>
#include <Camera.h>

Sprite::Sprite() {
    texture = nullptr;
    width = 0;
    height = 0;
    clipRect = {0, 0, 0, 0};
    frameCountW = 1;
    frameCountH = 1;
    cameraFollower = false;
}

Sprite::Sprite(std::string file, int frameCountW, int frameCountH) : Sprite() {
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
    open(file);
}

Sprite::~Sprite() {}

void Sprite::open(std::string file) {
    texture = Resources::GetImage(file);

    if (!texture) {
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    setClip(0, 0, width / frameCountW, height / frameCountH);
}

void Sprite::setClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y) {
    render(x, y, clipRect.w, clipRect.h);
}

void Sprite::render(int x, int y, int w, int h) {
    if (!cameraFollower) {
        Camera& cam = Camera::GetInstance();
        x -= (int)cam.pos.x;
        y -= (int)cam.pos.y;
    }

    SDL_Rect dst = {x, y, w, h};
    SDL_RenderCopy(Game::getInstance().getRenderer(), texture, &clipRect, &dst);
}

void Sprite::setCameraFollower(bool value) {
    cameraFollower = value;
}

int Sprite::getWidth() {
    return width / frameCountW;
}

int Sprite::getHeight() {
    return height / frameCountH;
}

bool Sprite::isOpen() {
    return texture != nullptr;
}

void Sprite::setFrame(int frame) {
    int frameW = width / frameCountW;
    int frameH = height / frameCountH;
    int row = frame / frameCountW;
    int col = frame % frameCountW;
    int x = col * frameW;
    int y = row * frameH;

    if (x + frameW > width || y + frameH > height) {
        return;
    }

    setClip(x, y, frameW, frameH);
}

void Sprite::setFrameCount(int frameCountW, int frameCountH) {
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
    if (texture) {
        setClip(0, 0, width / frameCountW, height / frameCountH);
    }
}
