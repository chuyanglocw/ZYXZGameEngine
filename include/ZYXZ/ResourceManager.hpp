#ifndef __RESOURCE_MANAGER_HPP__
#define __RESOURCE_MANAGER_HPP__

// update data: 2024-01-13

#include "ZYXZ_SDL.hpp"
#include "Resource.hpp"

namespace ZYXZ
{

class ResourceManager{
    public:
    ResourceManager();
    ~ResourceManager();

    Texture loadTexture(String filePath);
    void unloadTexture(String filePath);

    private:
    Resource<String,Texture> textureMap;
};

} // namespace ZYXZ


#endif // ! __RESOURCE_MANAGER_HPP__