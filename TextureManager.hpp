// #pragma once

#include "game.hpp"

#ifndef TextureManager_H
#define TextureManager_H

class TextureManager{
    public:
        static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};

#endif