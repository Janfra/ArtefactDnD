#include "Player.h"
#include "Map.h"
#include <iostream>
#include <Windows.h>
/// Libraries included to try and make a sleep timer. ///
#include <chrono>
#include <thread>
///
#include <iomanip>

using namespace std; 

// Game class to put all the game inside and have the general game functions.
class Game
{
public:
 #pragma region Constructor & Destructor

    Game();
    ~Game();

#pragma endregion

 #pragma region Game Functions/General

    // Test for the start screen, update: Now to test/Run the game
    void gameStart();
    bool questionYesOrNo(string question);
    void infoDisplay();

#pragma endregion

#pragma region Testing

    void MapTesting();

    void MapGenerationTest();

    void Color(char typeColor);

#pragma endregion


 #pragma region Has-A Classes/Pointers
    // Has-a Player/Map
    Map* mainMap;
    Player* player;

#pragma endregion

private:
    // Private "Global Variables", bad for the stack, long life-span

};

