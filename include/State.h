#ifndef STATE_H
#define STATE_H
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <Music.h>
#include <GameObject.h>

class State {
    public:
        State();
        ~State();
        bool quitRequested();
        void loadAssets();
        void update(float dt);
        void render();
        void addObject(GameObject* go);
    private:
        Music   music;
        bool    quitRequestedFlag;
        std::vector<std::unique_ptr<GameObject>> objectArray;
};

#endif
