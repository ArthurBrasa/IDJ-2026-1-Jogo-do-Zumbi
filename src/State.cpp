#include <State.h>
#include <SDL2/SDL.h>
#include <Game.h>
#include <SpriteRenderer.h>
#include <Zombie.h>

State::State() : music(), quitRequestedFlag(false) {
    loadAssets();
    music.play();

    GameObject* bgObject = new GameObject();
    SpriteRenderer* bgSprite = new SpriteRenderer(*bgObject, "recursos/img/Background.png");
    bgObject->addComponent(bgSprite);
    bgObject->box.x = 0;
    bgObject->box.y = 0;
    addObject(bgObject);

    GameObject* zombieObject = new GameObject();
    zombieObject->addComponent(new Zombie(*zombieObject));
    zombieObject->box.x = 600;
    zombieObject->box.y = 450;
    addObject(zombieObject);
};

bool State::quitRequested() {
    return quitRequestedFlag;
};

void State::loadAssets() {
    music.open("recursos/audio/BGM.wav");
};

void State::update(float dt) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitRequestedFlag = true;
        }
    }

    for (unsigned i = 0; i < objectArray.size(); ++i) {
        objectArray[i]->update(dt);
    }

    for (unsigned i = 0; i < objectArray.size(); ++i) {
        if (objectArray[i]->isDead()) {
            objectArray.erase(objectArray.begin() + i);
            --i;
        }
    }
};

void State::render() {
    for (unsigned i = 0; i < objectArray.size(); ++i) {
        objectArray[i]->render();
    }
};

void State::addObject(GameObject* go) {
    objectArray.emplace_back(go);
}

State::~State() {
    objectArray.clear();
}
