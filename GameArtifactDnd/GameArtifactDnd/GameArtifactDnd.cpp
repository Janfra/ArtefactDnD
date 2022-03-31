// GameArtifactDnd.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include "Game.h"
#include <Windows.h>


using namespace std;

//Moved class stats, player and functions statSheet and questionYesOrNo to separated files. Considering merging the functions into the player class, questionYesOrNo into a general functions class

int main()
{
    // Taken from https://www.daniweb.com/, wanted to force a bigger screen to make it possible to have a bigger map.
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 600, TRUE);
    //

    Game mainGame;
    //int x = (x_Size / 2 - (Width_SIZE / 2));
    //int y = (y_Size - (Height_SIZE + 1));
    //mainGame.mainMap->setGrid((x_Size / 2 - (Width_SIZE / 2)), (y_Size - (Height_SIZE + 1))); 
    //mainGame.mainMap->setGrid((x + 5), (y));
    //mainGame.mainMap->setGrid((x + 10), (y));
    //mainGame.mainMap->setGrid((x + 15), (y));

    mainGame.MapTesting();


    /*mainGame.gameStart();*/

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
