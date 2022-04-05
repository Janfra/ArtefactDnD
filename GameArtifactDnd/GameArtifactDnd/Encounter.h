#include <time.h>
#include "Enemy.h"
#include "Player.h"
#include "Object.h"
#include "Display.h"
using namespace std;

#pragma once
class Encounter
{
public:
 #pragma region Constructor & Destructor

	// CONSTRUCTOR //
	Encounter();

	// DESTRUCTOR //
	~Encounter();

#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //
	void setDifficulty(short setDiff);
	void setHealing(short setHeal);
	void setTrapDmg(short setTrapDmg);
	void setPlayer(Player* playerSet);

	// GETTERS //
	short getDifficulty();
	short getHealing();
	short getTrapDmg();

#pragma endregion

 #pragma region Encounter Functions
	// Initiate encounter functions //
	void enemyEncounter();
	void healingFountain();
	void foundItem();
	void trapEncounter();

	// Encounter Functions //
	bool questionYesOrNo(string question);

#pragma endregion

 #pragma region Fighting Functions

	void displayEnemyStats(Enemy* enemyStats);
	void attackEnemy(Enemy* enemyHP);

#pragma endregion

	// Public variables. encounterInProcess was gonna be used on game and display is used throughout the whole game.
	bool encounterInProcess;
	Display display;
private:
#pragma region Has-A/Pointers

	Player* playerPtn;
	Enemy* enemyPtn;

#pragma endregion

	short difficulty;
	short healing;
	short trapDmg;
};

