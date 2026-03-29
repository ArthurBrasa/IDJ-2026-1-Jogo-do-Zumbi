#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>

class Sprite {
    public:
        Sprite();
        Sprite(std::string file);
        ~Sprite();

        void open(std::string file);
        void setClip(int x, int y, int w, int h);
        void render(int x, int y);
        int getWidth();
        int getHeight();
        bool isOpen();
    private:
        SDL_Texture* texture;
        SDL_Rect clipRect;
        int width;
        int height;
};


#endif