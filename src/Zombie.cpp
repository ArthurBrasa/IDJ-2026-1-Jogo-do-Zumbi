#include <Zombie.h>
#include <GameObject.h>
#include <SpriteRenderer.h>
#include <Animator.h>
#include <Animation.h>

Zombie::Zombie(GameObject& associated)
    : Component(associated), hitpoints(100), deathSound("recursos/audio/Dead.wav") {
    SpriteRenderer* sr = new SpriteRenderer(associated, "recursos/img/Enemy.png", 3, 2);
    sr->setFrame(1);
    associated.addComponent(sr);

    Animator* anim = new Animator(associated);
    anim->addAnimation("walking", Animation(0, 3, 10));
    anim->addAnimation("dead", Animation(5, 5, 0));
    associated.addComponent(anim);
    anim->setAnimation("walking");
}

void Zombie::damage(int damage) {
    bool wasAlive = hitpoints > 0;
    hitpoints -= damage;
    if (hitpoints <= 0) {
        Animator* anim = associated.getComponent<Animator>();
        if (anim) {
            anim->setAnimation("dead");
        } else {
            SpriteRenderer* sr = associated.getComponent<SpriteRenderer>();
            if (sr) {
                sr->setFrame(5);
            }
        }
        if (wasAlive) {
            deathSound.play(1);
        }
    }
}

void Zombie::update(float dt) {
    (void)dt;
    damage(1);
}

void Zombie::render() {}
