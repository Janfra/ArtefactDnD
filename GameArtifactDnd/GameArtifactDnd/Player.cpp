#include "Player.h"

 #pragma region Constructor & Destructor

Player::Player()
{
    EXP = 0;
    for (int i = 0; i < TOTAL_LEVELS; i++) 
    {
        neededEXP[i] = ((10 * i) + 10);
    }
    level = 1;
    // Had to add this variable to the player constructor for it to display the right amount of HP at level 1. 
    currentHP = (totalHP + level + CON);

    items = new Object();
    items[0].setRange(1);
}

Player::~Player() 
{
    // Clears space in the heap and prevents hanging pointers //
    delete items;
    items = NULL;
}

#pragma endregion

 #pragma region Setters & Getters
    // SETTERS //
// Add experience to the player using 'gainedEXP' parameter. If the amount required is met, levels up, restoring health back to max.
void Player::setEXP(short gainedEXP)
{
    EXP += gainedEXP;

    if (EXP >= getNeededEXP()) 
    {
        if (currentHP -= getTotalHP() > 0) 
        {
            currentHP -= getTotalHP();
        }
        else 
        {
            currentHP = 0;
        }
        level++;
        setLevel(level);
        currentHP += getTotalHP();
    }
}

/* Used for testing purposes // Update: Decided to use it inside the "level up" situation in setEXP. 
Decided to do this to avoid going over the max lvl once you get to the max amount of required EXP to lvl up. */

// Sets the player level to 'newLVL' parameter. Clamps the level if it exceeds the maximum. 
void Player::setLevel(short newLVL)
{
    if (newLVL > TOTAL_LEVELS) 
    {
        level = TOTAL_LEVELS;
    }
    else 
    {
        level = newLVL;
    }
}

// Sets player name to 'newName' parameter. If the player's name exceeds the display lenght, change it. 
void Player::setName(string newName) 
{
    // Check to make sure that the name doesn't exceed the size of the display.
    if (newName.length() > 29)
    {
        newName = "Goblin with long name";
    }
    name = newName;
}

    // GETTERS //
// Return the player's current 'EXP'.
short Player::getEXP()
{
    return EXP;
}

// Return the player's current level.
short Player::getLevel()
{
    return level;
}

// Return required 'EXP' to level up.
short Player::getNeededEXP()
{
    // Local variable to be able to store the number of the array needed.
    int arrayNumber = 0;

    // The for loop runs until it gets the required number of the array and stores it inside the variable.
    for (int i = 0; i < level; i++) 
    {
        arrayNumber = i;
    }

    // Returns the exp stored in the space given by the for loop variable.
    return neededEXP[arrayNumber];
}

// Return amount of damage dealt by the player taken into consideration items.
short Player::getPDMG() {
    return (getSTR() + items->getDMG() + rand() % getDEX());
}

// Return player's 'DODGE'
short Player::getDODGE() {
    return (1 + (getDEX() / 2) + 0.5 + (items->getRange()));
}

#pragma endregion

 #pragma region Player Functions

/*  the displayLine function was created in order for me to properly align the displayInfo function. If the cout had more than 1 component all other couts needed the same amount of components
    to stay consistent and not affect the map display. In order to avoid having to constantly change couts, I decided to cut the statSheet into lines and into a single string. That way
    I only need to cout once for all lines and keep the alignment correctly. */


// Returns a string depending on the 'lineNumber' parameter given. 
string Player::displayLine(short lineNumber)
{
    if (lineNumber >= 9) 
    {
        lineNumber = 9;
    }
    else if (lineNumber < 0) 
    {
        lineNumber = 0;
    }
    string rv[10];

    // I had to write them manually but stats shouldn't be constantly changing so there should be no need to change it.
    rv[0] = "- " + name + " Stats";
    rv[1] = "- Level: " + to_string(getLevel());
    rv[2] = "- EXP: " + to_string(getEXP()) + " / " + to_string(getNeededEXP());
    rv[3] = "- HP: " + to_string(getCurrentHP()) + " / " + to_string(getTotalHP());
    rv[4] = "- STR: " + to_string(getSTR());
    rv[5] = "- DEX: " + to_string(getDEX());
    rv[6] = "- CON: " + to_string(getCON());
    rv[7] = "- CHA: " + to_string(getCHA());
    rv[8] = "- INT: " + to_string(getINT());
    rv[9] = "- DDG: " + to_string(getDODGE());

    return rv[lineNumber];
}

#pragma endregion

 #pragma region Attack Functions

#pragma endregion

 #pragma region Outdated
    
    // Updating the function to make it finish only when giving the right value. It needs to be fixed so that it deletes the last wrong cin.
    // bool questionYesorNo(string response) was taken into the Game class instead

    // Outdated statSheet that will probably not be used again. It was a helpful base to create the displayInfo function.
string Player::statSheet() {
    // To make it returnable with the short variables I transformed them into strings
    string rv;

    rv = "--------------------------------------------------------------------\n\n" +
        name + " Stats" +
        "\n\nLevel: " + to_string(level) +
        "\nEXP: " + to_string(getNeededEXP()) + " / " + to_string(getEXP()) +
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

    /// SETEXP OLD CODE ///
    //    for (int i = 0; i < TOTAL_LEVELS; i++) {
    //    if (EXP == neededEXP[i]) {
    //        level++;
    //        currentHP = getTotalHP();
    //    }
    // }
    // 
    // After going checking the code again, I realised the old for loop I had in the setEXP function would most likely run even if the player
    // only had the require EXP for level 2, so I changed it to run with the getNeededEXP function instead. Also, not equal, but equal or higher. //


#pragma endregion
