#include "Display.h"

 #pragma region Constructor & Destructor

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

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS //
void Display::setCursorPosition(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, SHORT(y) };
    SetConsoleCursorPosition(hOut, coord);
}

void Display::setCursorBottom() {
    setCursorPosition(0, getYCoordinate());
}

    // GETTERS //
void Display::getCurrentPosition()
{

}

short Display::getYCoordinate()
{
    return yCoordinate;
}

#pragma endregion

 #pragma region Display Functions
    // CLEAR FUNCTIONS //
// Clear everything after the infoDisplay()
void Display::clearEncounter()
{
    setCursorPosition(0, (y_Size + 1));
    for (int i = (y_Size); i < (y_Size + 11); i++) {
        for (int x = 0; x < 200; x++) {
            setCursorPosition(x, i);
            cout << " ";
        }
    }
    setCursorPosition(0, (y_Size + 1));
}

// Clear everything after the infoDisplay() plus 'y'
void Display::clearEncounter(int y)
{
    setCursorPosition(0, (y_Size + 1 + y));
    for (int i = (y_Size); i < (y_Size + 11); i++) {
        for (int x = 0; x < 200; x++) {
            setCursorPosition(x, i);
            cout << " ";
        }
    }
    // Set cursor to the line after display that was just cleared.
    setCursorPosition(0, (y_Size));
}

// Clear the whole console
void Display::clearConsole()
{
    for (int y = 0; y < 40 + 5; y++) {
        for (int x = 0; x < 200; x++) {
            setCursorPosition(x, y);
            cout << "   ";
        }
    }
    resetCoordinates();
}

// Clear the section in infoDisplay() dedicated to the encounter. *Doesn't include the description title and division line
void Display::clearEncounterDisplay(bool clearDescription) {
    for (int i = 1; i < y_Size; i++) {
        for (int x = ENCOUNTER_COORDINATE_DISPLAY; x < (ENCOUNTER_COORDINATE_DISPLAY + 35); x++) {
            // Don't delete the separating line for description and title
            if (i != 9 && i != 10 && clearDescription == true) {
            setCursorPosition(x, i);
            cout << " ";
            }
            else if(i < 9) {
                setCursorPosition(x, i);
                cout << " ";
            }
        }
    }
    setCursorBottom();
}

// Resets all the variables in display, used when the whole screen is reprinted 
void Display::resetCoordinates()
{
    clearEncounter();
    delete[] xCoordinatePtn;
    xCoordinatePtn = NULL;
    delete[] transferXCoord;
    transferXCoord = NULL;
    yCoordinate = 0;
    arrayPosition = 0;
    arraySize = 1;
    xCoordinatePtn = new short[arraySize];
    transferXCoord = new short[arraySize];
    setCursorBottom();
}

    // COORDINATE FUNCTIONS //
// Save X coordinate to calculate how many coordinates must be overwriten 
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
        if (i == arraySize - 1) {
            xCoordinatePtn[i] = 0;
        }
    }
    // Then update to new size the transfer array.
    delete[] transferXCoord;
    transferXCoord = new short[arraySize];
    // Update the transfer to be full and not have only the lastest value
    for (int i = 0; i < arraySize; i++) {
        transferXCoord[i] = xCoordinatePtn[i];
    }
}

// Display moves one line down, save the change of line in the 'xCoordinates'
void Display::plusY()
{
    yCoordinate++;
    plusX(-1);
}
    // ENCOUNTER DISPLAY FUNCTIONS //
// Display the given string in the infoDisplay() section dedicated to encounters, the 'y' parameter sets in which line. 
void Display::encounterDisplay(string display, int y)
{
    // Clamp 'y' to not go outside the infoDisplay()
    if (y <= 1) {
        y = 1;
    }
    else if (y >= y_Size) {
        y = y_Size - 1;
    }
    setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, y);
    cout << display;
    setCursorBottom();
}

// Same as before but giving a colour to the displayed string 
void Display::encounterDisplay(string display, int y, char colour)
{
    setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, y);
    Color(colour);
    cout << display;
    Color(15);
    setCursorBottom();
}

// This will add a random description to the encounter, thats why I gave it an 'encounterNumber' parameter, that way I can define if its a trap, or an enemy encounter. For now is 1 to 4.
void Display::encounterDescription(short encounterNumber) {
    // When a new description is generated, clear the display to write the new one.
    clearEncounterDisplay(true);
    // local variable that sets the y coordinates to the start line of the description. Which is 11.
    short descriptionY = 11;
    string description;
    short randomDescription = rand() % 3;
    switch (encounterNumber)
    {
    case 1:
        encounterAnnouncement("Enemy Encountered!");
        setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, descriptionY);
        if (randomDescription == 0) {
            description = "As you enter the room you find a -ninja turtle that for some reason is trying to kill you... --No time to figure out why!!";
            descriptionText(description, '-', descriptionY);
        }
            else if (randomDescription == 1) {
            description = "As you enter the room you find a-flying tulipan that for some -reason is trying to kill you... --No time to figure out why!!";
            descriptionText(description, '-', descriptionY);
            }
                else {
                    description = "As you enter the room you find a -giant baby that for some reason istrying to kill you... --No time to figure out why!!";
                    descriptionText(description, '-', descriptionY);
                }
        break;
    case 2:
        encounterAnnouncement("Healing fountain found!");
        setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, descriptionY);
        if (randomDescription == 0) { 
            description = "You found a glowing fountain!! --It gives you the feeling that it -will heal you if you drink from it";
            descriptionText(description, '-', descriptionY);
        }
            else if (randomDescription == 1) {
                description = "You found a fountain but the watercoming out of it looks murky -and disgusting... --You feel like you shoulnd't drink from it...";
                descriptionText(description, '-', descriptionY);
            }
                else {
                    description = "You found a fountain. --Looks pretty normal";
                    descriptionText(description, '-', descriptionY);
                }
        break;
    case 3:
        encounterAnnouncement("Item found!");
        setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, descriptionY);
        if (randomDescription == 0) {
            description = "As you are walking through the -next room you realise that there -is an item stuck on the wall. --You decide to go and have a closerlook.";
            descriptionText(description, '-', descriptionY);
        }
            else if (randomDescription == 1) {
            description = "You were walking without paying -attention when you almost fell. -Confused you thank God that it -wasn't a trap, but you still don'tknow what made you trip -for a second. -You turned around to check and... -Is an item... --Why would someone drop an item andleave? It better be bad...";
            descriptionText(description, '-', descriptionY);
            }
                else {
            description = "You come into the room and you seea pedastal.--You just hope you dont have to -pull anything by force, -because you definitely are going to check that item.";
            descriptionText(description, '-', descriptionY);
                }
        break;
    case 4:
        encounterAnnouncement("Trap!");
        setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, descriptionY);
        if (randomDescription == 0) {
            description = "Went lazy";
            descriptionText(description, '-', descriptionY);
        }
            else if (randomDescription == 1) {
            description = "Still lazy";
            descriptionText(description, '-', descriptionY);
            }
                else {
            description = "... Yeah, still";
            descriptionText(description, '-', descriptionY);
                }
        break;
    default:
        break;
    }
    setCursorBottom();
}

void Display::descriptionNextLine(short& descriptionY) {
    descriptionY++;
    setCursorPosition(ENCOUNTER_COORDINATE_DISPLAY, descriptionY);
}

void Display::descriptionText(string str, char del, short& descriptionY) {
    // declaring temp string to store the curr "word" upto del
      string temp = "";
      short charactersSoFar = 1;
   
      for(int i = 0; i <(int)str.size(); i++){
        // If cur char is not del, then append it to the cur "word", otherwise
          // you have completed the word, print it, and start a new word.
          if (str[i] != del && charactersSoFar % 34 != 0) {
              temp += str[i];
              charactersSoFar++;
          }
          else {
              if (str[i] != del) {
                  temp += str[i];
                  charactersSoFar++;
              }
              else {
                  charactersSoFar = 1;
              }
              cout << temp; descriptionNextLine(descriptionY);
              temp = "";
          }
      }

      // Couts the last line
      cout << temp;
}

// Display at the announcement section which encounter is currently happening
void Display::encounterAnnouncement(string display) {
    setCursorPosition(0, (y_Size - 2));
    cout << display;
}

    // PLAYER FUNCTIONS //
void Display::playerHPDisplay(string update) {
    setCursorPosition(0, 7);
    cout << "                            ";
    setCursorPosition(0, 7);
    Color(2);
    cout << update;
    Color(15);
    setCursorBottom();
}

    // COLOUR DISPLAY FUNCTION // 
// Changes the text display colour
void Display::Color(char typeColor)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //Prints color to the console. This functions makes it easier to use
    SetConsoleTextAttribute(color, typeColor);
}

#pragma endregion

 #pragma region Outdated

// Outdated
short Display::biggestLine()
{
    short size = 0;
    short temporary = 0;
    for (int i = 0; i < arraySize; i++) {
        if (xCoordinatePtn[i] != -1) {
            temporary += xCoordinatePtn[i];
        }
        else {
            if (temporary >= size) {
                size = temporary;
            }
            temporary = 0;
        }
    }
    return size;
}


#pragma endregion
