#pragma once

#include <iostream>
#include <iomanip> // for std::put_time
#include "GameComponent.h"

using namespace std;

class DrawableGameComponent: public GameComponent {
private:
    void ChangeDirection(){};
    void Draw(){};
    int x;
    int y;
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    Direction direction;

    // Assuming we are using a 1080p resolution for this task.
    const int SCREEN_HEIGHT = 1080;
    const int SCREEN_WIDTH = 1920;

    DrawableGameComponent(int x, int y) {
        cout << "DWC constructor" << endl;
        // clamp x position to boundary if it is placed off screen
        if (x < 0) {
            x = 0;
        } else if (x > SCREEN_WIDTH) {
            x = SCREEN_WIDTH;
        };
        // clamp y position to boundary if it is placed off screen
        if (y < 0) {
            y = 0;
        } else if (y > SCREEN_HEIGHT) {
            y = SCREEN_HEIGHT;
        };

        // default direction is RIGHT
        direction = RIGHT;
    };
    ~DrawableGameComponent(){};
    void Update(const tm* time) override {
        cout << "DGC UPDATE" << endl;
        cout << "ID : " << GetId() << " Updated @ " << put_time(time, "%H:%M:%S") << endl;
        Draw();
        ChangeDirection();
    };
};