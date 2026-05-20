#ifndef CAMERA_H
#define CAMERA_H

#include <Vec2.h>

class GameObject;

class Camera {
    public:
        static Camera& GetInstance();

        void follow(GameObject* newFocus);
        void unfollow();
        void update(float dt);

        Vec2 pos;
        Vec2 speed;

    private:
        Camera();
        GameObject* focus;
};

#endif
