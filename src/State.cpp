#include <State.h>
#include <SDL2/SDL.h>
#include <Game.h>
#include <SpriteRenderer.h>
#include <Zombie.h>
#include <TileMap.h>
#include <TileSet.h>

State::State() : music(), quitRequestedFlag(false) {
    loadAssets();
    music.play();

    GameObject* bgObject = new GameObject();
    SpriteRenderer* bgSprite = new SpriteRenderer(*bgObject, "recursos/img/Background.png");
    bgObject->addComponent(bgSprite);
    bgObject->box.x = 0;
    bgObject->box.y = 0;
    addObject(bgObject);

    GameObject* mapObject = new GameObject();
    TileSet* tileSet = new TileSet(64, 64, "recursos/img/Tileset.png");
    mapObject->addComponent(new TileMap(*mapObject, "recursos/map/map.txt", tileSet));
    mapObject->box.x = 0;
    mapObject->box.y = 0;
    addObject(mapObject);

    GameObject* zombieObject = new GameObject();
    zombieObject->addComponent(new Zombie(*zombieObject));
    zombieObject->box.x = 600;
    zombieObject->box.y = 450;
    addObject(zombieObject);

    GameObject* zombieObject2 = new GameObject();
    zombieObject2->addComponent(new Zombie(*zombieObject2));
    zombieObject2->box.x = 300;
    zombieObject2->box.y = 200;
    addObject(zombieObject2);

    GameObject* zombieObject3 = new GameObject();
    zombieObject3->addComponent(new Zombie(*zombieObject3));
    zombieObject3->box.x = 900;
    zombieObject3->box.y = 600;
    addObject(zombieObject3);
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
