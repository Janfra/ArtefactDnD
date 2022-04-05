#include "Player.h" 
#include "Map.h"
/// Libraries included to try and make a sleep timer. ///
#include <chrono>
#include <thread>
///

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
    void infoDisplay();

#pragma endregion

 #pragma region Testing

    void MapTesting();
    void MapGenerationTest();
    void testWallsCheck();
    void displayRewritingTest();

#pragma endregion

 #pragma region Has-A Classes/Pointers
    // Has-a Player/Map
    Map* mainMap;
    Player* player;

#pragma endregion

private:
    // Private "Global Variables", bad for the stack, long life-span
};

