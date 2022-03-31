#include "Map.h"

 #pragma region Constructor & Destructor

Map::Map()
{
    rooms = new Room();
    totalRooms = 0;
    posX = (x_Size / 2 - (Width_SIZE / 2));
    playerX = (x_Size / 2 - (Width_SIZE / 2));
    playerY = (y_Size - (Height_SIZE + 1));
    posY = (y_Size - (Height_SIZE + 1));
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
    playerLocationNumber = 0;
    arrayLocation = 0;
}

Map::~Map()
{  
    delete rooms;
    rooms = NULL;
}
#pragma endregion

 #pragma region Getters & Setters

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

void Map::setPosX(short x)
{
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
// I haven't tested it, but it should also block the player from going under or over the limits. After writing that... Actually, probably not.
string Map::getGrid(short x, short y)
{
    if (x <= 0) {
        x = 0;
    }
    else if (x > x_Size) {
        x = (x_Size - 1);
    };
    if (y <= 0) {
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

void Map::roundMap()
{
    fillMap(2);
    fillMap(1);
    fillMap(3);
    fillMap(4);

    roomCleared(playerX, playerY);
}

void Map::fillMap(int direction)
{
    // I will use an integer so that I can use a random number generator to decide in which direction the rooms are generated. Up = 1
    int randomNumber = 0;
    switch (direction)
    {
    case 1:
        // Fill till the wall up so, total and it goes 'up' by taking away
        for (int i = posY; i > 0; i -= Height_SIZE + 1) {
            setPosY(i);
            rooms->setType(randomNumber);
            randomNumber = (rand() % 15) + 1;
            if (i <= Height_SIZE + 1) {
                arrayLocation--;
            }
            setGrid(posX, i, direction);
            totalRooms++;
        }
        break;
    case 2:
        // Fill till the wall left, total and to go left it takes away 
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
        // Fill till the wall right, total and to go right it adds up
    case 3:
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
    case 4:
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

void Map::roomCleared(int x, int y)
{
    int old = x;
    clamping(x, y);

    for (int h = 0; h < Height_SIZE; h++) {
        for (int w = 0; w < Width_SIZE; w++) {
            if (y >= y_Size || y <= (y_Size - y_Size) || x >= x_Size || x <= (x_Size - x_Size)) {
                cout << "You going over " << x << " " << y << " " << endl;
                system("PAUSE");
                break;
            }
            if (h > 0 && w > 0 && w < (Width_SIZE - 1) && h < (Height_SIZE - 1)) {
                grid[x][y] = " + ";
            }
            x++;
        }
        x = old;
        y++;
    }
}

void Map::playerMovement()
{
    if (playerLocationNumber + 2 < totalRooms) {
    if (playerY > 0 || playerX > 0 || playerY < (y_Size - 2) || playerX < (x_Size - 2)) {
        playerX += pathX[playerLocationNumber];
        playerY += pathY[playerLocationNumber];
    }
    playerLocationNumber++;
    playerClamping(playerX, playerY);
    roomCleared(playerX, playerY);
    }

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
}

//bool Map::checkWall(short x, short y)
//{
//    for (int n = 0; n < TOTAL_WALLS; n++) {
//        if (getGrid(x, y) == rooms->roomWalls[n]) {
//            return true;
//        }
//    }
//    
//    return false;
//}
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

void Map::clamping(int& x, int& y)
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


#pragma endregion