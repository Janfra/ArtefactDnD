// GameArtifactDnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "Game.h"

using namespace std;

//Moved class stats, player and functions statSheet and questionYesOrNo to separated files. Considering merging the functions into the player class, questionYesOrNo into a general functions class

int main()
{
    Game mainGame;
        
    mainGame.gameStart();

        delete mainGame.mainMap;
        mainGame.mainMap = NULL;
        delete mainGame.player;
        mainGame.player = NULL;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
