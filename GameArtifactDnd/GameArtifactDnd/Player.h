#pragma once
#include "Stats.h"
#include "Object.h"
#define TOTAL_LEVELS 10

class Player :
    public Stats
{
public:
    Player();
    ~Player();
    // Will make functions used exclusively by the player part of its class for now
    
    // Used to reply to questions made to the player, only accepts Yes/y, any other response is false. May change it in the future.
    bool questionYesOrNo(string response);

    // StatSheet will look different when the player is displaying his own statSheet so I am overwritten it here. If inspecting other beings, it will have less information
    string statSheet();

    short getEXP();
    short getLevel();
    short getNeededEXP();
    string displayLine(short a);

    void setEXP(short gainedEXP);
    void setLevel(short newLVL);

    // Player Has-A object
    Object * items;

protected:
    //Added a couple of player specific stats
    short EXP;
    // Made neededEXP an array to set the amounts of EXP required for each level to a total of 10 levels because we start off as 1, so TOTAL_LEVELS - 1 which works well with for loops.
    short neededEXP[TOTAL_LEVELS];
};

