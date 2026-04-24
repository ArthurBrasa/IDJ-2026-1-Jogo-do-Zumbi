#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <string>
#include <Component.h>
#include <Sprite.h>

class SpriteRenderer : public Component {
    public:
        SpriteRenderer(GameObject& associated);
        SpriteRenderer(GameObject& associated, std::string file,
                       int frameCountW = 1, int frameCountH = 1);

        void open(std::string file);
        void setFrameCount(int frameCountW, int frameCountH);
        void setFrame(int frame);

        void update(float dt) override;
        void render() override;

    private:
        Sprite sprite;
};

#endif
