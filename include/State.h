#ifndef STATE_H
#define STATE_H
#include <SDL2/SDL.h>
#include <Music.h>
#include <Sprite.h>
#include <GameObject.h>

class State {
    public:
        State();
        ~State();
        bool quitRequested();
        void loadAssets();
        void update(float dt);
        void render();
        // + AddObject (GameObject* go) : void
        void addObject(GameObject* go);
    private:
        Sprite  bg;
        Music   music;
        bool    quitRequestedFlag;
        // - objectArray : std::vector<std::unique_ptr<GameObject>>
        std::vector<GameObject*> objectArray;

};

#endif