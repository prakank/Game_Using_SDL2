// #pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>


#ifndef game_h  // Alternative for #pragma once
#define game_h

using namespace std;

class Game{

    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running(){return isRunning;}
                
        static SDL_Renderer* renderer;
        static SDL_Event event;

    private:
        bool isRunning;
        // SDL_Renderer* renderer = NULL;
        SDL_Window* window = NULL;
        // SDL_Texture* playerTex = NULL;
    
};

#endif