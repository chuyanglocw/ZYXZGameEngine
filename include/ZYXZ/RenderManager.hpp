#ifndef __RENDER_MANAGER_HPP__
#define __RENDER_MANAGER_HPP__

#include "ZYXZ_SDL.hpp"


namespace ZYXZ
{

class RenderManager{
public:
    RenderManager();
    ~RenderManager();

    void clear();
    void present();
    void setBlendMode(SDL_BlendMode blendMode);
    void draw(Texture texture, Rect src, Rect dest, double angle, Point* center, SDL_RendererFlip flip);
    void draw(Texture texture, int x, int y, int w, int h, double angle, Point* center, SDL_RendererFlip flip);
    void draw(Texture texture, int x, int y, int w, int h, double angle, int centerx, int centery, SDL_RendererFlip flip);
    void draw(Texture texture, Rect src, Rect dest);
    void draw(Texture texture, Rect dest);
    void draw(Texture texture, int x, int y, int w, int h);
    void draw(Texture texture, int x, int y);

};

} // namespace ZYXZ



#endif // ! __RENDER_MANAGER_HPP__