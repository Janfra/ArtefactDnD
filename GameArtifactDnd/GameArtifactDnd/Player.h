#pragma once
#include "Stats.h"
#include "Object.h"
#include <iostream>

// Max possible level. 
#define TOTAL_LEVELS 10

class Player :
    public Stats
{
public:
 #pragma region Constructor & Destructor

    Player();
    ~Player();

#pragma endregion
    
 #pragma region Setters & Getters
    // SETTERS //

    short getEXP();
    short getLevel();
    short getNeededEXP();

    short getPDMG();

    short getDODGE();

    // GETTERS //

    void setEXP(short gainedEXP);
    void setLevel(short newLVL);
    void setName(string setName);

#pragma endregion

 #pragma region Player-Functions

    string displayLine(short lineNumber);

#pragma endregion

 #pragma region Attack Functions

#pragma endregion

 #pragma region Has-A Classes/Pointers
    // Player Has-A object
    Object* items;

#pragma endregion

 #pragma region Outdated
    // Used to reply to questions made to the player, only accepts Yes/y, any other response is false. May change it in the future. Update: Took it to the Game functions

    // StatSheet will look different when the player is displaying his own statSheet so I am overwritten it here. If inspecting other beings, it will have less information
    string statSheet();
#pragma endregion

protected:
    // Experience of the player. Needed to level up.
    short EXP;
    
    // Made neededEXP an array to set the amounts of EXP required for each level to a total of 10 levels because we start off as 1, so TOTAL_LEVELS - 1 which works well with for loops.

    // Required 'EXP' to level up per level.
    short neededEXP[TOTAL_LEVELS];
};

