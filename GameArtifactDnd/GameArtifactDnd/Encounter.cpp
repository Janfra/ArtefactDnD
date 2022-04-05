#include "Encounter.h"
 #pragma region Constructor & Destructor

Encounter::Encounter()
{
	difficulty = 0;
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
	playerPtn = playerSet;
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
	// If there is already an enemy, then don't generate a new one
	if (enemyPtn == NULL) {
	enemyPtn = new Enemy(difficulty);
	encounterInProcess = true;
	}
	
	// Announce the encounter and display the enemy stats
	display.encounterAnnouncement("Enemy Encountered!");
	displayEnemyStats(enemyPtn);

	// Initiate the encounter loop 
	while (encounterInProcess == true) {
		// Need to change the question function, it doesnt take all the inputs for battle.
	if (questionYesOrNo("Attack Enemy?") == true) {
		attackEnemy(enemyPtn);
		displayEnemyStats(enemyPtn);
	}
	

	// When enemy runs out of HP, finish encounter
	if (enemyPtn->getCurrentHP() <= 0) {
		encounterInProcess = false;
		display.encounterDisplay("- Enemy Dead!", 2);
		difficulty++;
		display.setCursorBottom();
		display.Color(3);
		cout << "Dropped " << enemyPtn->getDropEXP() << " EXP!" << endl;
		display.Color(7);
		playerPtn->setEXP(enemyPtn->getDropEXP());
	}
	}

	// When the encounter finish, get rid of the enemy in the heap and clear the pointer to not have a hanging pointer.
	delete enemyPtn;
	enemyPtn = NULL;
}

// This function will be called when in a room a healing fountain is found.
void Encounter::healingFountain()
{
	display.encounterAnnouncement("Healing fountain found!");
	encounterInProcess = true;
	if (questionYesOrNo("Want to use the fountain to heal?") == true) {
		short healAmount = (rand() % (difficulty + 1) * 4);
		playerPtn->heal(healAmount);
		if (healAmount != 0) {
		cout << "Healed for " << healAmount << "!" << endl;
		}
		else {
			cout << "Something went wrong!! There is no healing." << endl;
		}
	}
	encounterInProcess = false;
}

// This function will be called when an item is found.
void Encounter::foundItem()
{
	display.encounterAnnouncement("Item found!");
}

// This function will be called when a trap room is entered.
void Encounter::trapEncounter()
{
	display.encounterAnnouncement("Trap!!");
}

// This function is used to ask the player a question and return a bool based on it
bool Encounter::questionYesOrNo(string question) {
	// Declare a local variable to run an if and return a value
	bool rv = NULL;
	// Declare another one to store the player answer
	string answer;

	cout << question << endl << endl;

	// Until the player gives a valid answer, ask the question.
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
			cout << endl << "Invalid response! It has to be 'Yes' or 'No'!" << endl;
			system("Pause");
		}
		// Clear the console after the infoDisplay() line
		display.clearEncounter();
	}
	return rv;
}

#pragma endregion

 #pragma region Fighting Functions

// Function to display the enemy stats, its only parameter is to assign which enemy stats it is showing.
void Encounter::displayEnemyStats(Enemy* enemyStats) {
	// Clear the section designed to display the encounter information inside infoDisplay()
	display.clearEncounterDisplay();
	// Display the enemy information
	display.encounterDisplay(enemyStats->displayLine(0), 2, 4);
	display.encounterDisplay(enemyStats->displayLine(1), 4, 2);
	display.encounterDisplay(enemyStats->displayLine(2), 6);
	display.encounterDisplay(enemyStats->displayLine(3), 7);
}

// Function to damage the enemy
void Encounter::attackEnemy(Enemy* enemyHP)
{
	// Clear the console in case there was anything being displayed before
	display.clearEncounter();
	// Declare a local variable to store the amount of damage done to the enemy. This was added at first to do testing. Now I am keeping it for adding obj damage and possibly RNG.
	short dmgTaken = (playerPtn->getSTR() + rand() % playerPtn->getDEX());
	// Set the enemy HP to the new amount.
	enemyHP->setCurrentHP(enemyHP->getCurrentHP() - dmgTaken);
	// If the player is not dead display the amount of damage dealt on the console. This needs to be changed so that 'dmgTaken' just have the amount of damage that will be dealt and use that.
	if (enemyHP->getCurrentHP() > 0) {
	display.setCursorBottom();
	cout << endl <<"Enemy Hit for " << dmgTaken << "!!" << endl;
	}
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

