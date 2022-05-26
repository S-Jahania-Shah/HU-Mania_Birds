#include<SDL.h>
#include "drawing.hpp"

class Bee{
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    int count = 0;
    bool Hover = false; //hover is false initially
    bool bee_within_src = true; // 
public:
    // add the fly function here as well.
    void draw();
    void fly();
    Bee(int, int); 
    // may add other overloaded constructors here...
    bool out_of_scr(){
        return bee_within_src;
    } 
};