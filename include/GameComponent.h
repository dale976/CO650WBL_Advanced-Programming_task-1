#pragma once

#include <iostream>
#include <iomanip> // for std::put_time

using namespace std;

class GameComponent {
private:
    int id;
    static int instances;
public:
    GameComponent(){
        cout << "game component constructor" << endl;
        instances += 1;
        id = instances;
    };
    ~GameComponent(){};
    virtual void Update(const tm* time){
        cout << "GC UPDATE" << endl;
        cout << "ID : " << id << " Updated @ " << put_time(time, "%H:%M:%S") << endl;
    };
    int GetId() {
        return id;
    };
};

// Initialize static member outside the class definition
int GameComponent::instances = 0;