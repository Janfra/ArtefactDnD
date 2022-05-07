// Include the room class, map has rooms
#include "Room.h"

class Map {
public:
    // All functions explained in the cpp file.
 #pragma region Constructor & Destructor

    Map();
    ~Map();

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS //
    // Room Drawing
    void setGrid(int x, int y, short direction);
    void setPosX(short x);
    void setPosY(short y);

    // GETTERS //

    // Grid display
    string getGrid(short x, short y);

    // Room total display
    short getTotalRooms();

    // Player Movement Direction
    int getPathX(int arrayPosition);
    int getPathY(int arrayPosition);

    // Player Position/Movement
    short getPlayerX();
    short getPlayerY();

    //string getRoomType(int n);

#pragma endregion

 #pragma region Map Function

    // Rooms Drawing or Update
    void roundMap();
    void drawRooms(int direction);
    void roomCleared(int x, int y);
    void playerMovement();

    // Walls checking 
    short checkWall(short x, short y);

    // Clamping
    void clamping(short& x, short& y);
    void clamping(int& x, int& y);

#pragma endregion

 #pragma region Testing

#pragma endregion

 #pragma region Has-A Classes/Pointers

    // Pointer to the Room class to save space working by reference instead of by value (creating an extra copy).
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

    //bool checkWall(short x, short y);

    //bool checkWallsAround(short x, short y, int direction);

        //string* roomTypes;
    //     void playerClamping(short& x, short& y);
#pragma endregion

private:
    // Variables for room and player position as well as array locations.
    short posX, posY, playerX, playerY, playerLocationNumber, arrayLocation;
    // Variables for the players directions to follow on the grid
    int pathX[20], pathY[20];
    // Stores the maps grid that gets displayed to the player. Everything that will be displayed in the map is assigned here.
    string grid[X_SIZE][Y_SIZE];
    // Stores the amount of rooms in the grid.
    short totalRooms;
};