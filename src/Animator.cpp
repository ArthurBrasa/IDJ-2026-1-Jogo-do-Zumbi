#include <Animator.h>
#include <GameObject.h>
#include <SpriteRenderer.h>

Animator::Animator(GameObject& associated)
    : Component(associated), frameStart(0), frameEnd(0),
      frameTime(0), currentFrame(0), timeElapsed(0) {}

void Animator::update(float dt) {
    (void)dt;
    if (frameTime == 0) {
        return;
    }

    timeElapsed += 1;
    int previousFrame = currentFrame;
    if (timeElapsed > frameTime) {
        currentFrame++;
        timeElapsed -= frameTime;
        if (currentFrame > frameEnd) {
            currentFrame = frameStart;
        }
    }

    if (currentFrame != previousFrame) {
        SpriteRenderer* sr = associated.getComponent<SpriteRenderer>();
        if (sr) {
            sr->setFrame(currentFrame);
        }
    }
}

void Animator::render() {}

void Animator::setAnimation(std::string name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        frameStart = it->second.frameStart;
        frameEnd = it->second.frameEnd;
        frameTime = it->second.frameTime;
        currentFrame = frameStart;
        timeElapsed = 0;

        SpriteRenderer* sr = associated.getComponent<SpriteRenderer>();
        if (sr) {
            sr->setFrame(currentFrame);
        }
    }
}

void Animator::addAnimation(std::string name, Animation anim) {
    auto it = animations.find(name);
    if (it == animations.end()) {
        animations.insert(std::make_pair(name, anim));
    }
}
