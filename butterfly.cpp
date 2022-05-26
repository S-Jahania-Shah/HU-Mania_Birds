#include "butterfly.hpp"
#include "drawing.hpp"

// butterfly implementation will go here.
struct src{
    int x_cor;
    int y_cor;
    int width;
    int height;
};
void Butterfly::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

void Butterfly::fly(){
    src case_1 = {256, 24, 174, 134};
    src case_2 = {257, 182,192,214};
    src case_3 = {248, 433,247,178};
    
    // we are changing states of object by using FSM
    if (srcRect.x == case_1.x_cor &&  srcRect.y == case_1.y_cor && srcRect.h == case_1.height && srcRect.w == case_1.width){
        srcRect.x = case_2.x_cor;
        srcRect.y = case_2.y_cor;
        srcRect.h = case_2.height;
        srcRect.w = case_2.width;
    }
    
    else if (srcRect.x == case_2.x_cor &&  srcRect.y == case_2.y_cor  && srcRect.h == case_2.height && srcRect.w == case_2.width){
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


    // here we are making our object rotate around the screen by putting the condition if moverrect.x approaches to the boundary, it will update the position to x = 0;  
    // check has been declared zero in the class, this is working as checker.
    if(moverRect.x <= 999 - moverRect.w )
    {
        check = 0;
    }
    if(moverRect.x > 999 - moverRect.w)
    {
        check = 1;
    }
    
    
    // here we are setting the conditions for the motion of butterfly once it touches the ground it will bouce back.
    // a has been declared as 0 in the class, this is working as checker.
    if (moverRect.y >= 600 - moverRect.h)
        a = 1;
    if (moverRect.y <= 0)
        a = 0;

    
    // here we are moving our butterfly according tothe conditions above mentioned.
    if(check==1)
    {
        moverRect.x = 0; //set to zero
        if (a==0) // if zero, move downward
        {
            moverRect.x += 5;
            moverRect.y += 5;
        }
        else if(a==1)// if 1, move upward
        {
            moverRect.x += 5;    
            moverRect.y += -5;  
        }    
    }
    else if (check==0) // it will move towards right
    {
        if (a==0)
        {
            moverRect.x += 5;
            moverRect.y += 5;
        }
        else if(a==1)
        {
            moverRect.x += 5;    
            moverRect.y += -5;
        }
    }
}

Butterfly::Butterfly(int x , int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {256, 24, 174, 134};
    
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 60, 60};
}