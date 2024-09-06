#include <iostream>
#include <iomanip>

#include "GameComponent.h"

using namespace std;

GameComponent::GameComponent(){
    instances += 1;
    id = instances;
}

GameComponent::~GameComponent(){}

void GameComponent::Update(const tm* time){
    cout << "ID: " << id << " Updated @ " << put_time(time, "%H:%M:%S") << endl;
}
int GameComponent::GetId() {
    return id;
}

int GameComponent::instances = 0;