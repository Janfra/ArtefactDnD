#include "Map.h"

 #pragma region Constructor & Destructor

Map::Map()
{
    // Initializing the values for every global variable.
    rooms = new Room();
    totalRooms = 0;
    posX = (x_Size / 2 - (Width_SIZE / 2));
    posY = (y_Size - (Height_SIZE + 1));
    playerX = posX;
    playerY = posY;
    playerLocationNumber = 0;
    arrayLocation = 0;

        // Generates the map display (without including the rooms)
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
            // The inside of the map
            else {
                grid[x][y] = "   ";
            }
        }
    }
    // Create the new dynamic variable with the total amount of rooms. Possibly change this.
    // roomTypes = new string[totalRooms];
}

Map::~Map()
{  
    // Delete the space in the freestore to avoid memory leaks. 
    delete rooms;
        // Set the rooms as NULL so that rooms is not storing anything. 
    rooms = NULL;
    
    //delete [] roomTypes;
    //roomTypes = NULL;
}
#pragma endregion

 #pragma region Getters & Setters

// This function is used to assign the rooms to the map grid and display them. It also stores the path used when generating them for the player to follow. 
void Map::setGrid(int x, int y, short direction)
{
    clamping(x, y);
    int old = x;
    switch (direction)
    {
    case 1:
        pathX[arrayLocation] = 0;
        pathY[arrayLocation] = -5;
        break;
    case 2:
        pathX[arrayLocation] = -5;
        pathY[arrayLocation] = 0;
        break;
    case 3:
        pathX[arrayLocation] = Width_SIZE + 1;
        pathY[arrayLocation] = 0;
        break;
    case 4:
        pathX[arrayLocation] = 0;
        pathY[arrayLocation] = Height_SIZE + 1;
        break;
    default:
        break;
    }
    arrayLocation++;

    // Nested for loop to go over all the assigned room array grid to assign it to the map grid to display it. Basically copy pasting the room format into the map.
    for (int h = 0; h < Height_SIZE; h++) {
        for (int w = 0; w < Width_SIZE; w++) {
            if (y >= y_Size || y <= (y_Size - y_Size) || x >= x_Size || x <= (x_Size - x_Size)) {
              cout << "you going over: " << y << " " << x;
              system("pause");
              break;
            }
            grid[x][y] = rooms[0].getRoom(w, h);
            x++;
        }
        x = old;
        y++;
    }
}

// Set both the value for 'posX' and 'posY' while clamping them to avoid errors.
void Map::setPosX(short x)
{
    // Clamp the 'x' parameter in between a minimun value of 0 and a maximum value of 'x_Size' (total x value of the map).
    if (x > x_Size) {
        posX = x_Size - 1;
    }
    else if (x <= 0) {
        posX = 1;
    }
    else {
        posX = x;
    }
}

void Map::setPosY(short y)
{
    // Clamp the 'y' parameter in between a minimun value of 0 and a maximum value of 'y_Size' (total y value of the map).
    if (y > y_Size) {
        posY = y_Size - 1;
    }
    else if (y <= 0) {
        posY = 1;
    }
    else {
        posY = y;
    }
}

// getGrid function was created to be able to output the grid map on displayFunction. It accepts two parameters required to return the correct array variable.
string Map::getGrid(short x, short y)
{
    // Check that the 'x' parameter is not under 0.
    if (x < 0) {
        // Make it 0 to avoid errors.
        x = 0;
    }
        // Else check if the 'x' parameter is going over the grid 'x_Size' (total x size of the map).
    else if (x > x_Size) {
            // Make it so
        x = (x_Size - 1);
    }
    // Check that the 'y' parameter is not under 0.
    if (y < 0) {
        // Make it 0 to avoid errors.
        y = 0;
    }
        // Else check if the 'y' parameter is going over the grid 'y_Size' (total y size of the map).
    else if (y > y_Size) {
        y = (y_Size - 1);
    }
            // Return the grid using the parameters.
    return grid[x][y];
}

// Making possible to display the total amount of rooms
short Map::getTotalRooms()
{
    return totalRooms;
}

// Clamping both PathX and PathY when getting their value to avoid errors.
int Map::getPathX(int arrayPosition)
{
    if (arrayPosition >= 19) {
        arrayPosition = 19;
    }
    else if (arrayPosition < 0) {
        arrayPosition = 0;
    }
    return pathX[arrayPosition];
}

int Map::getPathY(int arrayPosition)
{
    if (arrayPosition >= 19) {
        arrayPosition = 19;
    }
    else if (arrayPosition < 0) {
        arrayPosition = 0;
    }
    return pathY[arrayPosition];
}

// Making it possible to get playerX and Player Y value
short Map::getPlayerX()
{
    return playerX;
}

short Map::getPlayerY()
{
    return playerY;
}

//string Map::getRoomType(int n)
//{
//    return string(roomTypes[n]);
//}

#pragma endregion

 #pragma region Map Functions

// Manually generated map. It marks as "cleared" the first room when generated as well.
void Map::roundMap()
{
    // Left
    fillMap(2);
    // Up
    fillMap(1);
    // Right
    fillMap(3);
    // Down
    fillMap(4);
    // Mark as "cleared" the player starting position using the starting values of 'playerX' and 'playerY'.
    roomCleared(playerX, playerY);
}

/* Function to draw the rooms into the map grid using the Room class. It uses an int as a parameter to set the direction the rooms will be generated.
   I will use an int so that I can use a random number generator to decide in which direction the rooms are generated. */
void Map::fillMap(int direction)
{
    // This local variable is here to set the type of room that will be generated/draw from the list of type of rooms in the Room class. It is assigned the '0' value at first that is = to "spawn" room.
    int randomNumber = 0;
    // Switch case using the direction parameter.
    switch (direction)
    {
        // Case 1 = Up. *To move up it takes away (-) from 'posY'.
    case 1:
        // Generate rooms until 'i', that is equal to 'posY', is more than 0. The grid top limit. In case it is still not at the top, add the height value of a room + 1. The +1 is to make room for halls.
        for (int i = posY; i > 0; i -= Height_SIZE + 1) {
            // Set 'posY' as 'i' so that the next time fillMap() is called it does it from the last place this function was called and not from the initial value. 
            setPosY(i);
                /* During the first iteration set the type of room as the "spawn" room(0), it also stores the type of the room in the 'roomType[0]' because the totalRooms haven't gone up. 
                If it is not the first iteration, set is as a randomly generated number.
                Each room has a different probability. *For clarity check setType() in the Room class. */
            rooms->setType(randomNumber);
                    // Assign a new random value to the local variable 'randomNumber' to set the room type during the next iteration of the for loop. 
            randomNumber = (rand() % 15) + 1;
                        // Check if it is the last iteration of the for loop. 
            if (i <= Height_SIZE + 1) {
                            /* Subtract one from the 'arrayLocation' global variable. This is done to avoid the extra iteration generated when saving the room path.
                            Overwrite the last iteration done to avoid having an extra step on the path. *This variable is used in setGrid(). */
                arrayLocation--;
            }
                        /* Set the setGrid() first parameter to 'posX' as it won't change during going up. Set the second parameter to 'i' to change it to the new location during each iteration. 
                        Lastly use the direction parameter from the fillMap() function to set the last parameter in setGrid()*/
            setGrid(posX, i, direction);
                            // Add one to totalRooms, this is done every iteration because each iteration generates one more room.
            totalRooms++;
        }
        break;
        // Case 2 = Left. *To move left it takes away (-) from 'posX'. 
    case 2:
        // The inside of the for loop is the same as in case 1 but exchanging 'posY' with 'posX'.
        for (int i = posX; i > 0; i -= Width_SIZE + 1) {
            setPosX(i);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (i <= Width_SIZE + 1) {
                arrayLocation--;
            }
            setGrid(i, posY, direction);
            totalRooms++;
        }
        break;
        // Case 3 = Right. *To move right it adds (+) to 'posX'. 
    case 3:
        /* The inside of the for loop is the same as in case 1 but exchanging 'posY' with 'posX'
        and checking in the conditions not to exceed the max value, -2 to leave a small margin, of the grid instead of the minimum. */
        for (int i = posX; i < (x_Size - 2); i += Width_SIZE + 1) {
            setPosX(i);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (i >= (x_Size - (Width_SIZE + 2))) {
                arrayLocation--;
            }
            setGrid(i, posY, direction);
            totalRooms++;
        }
        break;
        // Case 4 = Down. *To move down it adds (+) to 'posY'.
    case 4:
        // The inside of the for loop is the same as in case 1 but checking in the conditions not to exceed the max value, -2 to leave a small margin, of the grid instead of the minimum. 
        for (int i = posY; i < (y_Size - 2); i += Height_SIZE + 1) {
            setPosY(i);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (i >= (y_Size - (Height_SIZE + 1))) {
                arrayLocation--;
            }
            setGrid(posX, i, direction);
            totalRooms++;
        }
        break;
    default:
        break;
    }
}

// Function to display the rooms as "cleared" as the player goes through them.
void Map::roomCleared(int x, int y)
{
    // Clamp the parameters to avoid going over the limit. Probably should modify this one as it would add 5 to it, so it should be 5 (Width or Height + 1) further than the usual clamp.
    clamping(x, y);
    // Store the 'x' parameter value to reset it in the nested for loop to simulate the restart of the parameter inside the second for loop. 
    int old = x;

        // Nested for loop to go over all the room grid to change the inside to be in a "cleared" state instead of empty. 'h' = height/y
    for (int h = 0; h < Height_SIZE; h++) {
            // Second iteration of the nested for loop, 'w' = width/x. It is done this way to go over 'x' several times as it must be done every time the y value changes to go to the next row.
        for (int w = 0; w < Width_SIZE; w++) {
            // Second check in case it tries to assign a value outside the grid.
            if (y >= y_Size || y <= (y_Size - y_Size) || x >= x_Size || x <= (x_Size - x_Size)) {
                // Cout that is going over and tell which are the values exceeding the limit.
                cout << "You going over " << x << " " << y << " " << endl;
                    // Pause for me to read it.
                system("PAUSE");
                        // Skip the rest of this for loop.
                break;
            }
                // Check that is the values in the middle and not the bordering values AKA the walls. So the min and max values of 'w' and 'h'.
            if (h > 0 && w > 0 && w < (Width_SIZE - 1) && h < (Height_SIZE - 1)) {
                grid[x][y] = " + ";
            }
                    // Add one to x for each repetition of this for loop. It simulates using the w parameter. This could be changed so that w is = to 'x' and the condition to stop is (Width_SIZE + x)
            x++;
        }
                        // Reset 'x' to its initial value.
        x = old;
                            // Add one to 'y'.
        y++;
    }
}

// Function that displays the player movement on the map
void Map::playerMovement()
{
    if (checkWall(playerX, playerY) == rooms->getType(0)) {
        rooms->encounters->enemyEncounter();
    }
    // First check if the player will be moving more than the amount of rooms generated.
    if (playerLocationNumber + 2 < totalRooms && rooms->encounters->encounterInProcess == false) {
        // Then check if the player position is exceding the map size (trying to imitate the room generation function parameters).
    if (playerY > 0 || playerX > 0 || playerY < (y_Size - 2) || playerX < (x_Size - 2)) {
            // Add to the player starting position the direction the rooms was generated to update to the next room coordinates in the map.
        playerX += pathX[playerLocationNumber];
        playerY += pathY[playerLocationNumber];
    }
                // Go to the next saved movement of the room. *check setGrid() for clarity on this.
    playerLocationNumber++;
                    // Clamp the player movement to not exceed the map limits, added as quick fix at first, left it for now for extra measurement. 
    playerClamping(playerX, playerY);
                        // Update the room as cleared in the display.
    roomCleared(playerX, playerY);
    }
}

// Clamp functions to avoid going over the map limits that would lead to errors
void Map::clamping(short& x, short& y)
{
    if (x < 1) {
        x = 1;
    }
    else if (x > x_Size) {
        x = (x_Size - 1);
    };
    if (y < 1) {
        y = 1;
    }
    else if (y > y_Size) {
        y = (y_Size - 1);
    };
}

// Updated this clamp to change its values to take in consideration that when this clamp is used it is inside a function that will add '5' to it.
void Map::clamping(int& x, int& y)
{
    // 1 and +1 to avoid changing the wall borders that are situated at the '0' coordinates.
    if (x < 1) {
        x = 1;
    }
    else if (x > (x_Size - Width_SIZE)) {
        x = (x_Size - (Width_SIZE + 1));
    };
    if (y < 1) {
        y = 1;
    }
    else if (y > (y_Size - Height_SIZE)) {
        y = (y_Size - (Height_SIZE + 1));
    };
}

void Map::playerClamping(short& x, short& y) {
    if (x < 1) {
        x = 2;
    }
    else if (x >= (x_Size - (Width_SIZE + 1))) {
        x = (x_Size - (Width_SIZE + 2));
    };
    if (y < 1) {
        y = 3;
    }
    else if (y >= (y_Size - (Height_SIZE + 1))) {
        y = (y_Size - (Height_SIZE + 1));
    };
}

string Map::checkWall(short x, short y) {
    short typeNumber = 0;
        for (int n = 0; n < TOTAL_WALLS; n++) {
            if (getGrid(x, y) == rooms->roomWalls[n]) {
                switch (n)
                {
                case 0:
                case 1:
                case 2:
                    return rooms->getType(typeNumber);
                    break;
                case 3:
                case 4:
                case 5:
                    return rooms->getType(typeNumber);
                    break;
                case 6:
                case 7:
                case 8:
                    return rooms->getType(typeNumber);
                    break;
                case 9:
                case 10:
                case 11:
                    return rooms->getType(typeNumber);
                    break;
                case 12:
                case 13:
                case 14:
                    return rooms->getType(typeNumber);
                    break;
                default:
                    break;
                }
            }
            // 3 in this case because there is a total of 3 walls, so if it already check 3 walls of a type, go to the next type.
            if (n % 3 == 2) {
                typeNumber++;
            }
        }
        return "Error";
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

//void Map::setGrid(int x, int y, short& locationNumber)
//{
//    int old = x;
//
//    for (int h = 0; h < Height_SIZE; h++) {
//        for (int w = 0; w < Width_SIZE; w++) {
//            clamping(x, y);
//            if (y >= y_Size || y <= (y_Size - y_Size) || x >= x_Size || x <= (x_Size - x_Size)) {
//                cout << "You going over";
//                system("PAUSE");
//                break;
//            }
//            grid[x][y] = rooms[0].getRoom(w, h);
//            if (w == 0 && h == 0) {
//                pathX[locationNumber] = x;
//                pathY[locationNumber] = y;
//                locationNumber++;
//            }
//            x++;
//        }
//        x = old;
//        y++;
//    }
//}

//void Map::setGrid(int x, int y)
//{
//    clamping(x, y);
//    int old = x;
//    for (int h = 0; h < Height_SIZE; h++) {
//        for (int w = 0; w < Width_SIZE; w++) {
//            if (y >= y_Size || y <= (y_Size - y_Size) || x >= x_Size || x <= (x_Size - x_Size)) {
//                cout << "you going over: " << y << " " << x;
//                system("pause");
//                break;
//            }
//            grid[x][y] = rooms[0].getRoom(w, h);
//            x++;
//        }
//        x = old;
//        y++;
//    }
//}

    /* x += 1;
    y += 1;
    switch (direction)
    {
    case 78:
    case 110:
        if (pathY[y] != pathY[y + 1]) {
            y++;
            roomCleared(pathX[x], pathX[y]);
        }
        else {
            cout << "Choose another direction!";
        };
        break;
    case 'W':
    case 'w':
        if (pathX[x] != pathX[x + 1]) {
            x++;
            roomCleared(pathX[x], pathX[y]);
        }
        else {
            cout << "Choose another direction!";
        };
        break;
    case 'e':
    case 'E':
        if (pathX[x] != pathX[x + 1]) {
           x++;
           roomCleared(pathX[x], pathX[y]);
        }
        else {
           cout << "Choose another direction!";
        };
        break;
    case 'S':
    case 's':
        if (pathY[y] != pathY[y + 1]) {
            x++;
            roomCleared(pathX[x], pathX[y]);
        }
        else {
            cout << "Choose another direction!";
        };
        break;
    default:
        break;
    }*/

    //
    //bool Map::checkWallsAround(short x, short y, int generationDirection)
    //{
    //    clamping(x, y);
    //    short* xPointer = &x;
    //    short* yPointer = &y;
    //    short direction = Width_SIZE + 1;
    //    
    //    // Doesnt include the cases check before running the WallsAround, AKA a single checkWall done before in X direction.
    //    switch (generationDirection)
    //    {
    //        //Up
    //    case 1:
    //        if (checkWall((x + direction), y) == true && checkWall((x - direction), y) == true && checkWall(x, (y + direction)) == true) {
    //            return true;
    //        }
    //        else if (checkWall((x + direction), y) == false && checkWall((x - direction), y) == false) {
    //            int random = rand() % 2;
    //            if (random == 1) {
    //                *xPointer = (x + direction);
    //            }
    //            else {
    //                *xPointer = (x - direction);
    //            }
    //        }
    //        else if(checkWall((x + direction), y) == false){
    //            
    //            *xPointer = (x + direction);
    //        }
    //        else if (checkWall((x - direction), y) == false) {
    //            *xPointer = (x - direction);
    //        }
    //        else if (checkWall(x, (y + direction)) == false) {
    //            *yPointer = (y + direction);
    //        }
    //        break;
    //    case 2:
    //        if (checkWall((x + direction), y) == true && checkWall(x, (y + direction)) == true && checkWall(x, (y - direction)) == true) {
    //            return true;
    //        }
    //        else if (checkWall(x, (y + direction)) == false && checkWall(x, (y - direction)) == false) {
    //            int random = rand() % 2;
    //            if (random == 1) {
    //                *yPointer = (y + direction);
    //            }
    //            else {
    //                *yPointer = (y - direction);
    //            }
    //        }
    //        else if (checkWall((x + direction), y) == false) {
    //
    //            *xPointer = (x + direction);
    //        }
    //        else if (checkWall(x, (y - direction)) == false) {
    //            *xPointer = (x - direction);
    //        }
    //        else if (checkWall(x, (y + direction)) == false) {
    //            *yPointer = (y + direction);
    //        }
    //        break;
    //        //Right
    //    case 3:
    //        if (checkWall(x, (y + direction)) == true && checkWall((x - direction), y) == true && checkWall(x, (y - direction)) == true) {
    //            return true;
    //        }
    //        /*else if (checkWall(x, (y + direction)) == false && checkWall(x, (y - direction)) == false) {
    //            int random = rand() % 2;
    //            if (random == 1) {
    //                *yPointer = (y + direction);
    //            }
    //            else {
    //                *yPointer = (y - direction);
    //            }
    //        }*/
    //        /*else if (checkWall((x - direction), y) == false) {
    //
    //            *xPointer = (x + direction);
    //        }
    //        else if (checkWall(x, (y - direction)) == false) {
    //            *xPointer = (x - direction);
    //        }
    //        else if (checkWall(x, (y + direction)) == false) {
    //            *yPointer = (y + direction);
    //        }*/
    //        break;
    //        //Down
    //    case 4:
    //        if (checkWall((x + direction), y) == true && checkWall((x - direction), y) == true && checkWall(x, (y - direction)) == true){
    //            return true;
    //        }
    //        /*else if (checkWall((x + direction), y) == false && checkWall((x - direction), y) == false) {
    //            int random = rand() % 2;
    //            if (random == 1) {
    //                *xPointer = (x + direction);
    //            }
    //            else {
    //                *xPointer = (x - direction);
    //            }
    //        }*/
    //        /*else if (checkWall((x + direction), y) == false) {
    //
    //            *xPointer = (x + direction);
    //        }
    //        else if (checkWall((x - direction), y) == false) {
    //            *xPointer = (x - direction);
    //        }
    //        else if (checkWall(x, (y - direction)) == false) {
    //            *yPointer = (y + direction);
    //        }*/
    //        break;
    //    default:
    //        break;
    //    }
    //
    //    return false;
    //}

#pragma endregion