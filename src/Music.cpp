#include <Music.h>
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
        Mix_FreeMusic(music);
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
    if (music) {
        Mix_FreeMusic(music);
    }

    music = Mix_LoadMUS(file.c_str());

    if (!music) {
        std::cout << "Failed to load music: " << file << std::endl;
        std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
    }
}

bool Music::isOpen() {
    return music != nullptr;
}
