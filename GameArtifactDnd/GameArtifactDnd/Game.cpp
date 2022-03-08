        //if (player == nullptr) {
        //    // handle null case
        //    
        //}
        //else {
        //    // handle case when there is another node
        //}
#include "Game.h"

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

// Trying to make a start screen with a timer to display the game title + a recommendation for full screen. 
void Game::gameStart()
{
       bool timer = false;
       while (timer == true) {
           cout << endl << endl << endl << "Welcome to Goblin Adventure!";
           // The sleep not working?
           this_thread::sleep_for(chrono::seconds(10));
           timer = true;
       }
}

// Displays the top line of the game that gives the information needed by the player. This does not include future dialogues. It still needs items/inventory added on the right side
void Game::infoDisplay()
{
    // Update: Moved all cases that shared the line to a single one. Update 2: Change it to be all pointers to their respective classes.
    for (int y = 0; y < y_Size; y++) {
        cout << left << setw(35);
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
