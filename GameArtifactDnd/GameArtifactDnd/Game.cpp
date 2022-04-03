#include "Game.h"

 #pragma region Constructor & Destructor

// Constructor
Game::Game()
{
    mainMap = new Map();
    player = new Player();
    mainMap->rooms->encounters->setPlayer(player);
}

// Destructor
Game::~Game()
{
    delete mainMap;
    mainMap = NULL;
    delete player;
    player = NULL;
}

#pragma endregion

 #pragma region Game Functions



// Displays the top line of the game that gives the information needed by the player. This does not include future dialogues. It still needs items/inventory added on the right side
void Game::infoDisplay()
{
    // Update: Moved all cases that shared the line to a single one. Update 2: Change it to be all pointers to their respective classes.
    for (int y = 0; y < y_Size; y++) {
        cout << left << setw(40);
        switch (y) {
        case 0:
            cout << setfill('-') << "-";
            break;
        case 1:
        case 17:
            cout << setfill(' ') << "|";
            break;
        case 2:
            Color(6);
            cout << player[0].displayLine(0);
            Color(15);
            break;
        case 3:
        case 6:
        case 8:
            cout << "|";
            break;
        case 4:
            Color(3);
            cout << player->displayLine(1);
            Color(15);
            break;
        case 5:
            Color(3);
            cout << player->displayLine(2);
            Color(15);
            break;
        case 7:
            Color(2);
            cout << player->displayLine(3);
            Color(15);
            break;
        case 9:
            cout << player->displayLine(4);
            break;
        case 10:
            cout << player->displayLine(5);
            break;
        case 11:
            cout << player->displayLine(6);
            break;
        case 12:
            cout << player->displayLine(7);
            break;
        case 13:
            cout << player->displayLine(8);
            break;
        case 14:
            cout << player->displayLine(9);
            break;
        case 15:
        case 22:
            cout << setfill('-') << "-";
            break;
        case 16:
            Color(6);
            cout << setfill(' ') << "+ Object +";
            Color(15);
            break;
        case 18:
            Color(9);
            cout << player->items[0].displayObjLine(0);
            Color(15);
            break;
        case 19:
            Color(9);
            cout << player->items[0].displayObjLine(1);
            Color(15);
            break;
        case 20:
            Color(9);
            cout << player->items[0].displayObjLine(2);
            Color(15);
            break;
        case 21:
            Color(9);
            cout << player->items[0].displayObjLine(3);
            Color(15);
            break;
        default:
            cout << setfill(' ') << " ";
            break;
        }
        // Left map border
        cout << "|";
        for (int x = 0; x < x_Size; x++) {
            cout << mainMap->getGrid(x, y);
        }
        // Right map border
        cout << "|";
        // Could add objects on right side of the map here
        switch (y) {
        case 0:
        case 15:
            cout << "-----------------------------------";
            break;
        default:
            cout << setfill(' ') << " ";
            break;
        }
        cout << endl;
    }
}

// Trying to make a start screen with a timer to display the game title + a recommendation for full screen. // UPDATE: Now is the function running the game
void Game::gameStart()
{
    short x = 0;
    short y = 0;

    short numResponse1 = 0;
    char response;
    mainMap->roundMap();
    /// <summary>
    /// Changing this function to be updated with the new changes on the functions 
    /// </summary>
    // testing
    while (numResponse1 != 5) {
        infoDisplay();
        cout << mainMap->getPathX(x) << " " << mainMap->getPathY(y) << endl;
        cin >> response;
        mainMap->playerMovement();
        system("CLS");
    }
} 

void Game::Color(char typeColor)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //Prints color to the console. This functions makes it easier to use
    SetConsoleTextAttribute(color, typeColor);
}

#pragma endregion

#pragma region Testing

void Game::MapTesting() {
    short numResponse1 = 0;
    mainMap->roundMap();
    while (numResponse1 != 5) {
        infoDisplay();
        cout << mainMap->getPlayerX() << " " << mainMap->getPlayerY() << endl;
        mainMap->playerMovement();
        cin >> numResponse1;
        system("CLS");
    }
}

void Game::testWallsCheck() {
    for (int i = 0; i < TOTAL_WALLS; i++) {
        cout << mainMap->rooms->roomWalls[i] << " " << i << endl;
    }
}

void Game::MapGenerationTest()
{
    short num1 = 0;
    char response = 'n';

    while (response != 'y') {
        infoDisplay();
        cin >> num1;
        mainMap->fillMap(num1);
        cout << "Type 'y' to finish." << endl;
        cin >> response;
        system("CLS");
    }
}



#pragma endregion

 #pragma region Outdated

    /// In case of a nullptr value, to avoid crashing errors ///
    //  if (player == nullptr) {
    //     handle null case
    //  }
    //  else {
    //     handle case when there is another node
    //  }


    /// Tried to do a starting screen that runs for a few seconds ///
    //
    //  bool timer = false;
    //  while (timer == true) {
    //    cout << endl << endl << endl << "Welcome to Goblin Adventure!";
    //    // The sleep not working?
    //    this_thread::sleep_for(chrono::seconds(10));
    //    timer = true;
    //}

    //while (player->getLevel() != 10) {
    //infoDisplay();
    //cout << "new level! select your new level." << endl;
    //cin >> numResponse;
    //system("CLS");
    //player->setLevel(numResponse);
    //cout << "here is your new stats!" << endl;
    // }

        //case 1:
        //    cout << player->items[0].displayObjLine(0);
        //    break;
        //case 2:
        //    cout << player->items[0].displayObjLine(1);
        //    break;
        //case 3:
        //    cout << player->items[0].displayObjLine(2);
        //    break;
        //case 4:
        //    cout << player->items[0].displayObjLine(3);
        //    break;
        //case 5:
        //    cout << player->items[0].displayObjLine(4);
        //    break;
        //case 7:
        //    cout << player->items[1].displayObjLine(0);
        //    break;
        //case 8:
        //    cout << player->items[1].displayObjLine(1);
        //    break;
        //case 9:
        //    cout << player->items[1].displayObjLine(2);
        //    break;
        //case 10:
        //    cout << player->items[1].displayObjLine(3);
        //    break;
        //case 11:
        //    cout << player->items[1].displayObjLine(4);
        //    break;
        //case 13:
        //    cout << player->items[2].displayObjLine(0);
        //    break;
#pragma endregion