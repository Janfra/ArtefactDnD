// Includes for randomizing with srand
#include <time.h>
// Necessary to do the sleep function
#include <chrono>
#include <thread>
// Includes the headers of all the things necessary to run an encounter
#include "Enemy.h"
#include "Player.h"
#include "Object.h"
#include "Display.h"
// Saves using std:: on functions
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
	void setPlayer(Player* playerSet);

	void setWin(bool* winCondition);

	// GETTERS //
	short getDifficulty();
#pragma endregion

 #pragma region Encounter Functions
	// Initiate encounter functions //
	void enemyEncounter();
	void healingFountain();
	void foundItem();
	void trapEncounter();

	// Encounter Functions //
	bool questionYesOrNo(string question);

	void generateItem();

#pragma endregion

 #pragma region Fighting Functions

	void displayEnemyStats(Enemy* enemyStats);
	void attackEnemy(Enemy* enemyHP);

	void attackPlayer(Enemy* enemyAttack);

	void damagePlayer(short dmgDone);

#pragma endregion

 #pragma region Rolling Functions

	short rollD20();

#pragma endregion


	// Public variables. encounterInProcess was gonna be used on game and display is used throughout the whole game.
	bool encounterInProcess;
	Display display;
	bool* winPtn;
private:
#pragma region Has-A/Pointers

	Player* playerPtn;
	Enemy* enemyPtn;

#pragma endregion

	short difficulty;
};

