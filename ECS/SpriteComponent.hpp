#ifndef SPRITE_COMPONENT
#define SPRITE_COMPONENT

#include "Components.hpp"
#include <SDL2/SDL.h>

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

        void setTex(const char* path){
            texture = TextureManager::LoadTexture(path);
        }

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = srcRect.h = 32;

            dstRect.w = dstRect.h = 64;

            // cout << transform->x() << " " << transform->y() << endl;
        }

        void update() override
        {
            dstRect.x = (int)transform->position.x;
            dstRect.y = (int)transform->position.y;

            // cout << dstRect.x << "  " << dstRect.y << endl;
        }

        void draw() override
        {
            TextureManager::Draw(texture, srcRect, dstRect);
        }

};

#endif