#ifndef POSITION_COMPONENT
#define POSITION_COMPONENT

#include "Components.hpp"

class PositionComponent : public Component{

    private:
        int xpos = 0, ypos = 0;
    
    public:
        int x() {return xpos;}
        int y() {return ypos;}
        
        void init() override
        {
            xpos = 0;
            ypos = 0;
        }

        void update() override
        {
            xpos++;
            ypos++;   
        }

        void setPos(int x, int y){
            xpos = x;
            ypos = y;
        }


};

#endif