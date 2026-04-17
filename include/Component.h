#ifndef COMPONENT_H
#define COMPONENT_H
#include <GameObject.h>

class Component {
    public:
        // Component (associated : GameObject&)
        Component(GameObject& associated);  
        virtual ~Component() = default;
        // + Update (dt : float) : void virtual pure
        virtual void update(float dt) = 0;
        // + Render () : void virtual pure
        virtual void render() = 0;
    protected:
        GameObject& associated;
};


#endif