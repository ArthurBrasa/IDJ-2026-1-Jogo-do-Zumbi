#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <algorithm>
#include <Rect.h>
#include <Component.h>

class GameObject{
    public:
        GameObject();
        ~GameObject();

        void update(float dt);
        void render();

        bool isDead() const;
        void requestDelete();

        void addComponent(Component* cpt);
        void removeComponent(Component* cpt);

        template<typename T> T* getComponent() const {
            for (Component* cpt : components) {
                T* casted = dynamic_cast<T*>(cpt);
                if (casted) {
                    return casted;
                }
            }
            return nullptr;
        }

        Rect box;
    private:
        std::vector<Component*> components;
        bool isDeadFlag;
};

#endif
