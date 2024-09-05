#pragma once

class GameComponent {
private:
    int id;
    int instances;
public:
    GameComponent(){};
    ~GameComponent(){};
    void Update(const tm*){};
};