#include <Zombie.h>
#include <GameObject.h>
#include <SpriteRenderer.h>
#include <Animator.h>
#include <Animation.h>
#include <InputManager.h>
#include <Camera.h>

Zombie::Zombie(GameObject& associated)
    : Component(associated), hitpoints(100), hit(false), dead(false),
      deathSound("recursos/audio/Dead.wav"),
      hitSound("recursos/audio/Hit0.wav") {

    SpriteRenderer* sr = new SpriteRenderer(associated, "recursos/img/Enemy.png", 3, 2);
    associated.addComponent(sr);

    Animator* anim = new Animator(associated);
    anim->addAnimation("walking", Animation(0, 3, 0.15f));
    anim->addAnimation("dead",    Animation(5, 5, 0));
    anim->addAnimation("hit",     Animation(4, 4, 0));
    associated.addComponent(anim);
    anim->setAnimation("walking");
}

void Zombie::damage(int dmg) {
    if (dead) return;

    hitpoints -= dmg;
    hitSound.play(1);

    if (hitpoints <= 0) {
        dead = true;
        deathSound.play(1);
        deathTimer.restart();

        Animator* anim = associated.getComponent<Animator>();
        if (anim) anim->setAnimation("dead");
    } else {
        hit = true;
        hitTimer.restart();

        Animator* anim = associated.getComponent<Animator>();
        if (anim) anim->setAnimation("hit");
    }
}

void Zombie::update(float dt) {
    hitTimer.update(dt);
    deathTimer.update(dt);

    InputManager& im = InputManager::GetInstance();

    if (!dead && im.mousePress(LEFT_MOUSE_BUTTON)) {
        Camera& cam = Camera::GetInstance();
        Vec2 mouseWorld((float)(im.getMouseX()) + cam.pos.x,
                        (float)(im.getMouseY()) + cam.pos.y);
        if (associated.box.contains(mouseWorld)) {
            damage(34);
        }
    }

    if (hit && !dead && hitTimer.get() >= 0.5f) {
        hit = false;
        Animator* anim = associated.getComponent<Animator>();
        if (anim) anim->setAnimation("walking");
    }

    if (dead && deathTimer.get() >= 5.0f) {
        associated.requestDelete();
    }
}

void Zombie::render() {}
