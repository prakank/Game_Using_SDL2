#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Map.cpp"

GameObject* player = NULL;
GameObject* enemy = NULL;
Map* backgroundMap = NULL;

SDL_Renderer* Game::renderer = NULL;

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
        // string file = "assets/" + path;
        player = new GameObject("assets/player.bmp", 0, 0);
        enemy = new GameObject("assets/enemy.bmp", 50, 50);
        backgroundMap = new Map();

        if(player == NULL){
            cout << "PLAYER NOT FOUND: " << SDL_GetError() << endl;
        }
        if(enemy == NULL){
            cout << "ENEMY NOT FOUND: " << SDL_GetError() << endl;
        }
        // playerTex = TextureManager::LoadTexture("assets/tank.bmp", renderer);
        
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
    player->Update();
    enemy->Update();
    // backgroundMap->LoadMap();
}

void Game::render(){
    SDL_RenderClear(renderer);    
    backgroundMap->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Ended\n";
}

