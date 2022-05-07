// GameArtifactDnd.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Including the game class that has all the other classes in the game. 
#include "Game.h"

int main()
{
    // Taken from https://www.daniweb.com/, wanted to force a bigger screen to make it possible to have a bigger map.
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 700, TRUE);
    //

    Game mainGame;
    mainGame.mainGameLoop();
}

#pragma region Testing-Outdated
//int x = (X_SIZE / 2 - (WIDTH_SIZE / 2));
    //int y = (Y_SIZE - (HEIGHT_SIZE + 1));
    //mainGame.mainMap->setGrid((X_SIZE / 2 - (WIDTH_SIZE / 2)), (Y_SIZE - (HEIGHT_SIZE + 1))); 
    //mainGame.mainMap->setGrid((x + 5), (y));
    //mainGame.mainMap->setGrid((x + 10), (y));
    //mainGame.mainMap->setGrid((x + 15), (y));
#pragma endregion

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
