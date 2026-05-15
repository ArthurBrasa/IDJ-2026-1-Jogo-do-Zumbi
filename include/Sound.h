#ifndef SOUND_H
#define SOUND_H

#include <string>
#include <SDL2/SDL_mixer.h>

class Sound {
    public:
        Sound();
        Sound(std::string file);
        ~Sound();

        void play(int times = 1);
        void stop();
        void open(std::string file);
        bool isOpen();
    private:
        Mix_Chunk*  chunk;
        int         channel;
};

#endif
