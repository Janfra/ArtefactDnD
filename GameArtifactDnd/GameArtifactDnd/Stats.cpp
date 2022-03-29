#include "Stats.h"

 #pragma region Constructor & Destructor

Stats::Stats() {
    name = "Test";
    level = 0;
    STR = 3;
    DEX = 3;
    CON = 3;
    CHA = 3;
    INT = 3;

    totalHP = (10 + level + CON);

    currentHP = totalHP;

    // I need to test DMG output and see if I should make it into a stat the hitting %
    PDMG = 0 + STR;

    // Added 0.5 to try and make it so that it always rounds up. 
    // Will be shown in stats as 'DDG' to keep them all 3 letters long. Looks neat.
    DODGE = 1 + (DEX / 2) + 0.5;
}

#pragma endregion

 #pragma region Setters & Getters
// Had to add new setters and getters for the new protected variables. Made them here so that this functions are accesible to all childs. Didnt do some of the setters because they are 
// directly dependant to other components. 

// SETTERS // 
void Stats::setName(string newName)
{
    name = newName;
}

void Stats::setSTR(short newSTR)
{
    STR = newSTR;
}

void Stats::setDEX(short newDEX)
{
    DEX = newDEX;
}

void Stats::setCON(short newCON)
{
    CON = newCON;
}

void Stats::setCHA(short newCHA)
{
    CHA = newCHA;
}

void Stats::setINT(short newINT)
{
    INT = newINT;
}

void Stats::setTotalHP(short newTotalHP)
{
    totalHP = newTotalHP;
}

void Stats::setCurrentHP(short newCurrentHP)
{
    currentHP = newCurrentHP;
}

// GETTERS //

string Stats::getName()
{
    return name;
}

// Made it so that getters now also include the player level to their stats. There will be ways to directly change the stat. I will need to work in the future in the adding of items bonus
// to stats.

short Stats::getSTR()
{
    return (STR + level);
}

short Stats::getDEX()
{
    return (DEX + level);
}

short Stats::getCON()
{
    return (CON + level);
}

short Stats::getCHA()
{
    return (CHA + level);
}

short Stats::getINT()
{
    return (INT + level);
}

short Stats::getCurrentHP()
{
    return currentHP;
}

short Stats::getTotalHP()
{
    return (totalHP + level + CON);
}

short Stats::getPDMG()
{
    return PDMG;
}

short Stats::getDODGE()
{
    return (DODGE + level);
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