#include "Map.h"

 #pragma region Constructor & Destructor
    // CONSTRUCTOR //
Map::Map()
{
    // Initializing the values for every global variable.
    rooms = new Room();
    totalRooms = 0;
    posX = (X_SIZE / 2 - (WIDTH_SIZE / 2));
    posY = (Y_SIZE - (HEIGHT_SIZE + 1));
    playerX = posX;
    playerY = posY;
    playerLocationNumber = 0;
    arrayLocation = 0;

        // Generates the empty map display (without including the rooms)
    for (int y = 0; y < Y_SIZE; y++) {
        for (int x = 0; x < X_SIZE; x++) {
            // Top map border
            if (y == (X_SIZE - X_SIZE)) {
                grid[x][y] = "~~~";
            }
            // Bottom map border
            else if (y == (Y_SIZE - 1)) {
                grid[x][y] = "~~~";
            }
            // The inside of the map
            else {
                grid[x][y] = "   ";
            }
        }
    }
}

    // DESTRUCTOR //
Map::~Map()
{  
    // Clears space in the heap and prevents hanging pointers //
    delete rooms;
    rooms = NULL;
}
#pragma endregion

 #pragma region Getters & Setters

// This function is used to assign the rooms to the map grid and display them. It also stores the path used when generating them for the player to follow. 
void Map::setGrid(int x, int y, short direction)
{
    clamping(x, y);
    int old = x;
    // Store direction for the player to follow.
    switch (direction)
    {
    case 1:
        pathX[arrayLocation] = 0;
        pathY[arrayLocation] = -HEIGHT_SIZE - 1;
        break;
    case 2:
        pathX[arrayLocation] = -WIDTH_SIZE - 1;
        pathY[arrayLocation] = 0;
        break;
    case 3:
        pathX[arrayLocation] = WIDTH_SIZE + 1;
        pathY[arrayLocation] = 0;
        break;
    case 4:
        pathX[arrayLocation] = 0;
        pathY[arrayLocation] = HEIGHT_SIZE + 1;
        break;
    default:
        break;
    }
    arrayLocation++;

    // Nested for loop to go over all the assigned room array grid to assign it to the map grid to display it. Basically copy pasting the room format into the map.
    for (int h = 0; h < HEIGHT_SIZE; h++)
    {
        for (int w = 0; w < WIDTH_SIZE; w++) 
        {
            if (y >= Y_SIZE || y <= (Y_SIZE - Y_SIZE) || x >= X_SIZE || x <= (X_SIZE - X_SIZE)) 
            {
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

// Set the value for 'posX' and clamp it.
void Map::setPosX(short x)
{
    // Clamp the 'x' parameter in between a minimun value of 0 and a maximum value of 'X_SIZE' (total x value of the map).
    if (x > X_SIZE) 
    {
        posX = X_SIZE - 1;
    }
    else if (x <= 0) 
    {
        posX = 1;
    }
    else 
    {
        posX = x;
    }
}

// Set the value for 'posY' and clamp it.
void Map::setPosY(short y)
{
    // Clamp the 'y' parameter in between a minimun value of 0 and a maximum value of 'Y_SIZE' (total y value of the map).
    if (y > Y_SIZE) 
    {
        posY = Y_SIZE - 1;
    }
    else if (y <= 0) 
    {
        posY = 1;
    }
    else 
    {
        posY = y;
    }
}

// Returns value in the 2D grid using the 'x' and 'y' parameters to set which to return. getGrid function was created to be able to output the grid map on display function.
string Map::getGrid(short x, short y)
{
    // Clamp 'x' parameter to not go over the grid
    if (x < 0) 
    {
        x = 0;
    }
    else if (x > X_SIZE) 
    {
        x = (X_SIZE - 1);
    }

    // Clamp 'y' parameter to not go over the grid
    if (y < 0) 
    {
        y = 0;
    }
    else if (y > Y_SIZE) 
    {
        y = (Y_SIZE - 1);
    }
    return grid[x][y];
}

// Returns total amount of rooms
short Map::getTotalRooms()
{
    return totalRooms;
}

// Clamp 'arrayPosition' parameter given and return value in 'pathX' array
int Map::getPathX(int arrayPosition)
{
    if (arrayPosition >= 19) 
    {
        arrayPosition = 19;
    }
    else if (arrayPosition < 0) 
    {
        arrayPosition = 0;
    }
    return pathX[arrayPosition];
}

// Clamp 'arrayPosition' parameter given and return value in 'pathY' array
int Map::getPathY(int arrayPosition)
{
    if (arrayPosition >= 19) 
    {
        arrayPosition = 19;
    }
    else if (arrayPosition < 0) 
    {
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



#pragma endregion

 #pragma region Map Functions

// Manually generated map. It marks as "cleared" the first room. Adds an extra room that is taken out by last drawRooms.
void Map::roundMap()
{
    // Left
    drawRooms(2);
    // Up
    drawRooms(1);
    // Right
    drawRooms(3);
    // Down
    drawRooms(4);
    roomCleared(playerX, playerY);
}

/* Draws/Assings the rooms into the map grid using the Room class. 'direction' parameter sets the direction the rooms will be generated.
   Could update to use a random number generator to fully create the map */
void Map::drawRooms(int direction)
{
    // Local variable to randomly generate the room types. First time this function is called, generates default room.
    int randomNumber = 0;

    // Overwrites the rooms it goes over, after first use there is an extra room. Take extra room off after first used.
    if (posY != playerY || posX != playerX) 
    {
        totalRooms -= 1;
    }

    // Using 'direction' parameter, determine in which direction to generate the rooms.
    switch (direction)
    {
        // Case 1 = Up. *To move up it takes away (-) from 'posY'.
    case 1:
        // Run for loop until hitting the grid top. + 1 to the room sizes to leave space for halls.
        for (int y = posY; y > 0; y -= HEIGHT_SIZE + 1) 
        {
            // Set 'posY' as 'y' to update to the new starting position next time the function is called. 
            setPosY(y);

            // If it's not the first iteration, set to a random room type.
            rooms->setType(randomNumber);
            
            // Create new random number for setType()
            randomNumber = (rand() % 15) + 1;
            
            // Check if it is the last iteration of the for loop. 
            if (y <= HEIGHT_SIZE + 1) 
            {
                // Avoid creating a path for the extra room. *This variable is used in setGrid().
                arrayLocation--;
            }

            // Draw the current room type in the current grid position, giving the direction and updated position with 'y' condition in this case.
            setGrid(posX, y, direction);
                            // Add one to totalRooms, this is done every iteration because each iteration generates one more room.
            totalRooms++;
        }
        break;
        // Case 2 = Left. *To move left it takes away (-) from 'posX'. 
    case 2:
        // The inside of the for loop is the same as in case 1 but exchanging 'posY' with 'posX', and 'y' with 'x' to match.
        for (int x = posX; x > 0; x -= WIDTH_SIZE + 1) 
        {
            setPosX(x);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (x <= WIDTH_SIZE + 1) 
            {
                arrayLocation--;
            }
            setGrid(x, posY, direction);
            totalRooms++;
        }
        break;
        // Case 3 = Right. *To move right it adds (+) to 'posX'. 
    case 3:
        /* The inside of the for loop is the same as in case 1 but exchanging 'posY' with 'posX', 'y' with 'x' to match and
        now adding instead of subtracting. Condition in this case leaves a small margin. */
        for (int x = posX; x < (X_SIZE - 2); x += WIDTH_SIZE + 1) 
        {
            setPosX(x);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (x >= (X_SIZE - (WIDTH_SIZE + 2))) 
            {
                arrayLocation--;
            }
            setGrid(x, posY, direction);
            totalRooms++;
        }
        break;
        // Case 4 = Down. *To move down it adds (+) to 'posY'.
    case 4:
        // The inside of the for loop is the same as in case 1 but now adding instead of subtracting. Condition in this case leaves a small margin.
        for (int y = posY; y < (Y_SIZE - 2); y += HEIGHT_SIZE + 1) 
        {
            setPosY(y);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (y >= (Y_SIZE - (HEIGHT_SIZE + 1))) 
            {
                arrayLocation--;
            }
            setGrid(posX, y, direction);
            totalRooms++;
        }
        break;
    default:
        break;
    }
}

// Display the rooms location given with the parameters 'x' and 'y' as cleared on the grid.
void Map::roomCleared(int x, int y)
{
    clamping(x, y);
    // Store the 'x' parameter value to reset it in the nested for loop to simulate the restart of the parameter inside the second for loop. 
    int old = x;

    // Nested for loop to go over all the room grid to change the inside to be in a "cleared" state. 'h' = height/y, changes the row
    for (int h = 0; h < HEIGHT_SIZE; h++) 
    {
        // 'w' = width/x. Goes through all columns in this row
        for (int w = 0; w < WIDTH_SIZE; w++) 
        {
            // Check that it does not go outside the grid, if it does cout values exceeding limit and finish this for loop.
            if (y >= Y_SIZE || y <= (Y_SIZE - Y_SIZE) || x >= X_SIZE || x <= (X_SIZE - X_SIZE)) 
            {
                cout << "You going over " << x << " " << y << " " << endl;
                system("PAUSE");
                break;
            }
            // Check that the values changed are of the inside of the room. Avoid min and max values of 'w' and 'h'.
            if (h > 0 && w > 0 && w < (WIDTH_SIZE - 1) && h < (HEIGHT_SIZE - 1)) 
            {
                grid[x][y] = " + ";
            }
            // Simulate the addition on 'w' in this for loop. They are done separately as the coordinates in the grid are different from the room.
            x++;
        }
        // Reset 'x' to its initial value before the loop.
        x = old;
        y++;
    }
}

// Displays the player movement on the map, amount of rooms left and initiate an encounter depending on the rooms wall type. 
void Map::playerMovement()
{
    // Display rooms left
    rooms->encounters->display.setCursorPosition(SET_WIDTH + (X_SIZE * 3) / 2, Y_SIZE + 1);
    cout << playerLocationNumber << " / " << totalRooms;

    // Initiate encounter
    switch (checkWall(playerX, playerY))
    {
    case 0:
        rooms->encounters->healingFountain();
        break;
    case 1:
        rooms->encounters->enemyEncounter();
        break;
    case 2:
        rooms->encounters->trapEncounter();
        break;
    case 3:
        rooms->encounters->foundItem();
        break;
    case 4:
        rooms->encounters->healingFountain();
        break;
    default:
        break;
    }

    // Check that there are rooms left to move to and that player is not in an encounter
    if (playerLocationNumber < totalRooms && rooms->encounters->encounterInProcess == false) 
    {
        // Clamp player movement inside the grid
        if (playerY > 0 || playerX > 0 || playerY < (Y_SIZE - 2) || playerX < (X_SIZE - 2)) 
        {
            // Update player position to the next room. *setGrid() for clarity
            playerX += pathX[playerLocationNumber];
            playerY += pathY[playerLocationNumber];
        }
        // Update to the next room direction stored and current player location as cleared
        playerLocationNumber++;
        roomCleared(playerX, playerY);
    }
    // Else if there is no more rooms to clear, finish main game loop. 
    else if (playerLocationNumber == totalRooms) 
    {
        rooms->encounters->winPtn[0] = true;
    }
}

// Clamp functions to avoid going over the map limits.
void Map::clamping(short& x, short& y)
{
    if (x < 1) 
    {
        x = 1;
    }
    else if (x > X_SIZE) 
    {
        x = (X_SIZE - 1);
    };
    if (y < 1) {
        y = 1;
    }
    else if (y > Y_SIZE) 
    {
        y = (Y_SIZE - 1);
    };
}

// Clamp rooms generation. Updated this clamp to change its values to take in consideration that when this clamp is used it is inside a function that will add '5' to it.
void Map::clamping(int& x, int& y)
{
    // 1 and +1 to avoid changing the wall borders that are situated at the '0' coordinates.
    if (x < 1) 
    {
        x = 1;
    }
    else if (x > (X_SIZE - WIDTH_SIZE)) 
    {
        x = (X_SIZE - (WIDTH_SIZE + 1));
    };
    if (y < 1) 
    {
        y = 1;
    }
    else if (y > (Y_SIZE - HEIGHT_SIZE)) 
    {
        y = (Y_SIZE - (HEIGHT_SIZE + 1));
    };
}

// Checks the wall of the current room of the player to determine which encounter to start.
short Map::checkWall(short x, short y) 
{
    // Local variable with the room type number.
    short typeNumber = 0;

    // For loop going by the total amount of walls that can be checked. Checks the walls of each room type until finding a match.
    for (int n = 0; n < TOTAL_WALLS; n++) 
    {
        if (getGrid(x, y) == rooms->roomWalls[n]) 
        {
            switch (n)
            {
            case 0:
            case 1:
            case 2:
                return typeNumber;
                break;
            case 3:
            case 4:
            case 5:
                return typeNumber;
                break;
            case 6:
            case 7:
            case 8:
                return typeNumber;
                break;
            case 9:
            case 10:
            case 11:
                return typeNumber;
                break;
            case 12:
            case 13:
            case 14:
                return typeNumber;
                break;
            default:
                break;
            }
        }
        // 3 in this case because there is a total of 3 walls per type, so if it already check 3 walls of a type, go to the next type.
        if (n % 3 == 2) 
        {
            typeNumber++;
        }
    }
    return -1;
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
    //	for (int y = 0; y < Y_SIZE; y++) {
    //        // This for is to create emtpy space and center the map
    //            for (int space = 0; space < emptySpace; space++) {
    //                cout << "   ";
    //            }
    //            // Left map border
    //            cout << "|";
    //            for (int x = 0; x < X_SIZE; x++) {
    //                // Top map border
    //                if (y == (X_SIZE - 1)){
    //                    cout << "~~~";
    //                    }
    //                // Bottom map border
    //                else if (y == (Y_SIZE - 1)) {
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
//    for (int h = 0; h < HEIGHT_SIZE; h++) {
//        for (int w = 0; w < WIDTH_SIZE; w++) {
//            clamping(x, y);
//            if (y >= Y_SIZE || y <= (Y_SIZE - Y_SIZE) || x >= X_SIZE || x <= (X_SIZE - X_SIZE)) {
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
//    for (int h = 0; h < HEIGHT_SIZE; h++) {
//        for (int w = 0; w < WIDTH_SIZE; w++) {
//            if (y >= Y_SIZE || y <= (Y_SIZE - Y_SIZE) || x >= X_SIZE || x <= (X_SIZE - X_SIZE)) {
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
    //    short direction = WIDTH_SIZE + 1;
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

    /*   if (posX != playerX && posY != playerY) {*/
    //totalRooms -= 2;
    //}

//string Map::getRoomType(int n)
//{
//    return string(roomTypes[n]);
//}

    // Create the new dynamic variable with the total amount of rooms. Possibly change this.
    // roomTypes = new string[totalRooms];

//void Map::playerClamping(short& x, short& y)
//{
//    if (x < 1) {
//        x = 2;
//    }
//    else if (x >= (X_SIZE - (WIDTH_SIZE + 1))) {
//        x = (X_SIZE - (WIDTH_SIZE + 2));
//    };
//    if (y < 1) {
//        y = 3;
//    }
//    else if (y >= (Y_SIZE - (HEIGHT_SIZE + 1))) {
//        y = (Y_SIZE - (HEIGHT_SIZE + 1));
//    };
//}

#pragma endregion