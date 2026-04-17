#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <Rect.h>
#include <Component.h>

class GameObject{
    public:
        GameObject();
        ~GameObject();

        // + Update(dt : float) : void
        void update(float dt);
        void render();

        // + IsDead() : bool
        bool isDead() const;

        // + RequestDelete() : void
        void requestDelete();

        // + AddComponent(cpt : Component*) : void
        void addComponent(Component* cpt);

        // + RemoveComponent(cpt : Component*) : void
        void removeComponent(Component* cpt);

        // + GetComponent<T>() : T*
        template<typename T> T* getComponent() const;

        // + box : Rect
        Rect box;
    private:
        // std::vector<Component*> components;
        std::vector<Component*> components;
        bool isDeadFlag;

};

#endif