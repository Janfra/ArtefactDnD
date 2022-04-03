#include "Encounter.h"
 #pragma region Constructor & Destructor

Encounter::Encounter()
{
	difficulty = 1;
	healing = 1;
	trapDmg = 1;
	playerPtn = NULL;
	enemyPtn = NULL;
	encounterInProcess = false;
}

Encounter::~Encounter()
{
	delete playerPtn;
	playerPtn = NULL;

	delete[] enemyPtn;
	playerPtn = NULL;
}

#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //
void Encounter::setDifficulty(short setDiff)
{
}

void Encounter::setHealing(short setHeal)
{
}

void Encounter::setTrapDmg(short setTrapDmg)
{
}

void Encounter::setPlayer(Player* playerSet)
{
	playerPtn = &playerSet;
}

	// GETTERS //
short Encounter::getDifficulty()
{
	return difficulty;
}

short Encounter::getHealing()
{
	return healing;
}

short Encounter::getTrapDmg()
{
	return trapDmg;
}

#pragma endregion

 #pragma region Encounter Functions
// This function will be called when in a room with an enemy to start a battle.
void Encounter::enemyEncounter()
{
	Enemy* enemy1 = new Enemy();
	cout << "Enemy encountered!" << endl;
	encounterInProcess = true;

	system("PAUSE");

	// When the encounter finish, get rid of the enemy in the heap and clear the pointer to not have a hanging pointer.
	delete enemy1;
	enemy1 = NULL;
	if (questionYesOrNo("Finish Encounter?") == true) {
	encounterInProcess = false;
	}
}
// This function will be called when in a room a healing fountain is found.
void Encounter::healingFountain()
{
	cout << "Healing fountain found!";
}
// This function will be called when an item is found.
void Encounter::foundItem()
{
	cout << "Item found!";
}
// This function will be called when a trap room is entered.
void Encounter::trap()
{
	cout << "Trap!!";
}

bool Encounter::questionYesOrNo(string question) {
	bool rv = NULL;
	string answer;

	cout << endl << question << endl;

	while (rv == NULL) {
		cin >> answer;
		if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y") {
			rv = true;
			return rv;
		}
		else if (answer == "No" || answer == "no" || answer == "n" || answer == "N") {
			rv = false;
			return rv;
		}
		else {
			cout << endl << "Invalid response! It has to be 'Yes' or 'No'!" << endl << question << endl;
			system("Pause");
		}
	}
	return rv;
}

#pragma endregion

#pragma region Fighting Functions

void Encounter::attackEnemy(Enemy* enemyHP)
{
	enemyHP->setCurrentHP((enemyHP->getCurrentHP()) - (playerPtn[0]->getSTR()));
}

#pragma endregion


 #pragma region Outdated

//enemy encounter
/// Giving me errors ///
//if (questionYesOrNo("Attack Enemy?") == true) {
//attackEnemy(enemy1);
//cout << enemy1->getCurrentHP();
//system("Pause");
//}

#pragma endregion

