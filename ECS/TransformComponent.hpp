#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component{

    public:

        Vector2D position;
        Vector2D velocity;
        int speed = 5;

        int height = 32;
        int width = 32;
        int scale = 1;

        bool initialized = false;

        TransformComponent()
        {
            position.x = 0.0f;
            position.y = 0.0f;
        }

        TransformComponent(int s)
        {
            position.x = 0.0f;
            position.y = 0.0f;
            scale = s;
        }

        TransformComponent(float x, float y)
        {
            position.x = y;
            position.y = x;
            initialized = true;
        }
        
        TransformComponent(float x, float y, int h, int w, int s)
        {
            position.x = y;
            position.y = x;
            width = w;
            height = h;
            scale = s;
            initialized = true;
        }

        void init() override
        {
            velocity.x = 0.0f;
            velocity.y = 0.0f;
        }

        void update() override
        {   
            position.x += velocity.x * speed;
            position.y += velocity.y * speed;
        }

        // int x() {return xpos;}
        // int y() {return ypos;}
        
        // void init() override
        // {
        //     if(!initialized)
        //     {
        //         xpos = 0;
        //         ypos = 0;
        //     }
            
        // }

   

        // void setPos(int x, int y){
        //     xpos = x;
        //     ypos = y;
        // }


};

#endif