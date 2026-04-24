#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <Component.h>

class Zombie : public Component {
    public:
        Zombie(GameObject& associated);

        void damage(int damage);
        void update(float dt) override;
        void render() override;

    private:
        int hitpoints;
};

#endif
