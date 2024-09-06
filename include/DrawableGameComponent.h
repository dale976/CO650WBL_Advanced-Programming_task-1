#pragma once

#include <iostream>
#include "GameComponent.h"

using namespace std;

class DrawableGameComponent: public GameComponent {
private:
    int x;
    int y;
    void ChangeDirection();
    void Draw();
    void UpdateCoordinates();
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    Direction direction; // enum value for the direction
    string directionStr; // string representation of the direction
    const int SCREEN_HEIGHT = 80; // x in the range 0 .. 80 
    const int SCREEN_WIDTH = 20;  // y in the range 0 .. 20 
    DrawableGameComponent(int x, int y);
    ~DrawableGameComponent();
    void Update(const tm* time) override;
};