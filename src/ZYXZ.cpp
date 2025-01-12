#include <ZYXZ/ZYXZ.hpp>

using namespace ZYXZ;

Game::Game() : running(true), window(nullptr), renderer(nullptr){}
Game::~Game(){}

void Game::init(String title, int x, int y, int width, int height, bool fullscreen){
    int flags = 0;
    initSuccess = true;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SDL init success" << std::endl;
        window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
        if(window){
            std::cout << "window create success" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "renderer create success" << std::endl;
        }
    }else{
        initSuccess = false;
        running = false;
    }
}

void Game::run(){
    init("ZYXZ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    loop();
}

void Game::loop(){
    while(running){
        handleInput();
        update();
        render();
        clean();
    }
}

void Game::quit(){
    if (window) SDL_DestroyWindow(window);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (initSuccess) SDL_Quit();
    std::cout << "game clean and quit" << std::endl;
}

void Game::handleInput(){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}

void Game::update(){
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean(){
}