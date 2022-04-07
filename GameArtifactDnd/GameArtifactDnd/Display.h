// Makes it possible to use the console functions. In this case is used for using cout.
#include <iostream>
#include <iomanip>
#include <Windows.h>

    // DEFINES //
// Necessary for the setCursorPosition function //
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

/* This defines set the size of the grid map.
Minimun 'y_Size' of the map has to be 22 until I add a way to automatically force it. Otherwise the stats won't show. It has to be divisible by 2. */
#define x_Size 38
#define y_Size 26

// Value for setw() in infoDisplay inside the Game Class //
#define SET_WIDTH 40

/* Defines how far in the 'xCoordinate' the setCursorPosition() has to go to be inside the encounter display section in infoDisplay(). 
*It multiplies 'x_Size' because it includes 3 char in each string and +3 because there is 2 lines separating the map and the displays +1 to not be inside the line */
#define ENCOUNTER_COORDINATE_DISPLAY ((x_Size * 3) + SET_WIDTH + 3)

using namespace std;

#pragma once
class Display
{
public:
#pragma region Constructor & Destructor
    // CONSTRUCTOR //
    Display();

    // DESTRUCTOR //
    ~Display();

#pragma endregion

#pragma region Setters & Getters
    // SETTERS //
    void setCursorPosition(int x, int y);
    void setCursorBottom();

    // GETTERS //
    short getYCoordinate();
    // Still not done, will get a coordinate
    void getCurrentPosition();

#pragma endregion

#pragma region Display Functions
    // Clear Functions //
    void clearEncounter();
    void clearEncounter(int y);
    void clearConsole();
    void clearEncounterDisplay(bool clearDescription);
    // Reset the variables, done when a full new display is generated
    void resetCoordinates();

    // Coordinate Functions //
    void plusX(int add);
    void plusY();
    short biggestLine();

    //  Encounter display functions //
    void encounterDisplay(string display, int y);
    void encounterDisplay(string display, int y, char colour);
    void encounterDescription(short encounterNumber);
    void descriptionNextLine(short& descriptionY);
    void descriptionText(string str, char del);
    void encounterAnnouncement(string display);

    void playerHPDisplay(string update);

    // Color changing function, credits to: Martin Sanz // 
    void Color(char typeColor);

#pragma endregion

private:
    short* xCoordinatePtn;
    short* transferXCoord;
    short yCoordinate;
    short arraySize;
    short arrayPosition;
};

