// Makes it possible to use the console functions. In this case is used for using cout. //
#include <iostream>
#include <iomanip>
// Windows is necessary for the setCursorPosition() to function properly. //
#include <Windows.h>

    // DEFINES //
// Necessary for the setCursorPosition() function //
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

/* This defines set the size of the grid map.
Minimun 'Y_SIZE' of the map has to be 22 until I add a way to automatically force it. Otherwise the stats won't show. It has to be divisible by 2. */
#define X_SIZE 38
#define Y_SIZE 26

// Value for setw() in infoDisplay() function inside the Game Class //
#define SET_WIDTH 40

/* Defines how far in the 'xCoordinate' the setCursorPosition() has to go to be inside the encounter display section in infoDisplay(). 
*It multiplies 'X_SIZE' because it includes 3 char in each string and +3 because there is 2 lines separating the map and the displays +1 to not be inside the line */
#define ENCOUNTER_COORDINATE_DISPLAY ((X_SIZE * 3) + SET_WIDTH + 3)

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

#pragma endregion

#pragma region Display Functions
    // Clear Functions //
    void clearEncounter();
    void clearEncounter(int y);
    void clearConsole();
    void clearEncounterDisplay(bool clearDescription);
    // Reset the variables, done when a full new display is generated //
    void resetCoordinates();

    // Coordinate Functions //
    void plusX(int add);
    void plusY();
    void minusY();



    //  Encounter display functions //
    void displayClamp(int& y);
    void encounterDisplay(string display, int y);
    void encounterDisplay(string display, int y, char colour);
    void encounterDescription(short encounterNumber);
    void descriptionNextLine(short& descriptionY);
    void descriptionText(string str, char del, short& descriptionY);
    bool checkDescriptionLimit(short characters) const;
    void encounterAnnouncement(string display);

    void playerHPDisplay(string update);

    // Color changing function, credits to: Martin Sanz // 
    void Color(char typeColor);

#pragma endregion

private:
    // Stores the x coordinates for setCursorPosition() //
    short* xCoordinatePtn;
    // Used to temporarily store the 'xCoordinatePtn' array to update it //
    short* transferXCoord;
    // Defines the size of the array for x coordinates // 
    short arraySize;
    // Used to define the position in array for the x coordinates array //
    short arrayPosition;
    // Stores the y coordinates for setCursorPosition() //
    short yCoordinate;
};

