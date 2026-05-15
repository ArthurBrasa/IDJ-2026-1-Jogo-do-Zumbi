#include <Music.h>
#include <Resources.h>
#include <iostream>

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) : Music() {
    open(file);
}

Music::~Music() {
    if (music) {
        stop(0);
    }
}

void Music::play(int times) {
    if (music) {
        Mix_PlayMusic(music, times);
    }
}

void Music::stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::open(std::string file) {
    music = Resources::GetMusic(file);
}

bool Music::isOpen() {
    return music != nullptr;
}
