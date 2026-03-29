#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include <SDL2/SDL_mixer.h>

class Music {
    public:
        Music();
        Music(std::string file);
        ~Music();

        void play(int times = -1);
        void stop(int msToStop = 1500);
        void open(std::string file);
        bool isOpen();
    private:
        Mix_Music* music;
};

#endif
