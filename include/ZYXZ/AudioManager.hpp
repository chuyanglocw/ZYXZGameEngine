#ifndef __AUDIO_MANAGER_HPP__
#define __AUDIO_MANAGER_HPP__

#include "ZYXZ_SDL.hpp"
#include "Resource.hpp"


namespace ZYXZ{

class AudioManager{
    public:
    AudioManager();
    ~AudioManager();

    bool initialize();
    void stop();

    bool loadMusic(String path);
    bool playMusic(String path, int loop = -1);

    bool loadSound(String path);
    bool playSound(String path, int channel = -1);

    private:
    Resource<String, Mix_Music*> music;
    Resource<String, Mix_Chunk*> sound;
};

}

#endif // ! __AUDIO_MANAGER_HPP__