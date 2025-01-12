#include <ZYXZ/ZYXZ.hpp>

class myGame : public ZYXZ::Game{
public:
    myGame() : ZYXZ::Game(){}
    ~myGame(){}
    void run() override{
        init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
        loop();
    }
    void loop() override{
        while(running){
            handleInput();
            update();
            render();
            clean();
        }
    }
    void quit() override{
        ZYXZ::Game::quit();
    }
protected:
    void update() override{

    }
    void render() override{

    }
    void clean() override{

    }
};

int main(int argc, char* argv[]){
    myGame game;
    game.run();
    game.quit();
    return 0;
}