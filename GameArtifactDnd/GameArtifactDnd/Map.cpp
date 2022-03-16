#include "Map.h"

 #pragma region Constructor & Destructor

Map::Map()
{
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
                grid[x][y] = " - ";
            }
        }
    }

}

#pragma endregion

 #pragma region Getters & Setters

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