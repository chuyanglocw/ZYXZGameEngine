#ifndef __ZYXZ_HPP__
#define __ZYXZ_HPP__

/**
 * @brief ZYXZ game engine
 *
 * @author ChuYangLOCW
 *
 * @version 0.1
 *
 * @date 2024-01-13
 *
 * @copyright Copyright (c) 2024
 *
 * @file ZYXZ.hpp
 *
 * @addtogroup ZYXZ
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
 * #include "ZYXZ.hpp"
 * class myGame : public ZYXZ::Game{
 * public:
 *     myGame() : ZYXZ::Game(){}
 *     ~myGame(){}
 *     void run() override{
 *         init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
 *         loop();
 *     }
 *     void loop() override{
 *         while(running){
 *             handleInput();
 *             update();
 *             render();
 *             clean();
 *         }
 *     }
 *     void quit() override{
 *         ZYXZ::Game::quit();
 *     }
 * protected:
 *     void handleInput() override{
 *     }
 *     void update() override{
 *     }
 *      void render() override{
 *     }
 *     void clean() override{
 *     }
 * };
 *
 * int main(int argc, char* argv[]){
 *     myGame game;
 *     game.run();
 *     game.quit();
 *     return 0;
 * }
 * @endcode
 */

#include "ZYXZ_all.hpp"

namespace ZYXZ
{

class Game{
public:
    Game();
    ~Game();
    virtual void run();
    virtual void loop();
    virtual void quit();
protected:
    virtual void init(String title, int x, int y, int width, int height, bool fullscreen);
    virtual void handleInput();
    virtual void update();
    virtual void render();
    virtual void clean();
    bool running;
    bool initSuccess;
public:
    static RenderManager renderManager;
    static ResourceManager resourceManager;
    static AudioManager audioManager;
    static ZYXZ::Window window;
    static ZYXZ::Renderer renderer;
    ZYXZ::Event event;
};

} // namespace ZYXZ

#endif // ! __ZYXZ_HPP__