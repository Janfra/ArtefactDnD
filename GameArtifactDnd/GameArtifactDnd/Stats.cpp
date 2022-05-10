#include "Stats.h"

 #pragma region Constructor & Destructor

Stats::Stats() 
{
    // Initializes Variables //
    name = "Test";
    level = 0;
    STR = 3;
    DEX = 3;
    CON = 3;
    CHA = 3;
    INT = 3;

    totalHP = (10 + level + CON);

    currentHP = (totalHP + getCON());

    // I need to test DMG output and see if I should make it into a stat the hitting %
    PDMG = 0;

    // Added 0.5 to try and make it so that it always rounds up. 
    // Will be shown in stats as 'DDG' to keep them all 3 letters long. Looks neat.
    DODGE = 1 + (DEX / 2) + 0.5;
}

#pragma endregion

 #pragma region Setters & Getters
// Had to add new setters and getters for the new protected variables. Made them here so that this functions are accesible to all childs. Didnt do some of the setters because they are 
// directly dependant to other components. 

    // SETTERS // 
// Set the 'name' variable to 'newName' parameter.
void Stats::setName(string newName)
{
    name = newName;
}

// Set the 'STR' variable to 'newSTR' parameter.
void Stats::setSTR(short newSTR)
{
    STR = newSTR;
}

// Set the 'DEX' variable to 'newDEX' parameter.
void Stats::setDEX(short newDEX)
{
    DEX = newDEX;
}

// Set the 'CON' variable to 'newCON' parameter.
void Stats::setCON(short newCON)
{
    CON = newCON;
}

// Set the 'CHA' variable to 'newCHA' parameter.
void Stats::setCHA(short newCHA)
{
    CHA = newCHA;
}

// Set the 'INT' variable to 'newINT' parameter.
void Stats::setINT(short newINT)
{
    INT = newINT;
}

// Set the 'totalHP' variable to 'newTotalHP' parameter.
void Stats::setTotalHP(short newTotalHP)
{
    totalHP = newTotalHP;
}

// Set the 'currentHP' variable to 'newCurrentHP' parameter.
void Stats::setCurrentHP(short newCurrentHP)
{
    currentHP = newCurrentHP;
}

    // GETTERS //
// Returns the name of character.
string Stats::getName()
{
    return name;
}

// Made it so that getters now also include the player level to their stats. There will be ways to directly change the stat. I will need to work in the future in the adding of items bonus
// to stats.

// Returns the 'STR' of character.
short Stats::getSTR()
{
    return (STR + level);
}

// Returns the 'DEX' of character.
short Stats::getDEX()
{
    return (DEX + level);
}

// Returns the 'CON' of character.
short Stats::getCON()
{
    return (CON + level);
}

// Returns the 'CHA' of character.
short Stats::getCHA()
{
    return (CHA + level);
}

// Returns the 'INT' of character.
short Stats::getINT()
{
    return (INT + level);
}

// Returns the 'currentHP' of character.
short Stats::getCurrentHP()
{
    return currentHP;
}

// Returns the 'totalHP' of character.
short Stats::getTotalHP()
{
    return (totalHP + getCON());
}

// Returns the damage done by the character.
short Stats::getPDMG()
{
    return (PDMG + getSTR());
}

// Returns the 'DODGE' of character.
short Stats::getDODGE()
{
    return (1 + (getDEX() / 2) + 0.5);
}

#pragma endregion

 #pragma region Stats Functions

// Returns a string depending on the 'lineNumber' parameter given. 
string Stats::displayLine(short lineNumber)
{
    if (lineNumber >= 4) {
        lineNumber = 3;
    }
    else if (lineNumber < 0) {
        lineNumber = 0;
    }
    string rv[4];

    // I had to write them manually but stats shouldn't be constantly changing so there should be no need to change it.
    rv[0] = "- " + name + " Stats";
    rv[1] = "- HP: " + to_string(getCurrentHP()) + " / " + to_string(getTotalHP());
    rv[2] = "- DMG: " + to_string(getSTR());
    rv[3] = "- DDG: " + to_string(getDODGE());

    return rv[lineNumber];
}

// Heals character by 'healAmount' parameter
void Stats::heal(short healAmount) {
    currentHP += healAmount;
}

#pragma endregion

 #pragma region Outdated

// Changed old statSheet to a version that doesn't need to put inside the parameter the class but runs directly with the object.
// Old parameter: string statSheet(Player textStats), it would run it instead with for example: "\nCHA: " + to_string(textStats.Stats.CHA)#

// Displays stats sheet
string Stats::statSheet() {
    // To make it returnable with the short variables I transformed them into strings
    string rv;

    rv = "--------------------------------------------------------------------\n\n" +
        name + " Stats" +
        "\n\nLevel: " + to_string(level) +
        "\n\nHP: " + to_string(getTotalHP()) + " / " + to_string(getCurrentHP()) +
        "\n\nSTR: " + to_string(getSTR()) +
        "\nDEX: " + to_string(getDEX()) +
        "\nCON: " + to_string(getCON()) +
        "\nCHA: " + to_string(getCHA()) +
        "\nINT: " + to_string(getINT()) +
        "\nDDG: " + to_string(getDODGE()) +
        "\n\n--------------------------------------------------------------------\n\n";

    return rv;
}

#pragma endregion