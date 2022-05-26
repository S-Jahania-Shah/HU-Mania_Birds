#include "pigeon.hpp"
// pigeon implementation will go here.
struct src{
    int x_cor;
    int y_cor;
    int width;
    int height;
};
void Pigeon::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

void Pigeon::fly(){
    src case_1 = {7, 88,155,103};
    src case_2 = {0, 235,153,84};
    src case_3 = {2, 361,159,124};
    if (srcRect.x == case_1.x_cor &&  srcRect.y == case_1.y_cor  && srcRect.h == case_1.height && srcRect.w == case_1.width){
        srcRect.x = case_2.x_cor;
        srcRect.y = case_2.y_cor;
        srcRect.h = case_2.height;
        srcRect.w = case_2.width;
    }
    
    else if (srcRect.x == case_2.x_cor &&  srcRect.y == case_2.y_cor && srcRect.h == case_2.height && srcRect.w == case_2.width){
        srcRect.x = case_3.x_cor;
        srcRect.y = case_3.y_cor;
        srcRect.h = case_3.height;
        srcRect.w = case_3.width;
    }

    else if (srcRect.x == case_3.x_cor &&  srcRect.y == case_3.y_cor && srcRect.h == case_3.height && srcRect.w == case_3.width){
        srcRect.x = case_1.x_cor;
        srcRect.y = case_1.y_cor;
        srcRect.h = case_1.height;
        srcRect.w = case_1.width;
    }
    
    // Here we are giving conditions for rotating objects around the screen.
    int check = 0;
    if(moverRect.x <= 999 - moverRect.w )
    {
        check = 0;
    }
    if(moverRect.x > 999 - moverRect.w)
    {
        check = 1;
    }


    // here applying above conditions.
    if(check==1)
    {
        moverRect.x = 0;
        moverRect.x += 5;
    }
    else if (check==0)
    {
        moverRect.x += 5;
    }    
}

Pigeon::Pigeon(int x , int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7, 88,155,103};
    
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}