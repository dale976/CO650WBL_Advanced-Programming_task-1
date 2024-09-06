#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip> // for std::put_time

#include "GameComponent.h"

using namespace std;

class Game {
private:
    int componentCount = 0;
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
    tm* GetTimeNow() {
        // Get current time as a time_point object
        auto now = chrono::system_clock::now();
        // Convert to time_t to use with standard C functions
        time_t currentTime = chrono::system_clock::to_time_t(now);
        // Convert time_t to local time (tm structure)
        tm* localTime = localtime(&currentTime);
        return localTime;
    };

    void Run(){

        initialise();
        /*
            iterates through the components array invoking the component’s Update member functions. 
            The time of invocation is passed as an argument to the Update member function. 
            The component’s Update member function should be invoked once every second.
            Should only execute 5 times.
        */
        for (int i = 0; i < componentCount; i++) {
            // every second, for 5 seconds, call the update function
            for(int j = 0; j < 5; j++) {
                // call update
                components[i]->Update(GetTimeNow());
                // sleep for 1 second before next iteration
                this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS));
            }
        }

        terminate();
    };
};