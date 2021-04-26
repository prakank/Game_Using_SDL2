#include "game.hpp"
#include "TextureManager.hpp"

#include "Map.cpp"
#include "ECS/Components.hpp"

// GameObject* player = NULL;
// GameObject* enemy = NULL;

Map* backgroundMap = NULL;

SDL_Renderer* Game::renderer = NULL;

Manager manager;
auto& player(manager.addEntity());

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    
    int flag = SDL_WINDOW_SHOWN;
    if(fullscreen)flag = SDL_WINDOW_FULLSCREEN;

    if( SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        isRunning = false;
        return;
    }
    else{
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if( window == NULL){
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            isRunning = false;
            return;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer == NULL){
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            isRunning = false;  
            return;
        }
        else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        backgroundMap = new Map();

        player.addComponent<PositionComponent>(0,100);
        player.addComponent<SpriteComponent>("assets/player.png");

        
    }
    isRunning = true;
    return;
}

void Game::handleEvents(){
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update(){
    
    manager.refresh();
    manager.update();

    if(player.getComponent<PositionComponent>().x() > 100){
        player.getComponent<SpriteComponent>().setTex("assets/enemy.png");
    }
}

void Game::render(){
    SDL_RenderClear(renderer);    
    backgroundMap->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Ended\n";
}

