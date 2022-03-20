#include "Map.h"

 #pragma region Constructor & Destructor

Map::Map()
{
    totalRooms = 3;
    for (int y = 0; y < y_Size; y++) {
        for (int x = 0; x < x_Size; x++) {
            // Top map border
            if (y == (x_Size - x_Size)) {
                grid[x][y] = "~~~";
            }
            // Bottom map border
            else if (y == (y_Size - 1)) {
                grid[x][y] = "~~~";
            }
            else {
                grid[x][y] = "   ";
            }
        }
    }
}

Map::~Map()
{  
    /*delete[] rooms;
    rooms = NULL;*/
}

#pragma endregion

 #pragma region Getters & Setters

void Map::setGrid(int x, int y)
{
    int old = x;
    for (int h = 0; h < Height_SIZE; h++) {
        for (int w = 0; w < Width_SIZE; w++) {
            grid[x][y] = rooms[0].getRoom(w, h);
            x++;
        }
        x = old;
        y++;
    }
}

// getGrid function was created to be able to output the grid map on displayFunction. It accepts two parameters required to return the correct array variable.
// I haven't tested it, but it should also block the player from going under or over the limits. After writing that... Actually, probably not.
string Map::getGrid(short x, short y)
{
    if (x < 0) {
        x = 0;
    }
    else if (x > x_Size) {
        x = (x_Size - 1);
    };
    if (y < 0) {
        y = 0;
    }
    else if (y > y_Size) {
        y = (y_Size - 1);
    };
    return grid[x][y];
}

short Map::getTotalRooms()
{
    return totalRooms;
}

#pragma endregion

 #pragma region Map Functions

void Map::fillMap(int direction)
{
    // I will use an integer so that I can use a random number generator to decide in which direction the rooms are generated. Up = 1
    int x = (x_Size / 2 - (Width_SIZE / 2));
    int y = (y_Size - (Height_SIZE + 1));
    
    switch (direction)
    {
    case 1:
        // Fill till the wall up so, total and it goes 'up' by taking away
        for (int i = y; i > (y_Size - y_Size); i -= Height_SIZE + 1) {
            // I added a condition to check if it was going over or under the grid size to avoid errors.
            if (y >= y_Size || y <= (y_Size - y_Size)) {
                i += Height_SIZE + 1;
                break;
            }
            setGrid(x, i);
        }
        break;
    case 2:
        // Fill till the wall left, total and to go left it takes away 
        for (int i = x; i > (x_Size - x_Size); i -= Width_SIZE + 1) {
            if (x >= x_Size || x <= (x_Size - x_Size)) {
                i += Width_SIZE + 1;
                break;
            }
            setGrid(i, y);
        }
        break;
        // Fill till the wall right, total and to go right it adds up
    case 3:
        for (int i = x; i < x_Size; i += Width_SIZE + 1) {
            if (x >= x_Size || x <= (x_Size - x_Size) || i == 15) {
                i -= Width_SIZE + 1;
                break;
            }
            setGrid(i, y);
        }
        break;
    default:
        break;
    }
}

#pragma endregion


 #pragma region Outdated

    // Outdated constructor variable: 
    // emptySpace = 12;

    // Old outdated functions:
    // 
    // int Map::getEmptySpace()
    //{
    //	return emptySpace;
    //}
    //
    //void Map::setEmptySpace(int size)
    //{
    //    if (size > 60) {
    //        emptySpace = 60;
    //    }
    //    else if (size < 1) {
    //        emptySpace = 0;
    //    }
    //    else {
    //        emptySpace = size;
    //    }
    //}
    //
    //
    //void Map::generateMap()
    //{
    //	for (int y = 0; y < y_Size; y++) {
    //        // This for is to create emtpy space and center the map
    //            for (int space = 0; space < emptySpace; space++) {
    //                cout << "   ";
    //            }
    //            // Left map border
    //            cout << "|";
    //            for (int x = 0; x < x_Size; x++) {
    //                // Top map border
    //                if (y == (x_Size - 1)){
    //                    cout << "~~~";
    //                    }
    //                // Bottom map border
    //                else if (y == (y_Size - 1)) {
    //                    cout << "~~~";
    //                } else {
    //                    cout << grid[x][y];
    //                }
    //
    //            }
    //            // Right map border
    //            cout << "|";
    //            cout << endl;
    //    }
    //}

#pragma endregion