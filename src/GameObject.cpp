#include <GameObject.h>
#include <Component.h>

GameObject::GameObject() : box(0, 0, 0, 0), isDeadFlag(false) {}

GameObject::~GameObject() {
    for (Component* cpt : components) {
        delete cpt;
    }
}

void GameObject::update(float dt) {
    for (Component* cpt : components) {
        cpt->update(dt);
    }
}

void GameObject::render() {
    for (Component* cpt : components) {
        cpt->render();
    }
}

bool GameObject::isDead() const {
    return isDeadFlag;
}

void GameObject::requestDelete() {
    isDeadFlag = true;
}

void GameObject::addComponent(Component* cpt) {
    components.push_back(cpt);
}

void GameObject::removeComponent(Component* cpt) {
    auto it = std::find(components.begin(), components.end(), cpt);
    if (it != components.end()) {
        delete *it; // Free the memory of the component
        components.erase(it); // Remove the pointer from the vector
    }
}

template<typename T>
T* GameObject::getComponent() const {
    for (Component* cpt : components) {
        T* casted = dynamic_cast<T*>(cpt);
        if (casted) {
            return casted;
        }
    }
    return nullptr;
}
