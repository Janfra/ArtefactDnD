#include "Game.h"

 #pragma region Constructor & Destructor

// Constructor
Game::Game()
{
    mainMap = new Map();
    player = new Player();
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

bool Game::questionYesOrNo(string question) {
    bool rv = NULL;
    string answer;

    cout << endl << question << endl;

    while (rv == NULL) {
        cin >> answer;
        if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y") {
            rv = true;
            return rv;
        }
        else if (answer == "No" || answer == "no" || answer == "n" || answer == "N") {
            rv = false;
            return rv;
        }
        else {
            system("CLS");
            infoDisplay();
            cout << endl << "Invalid response! It has to be 'Yes' or 'No'!" << endl << question << endl;
        }
    }
    return rv;
}

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
            cout << setfill(' ') << "|";
            break;
        case 2:
            cout << player[0].displayLine(0);
            break;
        case 3:
        case 6:
        case 8:
            cout << "|";
            break;
        case 4:
            cout << player->displayLine(1);
            break;
        case 5:
            cout << player->displayLine(2);
            break;
        case 7:
            cout << player->displayLine(3);
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
            cout << setfill('-') << "-";
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
        case 6:
        case 12:
            cout << "-----------------------------------";
            break;
        case 1:
            cout << player->items[0].displayObjLine(0);
            break;
        case 2:
            cout << player->items[0].displayObjLine(1);
            break;
        case 3:
            cout << player->items[0].displayObjLine(2);
            break;
        case 4:
            cout << player->items[0].displayObjLine(3);
            break;
        case 5:
            cout << player->items[0].displayObjLine(4);
            break;
        case 7:
            cout << player->items[1].displayObjLine(0);
            break;
        case 8:
            cout << player->items[1].displayObjLine(1);
            break;
        case 9:
            cout << player->items[1].displayObjLine(2);
            break;
        case 10:
            cout << player->items[1].displayObjLine(3);
            break;
        case 11:
            cout << player->items[1].displayObjLine(4);
            break;
        case 13:
            cout << player->items[2].displayObjLine(0);
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
        cout << mainMap->pathX[x] << " " << mainMap->pathY[y] << endl;
        cin >> response;
        mainMap->playerMovement(response, x, y);
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

#pragma endregion