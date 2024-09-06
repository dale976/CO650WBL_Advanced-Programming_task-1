#pragma once

#include <iostream>
#include <iomanip>
#include <random>
#include "GameComponent.h"

using namespace std;

class DrawableGameComponent: public GameComponent {
private:
    int x;
    int y;
    // assigns a new random direction to the data member
    // can not be the same as the current direction
    void ChangeDirection(){
        random_device rd;  // Seed generator
        mt19937 gen(rd()); // Mersenne Twister engine
        // create the range, this is the number of options we have in enum Direction (4)
        uniform_int_distribution<> distr(1, 4);
        int randomNum = distr(gen);
        
        Direction tmpDir; // hold a temporary value so we can compare with the current direction
        string tmpStr;    // hold a temporary string value
        switch(randomNum) {
            case 1:
                tmpDir = UP;
                tmpStr = "UP";
                break;
            case 2:
                tmpDir = DOWN;
                tmpStr = "DOWN";
                break;
            case 3:
                tmpDir = LEFT;
                tmpStr = "LEFT";
                break;
            case 4:
                tmpDir = RIGHT;
                tmpStr = "RIGHT";
                break;
        }

        // check to see if the temp direction is not equal to the current direction
        // if it is the same, re-run the function
        if (tmpDir != direction) {
            direction = tmpDir;
            directionStr = tmpStr;
            UpdateCoordinates();
        } else {
            ChangeDirection();
        }
    };
    void Draw(){
        // print out the direction and current coordinate values
        cout << directionStr << " : " << "X:" << x << " : " << "Y:" << y << endl;
    };
    void UpdateCoordinates() {
        // update the coordinate value if valid
        switch(direction) {
            case UP:
                if (y < SCREEN_HEIGHT)
                    y += 1;
                break;
            case DOWN:
                if (y > 0)
                    y -= 1;
                break;
            case LEFT:
                if (x > 0)
                    x -= 1;
                break;
            case RIGHT:
                if (x < SCREEN_WIDTH)
                    x += 1;
                break;
        }
    };
    
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

    DrawableGameComponent(int x, int y) {
        // clamp x position to boundary if it is placed off screen
        if (x < 0) {
            this->x = 0;
        } else if (x > SCREEN_WIDTH) {
            this->x = SCREEN_WIDTH;
        };
        // clamp y position to boundary if it is placed off screen
        if (y < 0) {
            this->y = 0;
        } else if (y > SCREEN_HEIGHT) {
            this->y = SCREEN_HEIGHT;
        };

        // default direction is RIGHT
        direction = RIGHT;
        directionStr = "RIGHT";
        // As the start direction is set to right, update the x value to +1;
        this->x += 1;
    };
    ~DrawableGameComponent(){};
    void Update(const tm* time) override {
        cout << "ID: " << GetId() << " Updated @ " << put_time(time, "%H:%M:%S") << endl;
        Draw();
        ChangeDirection();
        
    };
};