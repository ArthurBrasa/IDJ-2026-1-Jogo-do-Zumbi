#include <State.h>
#include <SDL2/SDL.h>
#include <Game.h>
#include <SpriteRenderer.h>
#include <Zombie.h>
#include <TileMap.h>
#include <TileSet.h>
#include <InputManager.h>
#include <Camera.h>

State::State() : music(), quitRequestedFlag(false) {
    loadAssets();
    music.play();

    GameObject* bgObject = new GameObject();
    SpriteRenderer* bgSprite = new SpriteRenderer(*bgObject, "recursos/img/Background.png");
    bgSprite->setCameraFollower(true);
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
};

bool State::quitRequested() {
    return quitRequestedFlag;
};

void State::loadAssets() {
    music.open("recursos/audio/BGM.wav");
};

void State::update(float dt) {
    InputManager& im = InputManager::GetInstance();

    if (im.quitRequested() || im.keyPress(ESCAPE_KEY)) {
        quitRequestedFlag = true;
        return;
    }

    if (im.keyPress(SDLK_SPACE)) {
        Camera& cam = Camera::GetInstance();
        GameObject* zombie = new GameObject();
        zombie->addComponent(new Zombie(*zombie));
        zombie->box.x = im.getMouseX() + cam.pos.x - zombie->box.w / 2.0f;
        zombie->box.y = im.getMouseY() + cam.pos.y - zombie->box.h / 2.0f;
        addObject(zombie);
    }

    Camera::GetInstance().update(dt);

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
