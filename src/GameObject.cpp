#include <GameObject.h>
#include <Component.h>

GameObject::GameObject() : box(0, 0, 0, 0), isDeadFlag(false) {}

GameObject::~GameObject() {
    for (int i = (int)components.size() - 1; i >= 0; --i) {
        delete *(components.begin() + i);
    }
    components.clear();
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
        components.erase(it);
    }
}
