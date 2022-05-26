#include<SDL.h>
#include "drawing.hpp"
class Butterfly{
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    int a = 0;
    int check = 0;
public:
    // add the fly function here as well.
    void draw();
    void fly();
    Butterfly(int, int); 
};