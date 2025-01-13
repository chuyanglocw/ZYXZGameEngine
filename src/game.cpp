#include <ZYXZ/ZYXZ.hpp>

class myGame : public ZYXZ::Game{
public:
    myGame() : ZYXZ::Game(){}
    ~myGame(){}

    ZYXZ::Texture texture;

    void run() override{
        init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
        texture = Game::resourceManager.loadTexture("assets/textures/player.png");
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
        SDL_RenderClear(Game::renderer);
        SDL_RenderCopy(Game::renderer, texture, NULL, NULL);
        SDL_RenderPresent(Game::renderer);
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