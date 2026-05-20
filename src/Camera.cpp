#include <Camera.h>
#include <GameObject.h>
#include <InputManager.h>
#include <Game.h>

static const float CAMERA_SPEED = 200.0f;

Camera::Camera() : pos(0, 0), speed(0, 0), focus(nullptr) {}

Camera& Camera::GetInstance() {
    static Camera instance;
    return instance;
}

void Camera::follow(GameObject* newFocus) {
    focus = newFocus;
}

void Camera::unfollow() {
    focus = nullptr;
}

void Camera::update(float dt) {
    if (focus) {
        float screenW = (float)Game::getInstance().getWidth();
        float screenH = (float)Game::getInstance().getHeight();
        pos.x = focus->box.center().x - screenW / 2.0f;
        pos.y = focus->box.center().y - screenH / 2.0f;
        return;
    }

    InputManager& im = InputManager::GetInstance();
    speed = Vec2(0, 0);

    if (im.isKeyDown(LEFT_ARROW_KEY))  speed.x = -CAMERA_SPEED;
    if (im.isKeyDown(RIGHT_ARROW_KEY)) speed.x =  CAMERA_SPEED;
    if (im.isKeyDown(UP_ARROW_KEY))    speed.y = -CAMERA_SPEED;
    if (im.isKeyDown(DOWN_ARROW_KEY))  speed.y =  CAMERA_SPEED;

    pos = pos + speed * dt;
}
