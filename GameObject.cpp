#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y){
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
}

void GameObject::Update(){
    
    xpos++;
    ypos++;
    
    srcRect = {
        .x = 0,
        .y = 0,
        .w = 64,
        .h = 64,        
    };
    
    dstRect = {
        .x = xpos,
        .y = ypos,
        .w = srcRect.w,
        .h = srcRect.h,
    };  
}

void GameObject::Render(){
    SDL_RenderCopy(renderer, objTexture, NULL, &dstRect);
}