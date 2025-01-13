#include <ZYXZ/ZYXZ.hpp>
#undef main

//此为测试用代码 使用Game类作为接口
class myGame : public ZYXZ::Game{
public:
    myGame() : ZYXZ::Game(){}
    ~myGame(){}

    ZYXZ::Texture texture;

    void run() override{
        init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
        texture = resourceManager.loadTexture("assets/textures/player.png");
        audioManager.initialize();
        audioManager.loadMusic("assets/musics/test.mp3");
        audioManager.loadSound("assets/sounds/曼波.mp3");
        loop();
    }
    void loop() override{
        audioManager.playMusic("assets/musics/test.mp3",1);
        audioManager.playSound("assets/sounds/曼波.mp3",2);
        while(running){
            handleInput();
            update();
            render();
            clean();
        }
    }
    void quit() override{
        audioManager.stop();
        ZYXZ::Game::quit();
    }
protected:
    void update() override{

    }
    void render() override{
        renderManager.clear();
        renderManager.draw(texture, 0, 0, 800, 600);
        renderManager.present();
    }
    void clean() override{

    }
};

//启动实现Game接口的类实现运行游戏
int main(int argc, char* argv[]){
    myGame game;
    game.run();
    game.quit();
    return 0;
}