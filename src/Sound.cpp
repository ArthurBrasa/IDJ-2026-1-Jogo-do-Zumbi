#include <Sound.h>
#include <Resources.h>
#include <iostream>

Sound::Sound() : chunk(nullptr), channel(-1) {}

Sound::Sound(std::string file) : Sound() {
    open(file);
}

Sound::~Sound() {
    if (chunk) {
        stop();
        chunk = nullptr;
    }
}

void Sound::play(int times) {
    if (chunk) {
        channel = Mix_PlayChannel(-1, chunk, times - 1);
    }
}

void Sound::stop() {
    if (chunk) {
        Mix_HaltChannel(channel);
    }
}

void Sound::open(std::string file) {
    chunk = Resources::GetSound(file);
    if (!chunk) {
        std::cout << "Failed to open sound: " << file << std::endl;
    }
}

bool Sound::isOpen() {
    return chunk != nullptr;
}
