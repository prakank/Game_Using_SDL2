#ifndef POSITION_COMPONENT
#define POSITION_COMPONENT

#include "Components.hpp"

class PositionComponent : public Component{

    private:
        int xpos, ypos;
        bool initialized = false;
    public:

        PositionComponent()
        {
            xpos = 0;
            ypos = 0;
        }

        PositionComponent(int x, int y)
        {
            xpos = x;
            ypos = y;
            initialized = true;
            // cout << xpos << " " << ypos << endl;
        }

        int x() {return xpos;}
        int y() {return ypos;}
        
        void init() override
        {
            if(!initialized)
            {
                xpos = 0;
                ypos = 0;
            }
            
        }

        void update() override
        {
            xpos++;
            ypos++;   
            // cout << xpos << " " << ypos << endl;
        }

        void setPos(int x, int y){
            xpos = x;
            ypos = y;
        }


};

#endif