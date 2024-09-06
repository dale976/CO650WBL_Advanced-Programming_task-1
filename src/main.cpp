#include <iostream>

#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"

using namespace std;

void init() {
    cout << "\nInitialising Game" << endl;
}

void term() {
    cout << "\nTerminating Game" << endl;
}

int main() {
    Game g = Game(8);
    g.SetInitialise(init);
    g.SetTerminate(term);

    GameComponent* gc = new GameComponent();
    DrawableGameComponent* dgc = new DrawableGameComponent(0, 0);

    g.Add(gc);
    g.Add(dgc);


    g.Run();

    return 0;
}