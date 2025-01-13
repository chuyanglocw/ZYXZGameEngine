#include <ZYXZ/ResourceManager.hpp>
#include <ZYXZ/ZYXZ.hpp>

using namespace ZYXZ;

ResourceManager::ResourceManager(){}

ResourceManager::~ResourceManager(){
    if (!textureMap.empty()){
        for (auto it = textureMap.getMap().begin(); it != textureMap.getMap().end(); it++){
            SDL_DestroyTexture(it->second);
            std::cout << "DestroyTexture: " << it->first << std::endl;
        }
        textureMap.clear();
    }
}

Texture ResourceManager::loadTexture(String filePath){
    if (textureMap.has(filePath)){
        return textureMap.get(filePath);
    }
    Surface surface = IMG_Load(filePath.c_str());
    if (!surface){
        std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    Texture texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    if (texture){
        std::cout << "Load Texture: " << filePath << std::endl;
        textureMap.add(filePath, texture);
        return texture;
    }
    return nullptr;
}

void ResourceManager::unloadTexture(String filePath){
    if (textureMap.has(filePath)){
        textureMap.remove(filePath);
    }
}