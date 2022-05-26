#include "bee.hpp"

// bool varaible to delete the object. 
bool bee_within_src = true;


// struction is defined to set the cases for transition in three picture of object by using FSM.
struct src{
    int x_cor;
    int y_cor;
    int width;
    int height;
};

void Bee::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

void Bee::fly(){
    src case_1 = {63, 619, 151, 166}; //1st positon
    src case_2 = {234, 630, 163, 162}; //2nd position
    src case_3 = {409, 650, 171, 147}; //3rd position
    
    //By using FSM, we are changing the states of each objec again and again.
    if (srcRect.x == case_1.x_cor &&  srcRect.y == case_1.y_cor && srcRect.h == case_1.height && srcRect.w == case_1.width){
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
    
    
    // we are applying 1% probablity to hover the bee.
    int a = rand() % 100;
    // the probablity of a to be 0 is 1%, once it is zero and hover is false it will stop for a while.
    if (a == 0 && Hover == false){
        Hover = true;
    }
    
    // Here we are giving two condition either hover is true or false.
    if (Hover == false){
        moverRect.x += 5;
    }
    else if(Hover == true){
        if (count == 10){
            count = 0;
            Hover = false;
        }
        else{
            count ++;
        } 
    }

    // if moverrect.x is greater then 1000, the delete vector becomes false       
    if(moverRect.x >1000){
        bee_within_src = false;
    }

}

Bee::Bee(int x , int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {63, 619, 151, 166};
    
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 50};
}