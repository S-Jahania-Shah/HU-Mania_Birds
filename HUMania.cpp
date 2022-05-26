#include <iostream>
#include "HUMania.hpp"

void HUMania::drawObjects()
{
    // call draw functions of all the objects here
    for (int i = 0; i < pigeons.size(); i++){
        pigeons[i]->draw();
    }
    for (int j = 0; j < butterfly.size(); j++){
        butterfly[j]->draw();
    }
    for (int j = 0; j < bee.size(); j++){
        bee[j]->draw();
        
        // here we are making a varaible to check whether it is deleteing bee once crosed width or not.
        static int bee_count = 1;

        // This will check the bee is on src or not.
        bool check_if_on_screen = bee[j]->out_of_scr();

        if(check_if_on_screen == false)
        {
            delete bee[j];
            bee.erase(bee.begin() + j); 
            cout << "Bee "<< bee_count << " is deleted!"<<endl;  
            bee_count ++;       
        } 
    } 
}    

void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    
    // this generates only one object by one click randomly.
    int randn = rand() % 3; 
    if(randn == 0)
    {
        pigeons.push_back(new Pigeon(x,y));
    }
    else if(randn == 1)
    {
        butterfly.push_back(new Butterfly(x,y));
    }
    else if(randn == 2)
    {
        bee.push_back(new Bee(x,y));       
    }    
}