#include <iostream>
#include<SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include<vector>
#include<list>
using namespace std;

class HUMania{

    //Right now we're creating one pigeon, 

    // In the solution you have to create vectors of pigeons, butterfly, and bee.    
    vector<Pigeon*> pigeons;
    vector<Butterfly*> butterfly;
    vector<Bee*> bee;

    public:
    void drawObjects(); 
    void createObject(int, int);
    // Here we have defined destructors for deleting the pigoens & butterlfy vectors.
    ~HUMania(){
        while(!pigeons.empty()) {
            delete pigeons.back();
            pigeons.pop_back();
        }

        while(!butterfly.empty()) {
            delete butterfly.back();
            butterfly.pop_back();
        }
    };
};