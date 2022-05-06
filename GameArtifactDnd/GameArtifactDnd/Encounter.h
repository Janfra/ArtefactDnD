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
	void displayEncounterInfo();
	void displayEncounterInfo(short a, short b);




#pragma endregion

 #pragma region Fighting Functions
	// Enemy Functions //
	void displayEnemyStats(Enemy* enemyStats);
	void attackEnemy(Enemy* enemyHP);

	// Player Functions //
	void attackPlayer(Enemy* enemyAttack);
	void damagePlayer(short dmgDone);

#pragma endregion

 #pragma region Rolling Functions

	short rollD20();

#pragma endregion


	// Public variables. 'encounterInProcess' is used on game and display and 'winPtn' is used throughout the whole game.
	bool encounterInProcess;
	Display display;
	bool* winPtn;
private:
#pragma region Has-A/Pointers

	// Pointers to access the players and enemy information //
	Player* playerPtn;
	Enemy* enemyPtn;

#pragma endregion

	// Sets the game difficulty //
	short difficulty;
	// String to add a small pause before next output
	string next;
};

