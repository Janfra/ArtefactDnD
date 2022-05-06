#include "Game.h"

 #pragma region Constructor & Destructor

    // CONSTRUCTOR //
Game::Game()
{
    mainMap = new Map();
    player = new Player();
}

    // DESTRUCTOR //
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
        cout << left << setw(SET_WIDTH);
        switch (y) {
        case 0:
            cout << setfill('-') << "-";
            break;
        case 1:
        case 17:
            cout << setfill(' ') << "|";
            break;
        case 2:
            mainMap->rooms->encounters->display.Color(6);
            cout << player[0].displayLine(0); 
            mainMap->rooms->encounters->display.plusX(player->displayLine(0).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 3:
        case 6:
        case 8:
            cout << "|";
            break;
        case 4:
            mainMap->rooms->encounters->display.Color(3);
            cout << player->displayLine(1);
            mainMap->rooms->encounters->display.plusX(player->displayLine(1).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 5:
            mainMap->rooms->encounters->display.Color(3);
            cout << player->displayLine(2);
            mainMap->rooms->encounters->display.plusX(player->displayLine(2).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 7:
            mainMap->rooms->encounters->display.Color(2);
            cout << player->displayLine(3);
            mainMap->rooms->encounters->display.plusX(player->displayLine(3).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 9:
            cout << player->displayLine(4);
            mainMap->rooms->encounters->display.plusX(player->displayLine(4).length());
            break;
        case 10:
            cout << player->displayLine(5);
            mainMap->rooms->encounters->display.plusX(player->displayLine(5).length());
            break;
        case 11:
            cout << player->displayLine(6);
            mainMap->rooms->encounters->display.plusX(player->displayLine(6).length());
            break;
        case 12:
            cout << player->displayLine(7);
            mainMap->rooms->encounters->display.plusX(player->displayLine(7).length());
            break;
        case 13:
            cout << player->displayLine(8);
            mainMap->rooms->encounters->display.plusX(player->displayLine(8).length());
            break;
        case 14:
            cout << player->displayLine(9);
            mainMap->rooms->encounters->display.plusX(player->displayLine(9).length());
            break;
        case 15:
        case 22:
            cout << setfill('-') << "-";
            break;
        case 16:
            mainMap->rooms->encounters->display.Color(6);
            cout << setfill(' ') << "+ Object +";
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 18:
            mainMap->rooms->encounters->display.Color(9);
            cout << player->items[0].displayObjLine(0);
            mainMap->rooms->encounters->display.plusX(player->items[0].displayObjLine(0).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 19:
            mainMap->rooms->encounters->display.Color(9);
            cout << player->items[0].displayObjLine(1);
            mainMap->rooms->encounters->display.plusX(player->items[0].displayObjLine(1).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 20:
            mainMap->rooms->encounters->display.Color(9);
            cout << player->items[0].displayObjLine(2);
            mainMap->rooms->encounters->display.plusX(player->items[0].displayObjLine(2).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        case 21:
            mainMap->rooms->encounters->display.Color(9);
            cout << player->items[0].displayObjLine(3);
            mainMap->rooms->encounters->display.plusX(player->items[0].displayObjLine(3).length());
            mainMap->rooms->encounters->display.Color(15);
            break;
        default:
            cout << setfill(' ') << " ";
            break;
        }
        // Left map border
        cout << "|";
        for (int x = 0; x < x_Size; x++) {
            cout << mainMap->getGrid(x, y);
            mainMap->rooms->encounters->display.plusX(mainMap->getGrid(x, y).length());
        }
        // Right map border
        cout << "|";
        // Enemies display or encounter display
        switch (y) {
        case 0:
        case 9:
            cout << "-----------------------------------";
            break;
        case 10:
            mainMap->rooms->encounters->display.Color(10);
            cout << "            DESCRIPTION            ";
            mainMap->rooms->encounters->display.Color(15);
        case 1:
        default:
            cout << setfill(' ') << " ";
            break;
        }
        cout << endl;
        mainMap->rooms->encounters->display.plusY();
    }
}

// Starts the game and runs the main game loop
void Game::gameStart()
{
    // Local variable to wait for player input
    string response = " ";
    // Local variable to define when the game loop finishes
    bool* win = new bool(false);

    // Introduction display
    mainMap->rooms->encounters->display.Color(15);
    cout << endl << "You wake up in a weird and obscure passage, the only thing you can see is a fountain at the distance." << endl << endl
         << "You look down at your ";
    mainMap->rooms->encounters->display.Color(6);
    cout << "green ";
    mainMap->rooms->encounters->display.Color(15);
    cout << "arms confused." << endl << endl << "Next to you lays a ";
    mainMap->rooms->encounters->display.Color(9);
    cout << "dagger";
    mainMap->rooms->encounters->display.Color(15);
    cout << " you pick it up and approach the fountain while trying to remember your name..." << endl << endl;

    mainMap->rooms->encounters->display.Color(7);
    cout << "What is your name, little goblin?" << endl;
    cin >> response;
    player->setName(response);

    // Initiates main game loop
    mainMap->rooms->encounters->display.clearConsole();
    mainMap->roundMap();
    mainMap->rooms->encounters->setPlayer(player);
    mainMap->rooms->encounters->setWin(win);
    while (win[0] == false) 
    {
        infoDisplay();
        mainMap->playerMovement();
        cin >> response;
        mainMap->rooms->encounters->display.resetCoordinates();
    }

    // Game finishes
    win = NULL;
    mainMap->rooms->encounters->display.clearConsole();
    cout << left << setw(70) << setfill(' ') << endl << endl << endl << " " << "Game Finish!" << endl << endl << endl << endl << endl << endl << endl;
} 

#pragma endregion

#pragma region Testing

void Game::MapTesting() {
    string Response1 = " ";
    mainMap->roundMap();
    mainMap->rooms->encounters->setPlayer(player);
    while (Response1 != "End") {
        infoDisplay();
        cout << mainMap->getPlayerX() << " " << mainMap->getPlayerY() << endl;
        mainMap->playerMovement();
        cin >> Response1;
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

void Game::displayRewritingTest() {
    string response = " ";
    mainMap->roundMap();
    mainMap->rooms->encounters->setPlayer(player);
    while (response != "END") {
        mainMap->rooms->encounters->display.setCursorPosition(0, 0);
        infoDisplay();
        mainMap->playerMovement();
        cin >> response;
        mainMap->rooms->encounters->display.resetCoordinates();
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

//string response = " ";
//mainMap->roundMap();
//mainMap->rooms->encounters->setPlayer(player);
//while (response != "END") {
//    gameDisplay.setCursorPosition(0, 0);
//    infoDisplay();
//    mainMap->playerMovement();
//    cin >> response;
//}
#pragma endregion