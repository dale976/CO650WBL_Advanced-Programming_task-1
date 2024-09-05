#include <iostream>

#include "Game.h"

using namespace std;

void init() {
    cout << "Initialising Game" << endl;
}

void term() {
    cout << "Terminating Game" << endl;
}

int main() {
    Game g = Game(8);
    g.SetInitialise(init);
    g.SetTerminate(term);
    g.Run();

    return 0;
}