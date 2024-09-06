#pragma once

#include <iostream>
#include <iomanip> // for std::put_time

using namespace std;

class GameComponent {
private:
    int id;
    int instances;
public:
    GameComponent(){
        cout << "game component constructor" << endl;
        instances += 1;
        id = instances;
    };
    ~GameComponent(){};
    void Update(const tm* time){
        // ID : 1 Updated @ 18:27:36
        cout << "ID : " << id << " Updated @ " << put_time(time, "%H:%M:%S") << endl;
    };
    int GetId() {
        return id;
    };
};

