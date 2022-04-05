#include "Display.h"



Display::Display()
{
    arrayPosition = 0;
    arraySize = 1;
    xCoordinatePtn = new short[arraySize];
    xCoordinatePtn[0] = 0;
    transferXCoord = new short[arraySize];
    transferXCoord[0] = 0;
    yCoordinate = 0;
}

Display::~Display()
{
    delete xCoordinatePtn;
    xCoordinatePtn = NULL;
    delete transferXCoord;
    transferXCoord = NULL;
}

void Display::setCursorPosition(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, SHORT(y) };
    SetConsoleCursorPosition(hOut, coord);
}

void Display::clearEncounter()
{
    setCursorPosition(0, (y_Size + 1));
    for (int i = (y_Size + 1); i < (y_Size + 11); i++) {
        for (int x = 0; x < 40; x++) {
            setCursorPosition(x, i);
            cout << " ";
        }
    }
}

void Display::clearConsole()
{
    for (int y = 0; y < yCoordinate + 5; y++) {
        for (int x = 0; x < biggestLine(); x++) {
            setCursorPosition(x, y);
            cout << "   ";
        }
    }
    resetCoordinates();
}

void Display::getCurrentPosition()
{

}

void Display::plusX(int add)
{
    // Assign a value to the current position of the array.
    xCoordinatePtn[arrayPosition] = add;
    // Assign that same value to the same position on the transfer.
    transferXCoord[arrayPosition] = xCoordinatePtn[arrayPosition];
    
    // Go up one in array position and in array size to update the dynamic array.
    arrayPosition++;
    arraySize++;

    // Update the size of the dynamic array on the xCoordinatesPtn.
    delete[] xCoordinatePtn;
    xCoordinatePtn = new short[arraySize];
    // Transfer the values back to the new size array.
    for (int i = 0; i < arraySize; i++) {
        xCoordinatePtn[i] = transferXCoord[i];
    }
    // Then update to new size the transfer array.
    delete[] transferXCoord;
    transferXCoord = new short[arraySize];
    // Update the transfer to be full and not have only the lastest value
    for (int i = 0; i < arraySize; i++) {
        transferXCoord[i] = xCoordinatePtn[i];
    }
}

short Display::biggestLine()
{
    short size = 0;
    short temporary = 0;
    for (int i = 0; i < arraySize; i++) {
        if (xCoordinatePtn[i] != -1) {
        temporary += xCoordinatePtn[i];
        } else {
            if (temporary >= size) {
                size = temporary;
            }
            temporary = 0;
        }
    }
    return size;
}

void Display::plusY()
{
    yCoordinate++;
    plusX(-1);
}

void Display::encounterDisplay(string display, int y)
{
    setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, y);
    cout << display;
    setCursorPosition(0, getYCoordinate());
}

void Display::resetCoordinates()
{
    delete[] xCoordinatePtn;
    xCoordinatePtn = NULL;
    delete[] transferXCoord;
    transferXCoord = NULL;
    yCoordinate = 0;
    arrayPosition = 0;
    arraySize = 1;
    xCoordinatePtn = new short[arraySize];
    transferXCoord = new short[arraySize];
}

short Display::getYCoordinate()
{
    return yCoordinate;
}


