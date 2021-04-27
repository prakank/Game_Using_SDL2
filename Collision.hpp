#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "ECS/ColliderComponent.hpp"
#include <SDL2/SDL.h>

class Collision{

    public:
        
        // Access Aligned Bounding Box tyoe Collision
        static bool AABB(const SDL_Rect& a, const SDL_Rect& b);

};

#endif