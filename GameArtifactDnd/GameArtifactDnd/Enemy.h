#pragma once
#include "Stats.h"
#include <time.h>
class Enemy :
    public Stats
{
public:
#pragma region Constructor & Destructor

    Enemy();
    Enemy(short difficulty);
    ~Enemy();

#pragma endregion

#pragma region Setters & Getters

    short getDropEXP();

#pragma endregion

#pragma region Enemy Functions



#pragma endregion

private:
    // Defines the amount of experience dropped once the enemy is defeated
    short dropEXP;
    // Defines if this enemy is the final boss
    bool finalBoss;
};

