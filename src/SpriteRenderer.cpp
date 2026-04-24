#include <SpriteRenderer.h>
#include <GameObject.h>

SpriteRenderer::SpriteRenderer(GameObject& associated)
    : Component(associated), sprite() {}

SpriteRenderer::SpriteRenderer(GameObject& associated, std::string file,
                               int frameCountW, int frameCountH)
    : Component(associated), sprite(file, frameCountW, frameCountH) {
    this->associated.box.w = sprite.getWidth();
    this->associated.box.h = sprite.getHeight();
    setFrame(0);
}

void SpriteRenderer::open(std::string file) {
    sprite.open(file);
    associated.box.w = sprite.getWidth();
    associated.box.h = sprite.getHeight();
}

void SpriteRenderer::setFrameCount(int frameCountW, int frameCountH) {
    sprite.setFrameCount(frameCountW, frameCountH);
}

void SpriteRenderer::setFrame(int frame) {
    sprite.setFrame(frame);
}

void SpriteRenderer::update(float dt) {
    (void)dt;
}

void SpriteRenderer::render() {
    sprite.render((int)associated.box.x, (int)associated.box.y,
                  (int)associated.box.w, (int)associated.box.h);
}
