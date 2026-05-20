#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <SDL2/SDL_image.h>

class Sprite {
    public:
        Sprite();
        Sprite(std::string file, int frameCountW = 1, int frameCountH = 1);
        ~Sprite();

        void open(std::string file);
        void setClip(int x, int y, int w, int h);
        void render(int x, int y);
        void render(int x, int y, int w, int h);
        int getWidth();
        int getHeight();
        bool isOpen();

        void setFrame(int frame);
        void setFrameCount(int frameCountW, int frameCountH);
        void setCameraFollower(bool value);
    private:
        SDL_Texture* texture;
        SDL_Rect clipRect;
        int width;
        int height;
        int frameCountW;
        int frameCountH;
        bool cameraFollower;
};


#endif
