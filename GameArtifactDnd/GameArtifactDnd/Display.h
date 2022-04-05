#include <iostream>
#include <iomanip>
#include <Windows.h>

// Include map to have the x_Size and y_Size, defining them here feels wrong
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
/* This defines set the size of the grid map.
Minimun 'y_Size' of the map has to be 22 until I add a way to automatically force it. Otherwise the stats won't show. It has to be divisible by 2. */
#define x_Size 38
#define y_Size 28
#define SET_WIDTH 40
#define ENCOUNTER_COORDINATE_DISPLAY ((x_Size * 3) + SET_WIDTH + 3)
using namespace std;

#pragma once
class Display
{
public:
#pragma region Constructor & Destructor

    Display();
    ~Display();

#pragma endregion

#pragma region Setters & Getters

    void setCursorPosition(int x, int y);
    short getYCoordinate();
    void getCurrentPosition();

#pragma endregion

#pragma region Display Functions

    void clearEncounter();
    void clearConsole();
    void resetCoordinates();
    short biggestLine();
    void plusX(int add);
    void plusY();

    void encounterDisplay(string display, int y);

#pragma endregion





private:
    short* xCoordinatePtn;
    short* transferXCoord;
    short yCoordinate;
    short arraySize;
    short arrayPosition;
};

