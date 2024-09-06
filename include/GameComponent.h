#pragma once

class GameComponent {
private:
    int id;
    static int instances;
public:
    GameComponent();
    ~GameComponent();
    virtual void Update(const tm* time);
    int GetId();
};