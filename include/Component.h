#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

class Component {
    public:
        Component(GameObject& associated) : associated(associated) {}
        virtual ~Component() = default;
        virtual void update(float dt) = 0;
        virtual void render() = 0;
    protected:
        GameObject& associated;
};

#endif
