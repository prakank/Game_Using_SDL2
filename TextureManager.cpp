#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName){
    
    SDL_Surface* tmpSurface = IMG_Load(fileName);    
    SDL_Texture* tex = NULL;
    tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;

}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip, int RotateDegrees){
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dst, RotateDegrees, NULL, flip);
    
}