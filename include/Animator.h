#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <string>
#include <unordered_map>
#include <Component.h>
#include <Animation.h>

class Animator : public Component {
    public:
        Animator(GameObject& associated);

        void update(float dt) override;
        void render() override;

        void setAnimation(std::string name);
        void addAnimation(std::string name, Animation anim);

    private:
        std::unordered_map<std::string, Animation> animations;
        int frameStart;
        int frameEnd;
        float frameTime;
        int currentFrame;
        float timeElapsed;
};

#endif
