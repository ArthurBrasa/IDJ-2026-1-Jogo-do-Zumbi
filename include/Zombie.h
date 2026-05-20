#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <Component.h>
#include <Sound.h>
#include <Timer.h>

class Zombie : public Component {
    public:
        Zombie(GameObject& associated);

        void damage(int dmg);
        void update(float dt) override;
        void render() override;

    private:
        int   hitpoints;
        bool  hit;
        bool  dead;
        Sound deathSound;
        Sound hitSound;
        Timer hitTimer;
        Timer deathTimer;
};

#endif
