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

    short getDifficulty(short difficulty);
    short getDropEXP();

#pragma endregion

#pragma region Enemy Functions



#pragma endregion

private:
    short dropEXP;
    bool finalBoss;
};

