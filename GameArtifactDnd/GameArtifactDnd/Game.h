#include "Player.h"
#include "Map.h"
#include <iostream>
#include <Windows.h>
// Libraries included to try and make a sleep timer.
#include <chrono>
#include <thread>
//////
#include <iomanip>

using namespace std; 

#pragma once
// Game class to put all the game inside and have the general game functions.
class Game
{
public:
    Game();
    ~Game();
    // Test for the start screen, update: Now to test
    void gameStart();

    void infoDisplay();

    // Has-a Player/Map
    Map * mainMap;
    Player * player;
private:

};

