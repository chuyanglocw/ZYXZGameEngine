#ifndef __ZYXZ_SDL_HPP__
#define __ZYXZ_SDL_HPP__

/**
 * @brief ZYXZ game engine
 *
 * @author ChuYangLOCW
 *
 * @version 0.1
 *
 * @date 2024-01-12
 *
 * @copyright Copyright (c) 2024
 *
 * @file ZYXZ_SDL.hpp
 *
 * @addtogroup ZYXZ
 *
 * @{
 *
 * @par 说明
 *
 * @par 历史
 *
 * @par 备注
 *
 * @par 测试
 *
 * @par 示例
 *
 * @code
 *
 * @endcode
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

//simplize SDL name
namespace ZYXZ
{
    using Rect = SDL_Rect;
    using Point = SDL_Point;
    using Color = SDL_Color;
    using Event = SDL_Event;
    using Renderer = SDL_Renderer*;
    using Window = SDL_Window*;
    using Texture = SDL_Texture*;
    using Surface = SDL_Surface*;

    using String = std::string;

} // namespace ZYXZ


#endif // ! __ZYXZ_SDL_HPP__