#pragma once

#include <iostream>
#include "GameComponent.h"

using namespace std;

class Game {
private:
    int componentCount;
    int maxSize;
    GameComponent** components;
    // typedef for a function pointer that has 0 arguments and return type void
    typedef void (*FP)();
    FP initialise;
    FP terminate;
    const int TICKS_1000MS;
public:
    Game(int maxComponents) :TICKS_1000MS(1000) {
        cout << "Game(), constructor" << endl;
        maxSize = maxComponents;
        components = new GameComponent* [maxComponents];
    };
    ~Game(){};
    void Add(GameComponent* gc){
        if(componentCount < maxSize) {
            components[componentCount] = gc;
            componentCount += 1;
        } else {
            cout << "Unable to add new game component, maximum limit reached" << endl;
        };
    };
    void SetInitialise(FP init){
        cout << "initialise address: " << addressof(init) << endl;
        initialise = init;
    };
    void SetTerminate(FP term){
        cout << "terminate address: " << addressof(initialise) << endl;
        terminate = term;
    };
    void Run(){

        initialise();

        /*
            iterates through the components array invoking the component’s Update member functions. 
            The time of invocation is passed as an argument to the Update member function. 
            The component’s Update member function should be invoked once every second.
            Should only execute 5 times.
        */

        terminate();
    };
};