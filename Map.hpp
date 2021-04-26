#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include "game.hpp"

class Map{

    public:
        Map();
        ~Map();

        void LoadMap(int arr[20][25]);
        void DrawMap();


    private:
        SDL_Rect srcRect, dstRect;
        
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        int arr[20][25];
        int map[20][25];

};

#endif