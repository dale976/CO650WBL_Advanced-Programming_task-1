#pragma once

#include "GameComponent.h"

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
    Game(int maxComponents);
    ~Game();
    tm* GetTimeNow();
    void Add(GameComponent* gc);
    void SetInitialise(FP init);
    void SetTerminate(FP term);
    void Run();
};