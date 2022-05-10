#include "Enemy.h"

#pragma region Constructor & Destructor
	// CONSTRUCTOR //
Enemy::Enemy()
{
	// Generate a random seed to get a random number generator
	srand(time(NULL));
	// Initilize Variables //
	dropEXP = level + (rand() % ((level + 1) * 3) + 1);
	finalBoss = false;
}

// Overloaded constructor to randomly generate an enemy using the 'difficulty' parameter to define how high is their stats as a minimum.
Enemy::Enemy(short difficulty)
{
	level += difficulty;
	srand(time(NULL));
	dropEXP = level + (rand() % ((level + 3) + 1 * 3) + 1);
	finalBoss = false;
	name = to_string(difficulty);
	// After changing the level value I need to set the stats again so that it updates the change
	totalHP = (10 + getCON() + (rand() % (level + 1)));
	currentHP = (totalHP + getCON());
}

	// DESTRUCTOR //
Enemy::~Enemy()
{
}

#pragma endregion

#pragma region Setters & Getters

// Returns the amount of experience dropped by the enemy
short Enemy::getDropEXP()
{
	return dropEXP;
}


#pragma endregion

#pragma region Enemy Functions



#pragma endregion

