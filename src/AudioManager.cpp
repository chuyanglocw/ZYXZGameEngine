#include <ZYXZ/AudioManager.hpp>

using namespace ZYXZ;

AudioManager::AudioManager(){}

AudioManager::~AudioManager(){
    stop();
    for (auto& it : music.getMap()){
        Mix_FreeMusic(it.second);
        std::cout << "Free music: " << it.first << std::endl;
    }

    for (auto& it : sound.getMap()){
        Mix_FreeChunk(it.second);
        std::cout << "Free sound: " << it.first << std::endl;
    }
}

bool AudioManager::initialize(){
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

void AudioManager::stop(){
    Mix_CloseAudio();
}

bool AudioManager::loadMusic(String path){
    if (music.has(path)){
        return true;
    }
    Mix_Music* music_ = Mix_LoadMUS(path.c_str());
    if (music_ == NULL){
        std::cout << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    music.add(path, music_);
    return true;
}

bool AudioManager::playMusic(String path, int loop){
    if (!music.has(path)){
        if (!loadMusic(path)){
            return false;
        }
    }
    if (Mix_PlayMusic(music.get(path), loop) < 0){
        std::cout << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

bool AudioManager::loadSound(String path){
    if (sound.has(path)){
        return true;
    }
    Mix_Chunk* sound_ = Mix_LoadWAV(path.c_str());
    if (sound_ == NULL){
        std::cout << "Failed to load sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    sound.add(path, sound_);
    return true;
}

bool AudioManager::playSound(String path, int channel){
    if (!sound.has(path)){
        if (!loadSound(path)){
            return false;
        }
    }
    if (Mix_PlayChannel(channel, sound.get(path), 0) < 0){
        std::cout << "Failed to play sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}


