// Minimun y_size of the map has to be 16 until I add a way to automatically force it. Otherwise the stats won't show., it has to be divisible by 2
#define x_Size 38
#define y_Size 28
#include <iostream>
#include <string>
#include "Room.h"
using namespace std;

class Map {
public:
 #pragma region Constructor & Destructor

    Map();
    ~Map();

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS //

    void setGrid(int x, int y, short direction);

    void setPosX(short x);
    
    void setPosY(short y);

    // GETTERS //

    // Created a getGrid function to be able to display the map grid on the displayInfo for the Game Class
    string getGrid(short x, short y);

    short getTotalRooms();

    int getPathX(int arrayPosition);

    int getPathY(int arrayPosition);

    short getPlayerX();

    short getPlayerY();

#pragma endregion

 #pragma region Map Function

    void roundMap();

    void fillMap(int direction);

    void playerMovement();

    void roomCleared(int x, int y);

    void clamping(short& x, short& y);

    void clamping(int& x, int& y);

    void playerClamping(short& x, short& y);

    //bool checkWall(short x, short y);

    //bool checkWallsAround(short x, short y, int direction);
#pragma endregion

 #pragma region Testing



#pragma endregion

 #pragma region Has-A Classes/Pointers

    Room * rooms;

#pragma endregion

 #pragma region Outdated

    // Emptyspace is no longer needed and even in the case of going back, now I have been using setw and setfill instead of emtpySpace as it was needed to align objects properly in
    // displayInfo function
    // int getEmptySpace();
    // void setEmptySpace(int size);

    // generateMap was the old version to cout the map that is not longer gonna be used but was used as base to create the displayInfo function
    // void generateMap();

    // Used a variable in private to set size and display it, then I decided that it wouldnt let me move around the map as it couldnt be used for a 2D grid and took it out and went for another
    // method
    //void setXSize(int size);
    //int getXSize();
    //int getYSize();

    // Unnecessary variables, outdated
    // int emptySpace;
    // int ySize;
    // int xSize;

    //void setGrid(int x, int y);

#pragma endregion

private:
    short posX, posY, playerX, playerY, playerLocationNumber, arrayLocation;
    int pathX[20], pathY[20];
    string grid[x_Size][y_Size];
    short totalRooms;
};