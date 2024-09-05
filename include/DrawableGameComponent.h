#pragma once

#include "GameComponent.h"

class DrawableGameComponent: public GameComponent {
private:
    void ChangeDirection(){};
    void Draw(){};
    int x;
    int y;
public:
    DrawableGameComponent(int x, int y){};
    ~DrawableGameComponent(){};
    void Update(const tm* eventTime){};
    Direction direction;

    const int SCREEN_HEIGHT;
    const int SCREEN_WIDTH;

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

};