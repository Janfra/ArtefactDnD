#pragma once
#include <string>
using namespace std;

// Will add the Objects Class as an object inside the Stats Class every time an object is picked up. 
// May end up doing a function that uses both of their respective values to add them together instead of putting one inside of the other... It will depend in if its possible to limit
// the total amount of objects
class Stats
{
    // Added them into separated types, before they were all public
public:
 #pragma region Constructor & Destructor

    Stats();
    // No destructor for this one?

#pragma endregion

 #pragma region Setters & Getters  
    // SETTERS //

    void setName(string newName);
    void setSTR(short newSTR);
    void setDEX(short newDEX);
    void setCON(short newCON);
    void setCHA(short newCHA);
    void setINT(short newINT);
    void setTotalHP(short newTotalHP);
    void setCurrentHP(short newCurrentHP);

    // GETTERS // 

    string getName();
    short getSTR();
    short getDEX();
    short getCON();
    short getCHA();
    short getINT();
    short getCurrentHP();
    short getTotalHP();
    short getPDMG();
    short getDODGE();

#pragma endregion

#pragma region Stats Functions

    string displayLine(short lineNumber);

    void heal(short healAmount);

#pragma endregion


 #pragma region Outdated

    string statSheet();

#pragma endregion


    // Made it protected so that it can be accessed by the classes that will inherit it. 
protected:
    string name;
    // Changed all values from int to short for efficiency

    // STR will be used to measure damage output and possibly for certain actions.
    short STR;
    // DEX will be used for DDG (dodge) and possibly movement.
    short DEX;
    // CON will be used for HP 
    short CON;
    // CHA could possibly be used for easter eggs AKA new dialogues
    short CHA;
    // INT will be used to identify objects? Still not sure. Don't think I'll add magic to a Goblin.
    short INT;

    short totalHP;
    short currentHP;
    // Using it to calculate total damage. May take it out.
    short PDMG;
    // Similar to AC in D&D
    short DODGE;
    // Level started of as a stat exclusively for the player but because I have to decided to automatize all stats using levels + other means to upgrade stats, I will make levels
    // a general stat, it will only work differently with the player. Other objects will have a set level and no limit to their level for whatever I come up with
    short level;
};

