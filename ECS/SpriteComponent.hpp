#ifndef SPRITE_COMPONENT
#define SPRITE_COMPONENT

#include "Components.hpp"
#include <SDL2/SDL.h>
#include "../TextureManager.hpp"

class SpriteComponent : public Component
{
    private:
        TransformComponent *transform;
        SDL_Texture* texture = NULL;
        SDL_Rect srcRect, dstRect;

    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path)
        {
            // texture = TextureManager::LoadTexture(path);
            setTex(path);
        }

        ~SpriteComponent()
        {
            SDL_DestroyTexture(texture);
        }

        void setTex(const char* path){
            texture = TextureManager::LoadTexture(path);
        }

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = transform->width;
            srcRect.h = transform->height;
        }

        void update() override
        {
            dstRect.x = static_cast<int>(transform->position.x);
            dstRect.y = static_cast<int>(transform->position.y);
            dstRect.w = transform->width * transform->scale;
            dstRect.h = transform->height * transform->scale;
        }

        void draw() override
        {
            TextureManager::Draw(texture, srcRect, dstRect);
        }

};

#endif