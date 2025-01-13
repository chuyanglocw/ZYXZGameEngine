#include <ZYXZ/RenderManager.hpp>
#include <ZYXZ/ZYXZ.hpp>

using namespace ZYXZ;

RenderManager::RenderManager(){}

RenderManager::~RenderManager(){}

void RenderManager::clear(){
    SDL_RenderClear(Game::renderer);
}

void RenderManager::present(){
    SDL_RenderPresent(Game::renderer);
}

void RenderManager::setBlendMode(SDL_BlendMode blendMode){
    SDL_SetRenderDrawBlendMode(Game::renderer, blendMode);
}

void RenderManager::draw(Texture texture, Rect src, Rect dest, double angle, Point* center, SDL_RendererFlip flip){
    SDL_RenderCopyEx(Game::renderer, texture, src, dest, angle, center, flip);
}

void RenderManager::draw(Texture texture, int x, int y, int width, int height, double angle, Point* center, SDL_RendererFlip flip){
    SDL_Rect dest = {x, y, width, height};
    SDL_RenderCopyEx(Game::renderer, texture, nullptr, &dest, angle, center, flip);
}

void RenderManager::draw(Texture texture, int x, int y, int width, int height, double angle, int centerx, int centery, SDL_RendererFlip flip){
    SDL_Rect dest = {x, y, width, height};
    SDL_Point center = {centerx, centery};
    SDL_RenderCopyEx(Game::renderer, texture, nullptr, &dest, angle, &center, flip);
}

void RenderManager::draw(Texture texture, Rect src, Rect dest){
    SDL_RenderCopy(Game::renderer, texture, src, dest);
}

void RenderManager::draw(Texture texture, Rect dest){
    SDL_RenderCopy(Game::renderer, texture, nullptr, dest);
}

void RenderManager::draw(Texture texture, int x, int y, int width, int height){
    SDL_Rect dest = {x, y, width, height};
    SDL_RenderCopy(Game::renderer, texture, nullptr, &dest);
}

void RenderManager::draw(Texture texture, int x, int y){
    SDL_Rect dest = {x, y, 0, 0};
    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    SDL_RenderCopy(Game::renderer, texture, nullptr, &dest);
}