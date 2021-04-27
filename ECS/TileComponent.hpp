#ifndef TILE_COMPONENT_HPP
#define TILE_COMPONENT_HPP

#include "EntityComponentSystem.hpp"
#include "TransformComponent.hpp"
#include "../TextureManager.hpp"
#include <SDL2/SDL.h>


class TileComponent : public Component 
{
    public:
        TransformComponent *transform;
        SpriteComponent *sprite;
        SDL_Rect tileRect;
        SDL_Texture *texture;
        int tileId;
        char* path = "";
        string temp_path = "";
        string color = "assets/GenerateTiles/White";

        TileComponent() = default;

        TileComponent(int x, int y, int w, int h, int id)
        {
            tileRect = {
                .x = x,
                .y = y,
                .w = w,
                .h = h,
            };
            tileId = id;

            temp_path = color + "_" + to_string(id) + ".png";
            // cout << temp_path << endl;
            // strcpy(path, temp_path.c_str());
            // path = temp_path;

            // switch(tileId)
            // {
            //     case 0:
            //         path = "assets/water.png";
            //         break;
            //     case 1:
            //         path = "assets/dirt.png";
            //         break;
            //     case 2:
            //         path = "assets/grass.png";
            //         break;
            //     default:
            //         break;                
            // }

        }

        void init() override
        {   
            entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
            transform = &entity->getComponent<TransformComponent>();

            entity->addComponent<SpriteComponent>(temp_path.c_str());
            sprite = &entity->getComponent<SpriteComponent>();

        }


};

#endif