#include "Encounter.h"
 #pragma region Constructor & Destructor

Encounter::Encounter()
{
	// Initilizing Variables // 
	difficulty = 0;
	playerPtn = NULL;
	enemyPtn = NULL;
	winPtn = NULL;
	encounterInProcess = false;
	next = "";
}

Encounter::~Encounter()
{
	// Clears space in the heap and prevents hanging pointers //
	playerPtn = NULL;

	delete enemyPtn;
	playerPtn = NULL;

	delete winPtn;
	winPtn = NULL;
}

#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //
// Changes the game difficulty.
void Encounter::setDifficulty(short setDiff)
{
	if (setDiff < 0) 
	{
		setDiff = 0;
	}
	difficulty = setDiff;
}

// Sets the player pointer to be able to access it during encounters. 
void Encounter::setPlayer(Player* playerSet)
{
	playerPtn = playerSet;
}

// Sets the win pointer to be able to terminate the game loop. 
void Encounter::setWin(bool* winSet) {
	winPtn = winSet;
}

	// GETTERS //
// Returns the current game difficulty.
short Encounter::getDifficulty()
{
	return difficulty;
}

#pragma endregion

 #pragma region Encounter Functions
// Starts the enemy encounter, initiating a fight. 
void Encounter::enemyEncounter()
{
	// If there is already an enemy, then don't generate a new one
	if (enemyPtn == NULL) 
	{
		display.encounterDescription(1);
		enemyPtn = new Enemy(difficulty);
		encounterInProcess = true;
	}
	// Display enemy stats in information section
	displayEnemyStats(enemyPtn);

	// Initiate the encounter/fight loop 
	while (encounterInProcess == true) 
	{
		// Need to change the question function, it doesnt take all the inputs for battle.
		if (questionYesOrNo("Attack Enemy?") == true) 
		{
			attackEnemy(enemyPtn);
			displayEnemyStats(enemyPtn);
			display.minusY();
		}

		// When enemy runs out of HP, finish encounter, update enemy display name, augment the difficulty and cout the EXP dropped.
		if (enemyPtn->getCurrentHP() <= 0) 
		{
			encounterInProcess = false;
			display.encounterDisplay("- Enemy Dead!", 2);
			difficulty++;
			display.setCursorBottom();
			display.Color(3);
			cout << "Dropped " << enemyPtn->getDropEXP() << " EXP!" << endl;
			display.Color(7);
			playerPtn->setEXP(enemyPtn->getDropEXP());
		}
		// Else enemy attacks the player
		else 
		{
			cin >> next;
			attackPlayer(enemyPtn);
		}
	}

	// When the encounter finish, clear enemy space in the heap and clear the pointer to not have a hanging pointer.
	delete enemyPtn;
	enemyPtn = NULL;
}

// Starts healing fountain encounter.
void Encounter::healingFountain()
{
	// Display the encounter information/description and initiate encounter 
	display.encounterDescription(2);
	displayEncounterInfo();
	encounterInProcess = true;

	if (questionYesOrNo("Want to use the fountain to heal?") == true) 
	{
		// Local variable to store rollD20 result to run an if check
		short roll = rollD20();
		// Local variable to set amount of healing
		short healAmount = (rand() % (difficulty + 1) + 1 * 4);
		// Update encounter information
		displayEncounterInfo(10, healAmount);

		cout << "You need a 10..." << endl;
		cin >> next;
		// In success heal player and cout their roll and amount healed
		if (roll >= 10) 
		{
			playerPtn->heal(healAmount);
			cout << "Rolled:" << roll << endl;
			cin >> next;
			cout << "Healed for " << healAmount << "!" << endl;
		}
		// Else cout roll and failure message.
		else 
		{
			cout << "Rolled: " << roll << endl;
			cin >> next;
			cout << "Something went wrong!! There is no healing." << endl;
		}
	}
	encounterInProcess = false;
}

// Starts a found item encounter.
void Encounter::foundItem()
{
	display.encounterDescription(3);
	generateItem();
	display.clearEncounter();
}

// Starts a trap encounter.
void Encounter::trapEncounter()
{
	display.encounterDescription(4);

	// Declare local variables
	short trapDodge = (rand() % 10) + 1;
	short trapDMG = (rand() % 4) + difficulty;
	short roll = rollD20();
	//
	displayEncounterInfo(trapDodge, trapDMG);
	
	cout << "Try to dodge!" << endl << "Throw a D20, you need at least : " << trapDodge << endl;
	cin >> next;
	cout << endl << "Rolled: " << roll << endl;
	cin >> next;
	if (roll >= trapDodge) 
	{
		cout << "Dodged!" << endl;
	}
	else 
	{
		cout << "You failed to dodge! You take: " << trapDMG << " of damage." << endl;
		damagePlayer(trapDMG);
	}
}

// Uses 'question' parameter to display a question and get the player input on it. Returns a bool.
bool Encounter::questionYesOrNo(string question) 
{
	// Declare local variable to run an if and return a value
	bool rv = NULL;
	// Declare local variable to store the player answer
	string answer;

	display.plusY();
	cout << question << endl;

	// Until the player gives a valid answer, ask the question.
	while (rv == NULL) 
	{
		cin >> answer;
		if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y") 
		{
			rv = true;
			return rv;
		}
		else if (answer == "No" || answer == "no" || answer == "n" || answer == "N") 
		{
			rv = false;
			return rv;
		}
		else 
		{
			cout << endl << "Invalid response! It has to be 'Yes' or 'No'!" << endl;
			system("Pause");
		}

		// Clear encounter to avoid flooding with the question
		display.clearEncounter();
	}
	return rv;
}

// Generate an item that can be taken or ignored. Could be used in any encounters as an addition.
void Encounter::generateItem() 
{
	Object* itemFound = new Object(difficulty);
	display.Color(9);
	itemFound->displayInfo();
	display.Color(15);
	if (questionYesOrNo("Want to pick up this item?") == true) 
	{
		delete playerPtn->items;
		playerPtn->items = itemFound;
	}
	else {
		delete itemFound;
	}
}

// Display the encounter information. This default version has no parameters as it is before the player commits and its still unknown. 
void Encounter::displayEncounterInfo()
{
	display.clearEncounterDisplay(false);

	display.encounterDisplay("Roll Required: ???", 3);
	display.encounterDisplay("You will receive: ???", 6);
}

// Display the encounter information. Parameter 'a' defines the amount required to get a good result, 'b' defines what the player will receive, be it damage or healing.
void Encounter::displayEncounterInfo(short a, short b) 
{
	display.clearEncounterDisplay(false);

	display.encounterDisplay("Roll Required: " + to_string(a), 3);
	display.encounterDisplay("You will receive: " + to_string(b), 6);
}

#pragma endregion

 #pragma region Fighting Functions

// Display the enemy stats, 'enemyStats' parameter defines which enemy stats are shown.
void Encounter::displayEnemyStats(Enemy* enemyStats) 
{
	display.clearEncounterDisplay(false);
	// Display the enemy information
	display.encounterDisplay(enemyStats->displayLine(0), 2, 4);
	display.encounterDisplay(enemyStats->displayLine(1), 4, 2);
	display.encounterDisplay(enemyStats->displayLine(2), 6);
	display.encounterDisplay(enemyStats->displayLine(3), 7);
}

// Attempts to deal damage to the enemy given with the 'enemyHP' parameter.
void Encounter::attackEnemy(Enemy* enemyHP)
{
	display.clearEncounter();
	// Declare local variable to store the amount of damage done to the enemy. 
	short dmgTaken = playerPtn->getPDMG();

	// Check that the roll go over their dodge
	if (rollD20() + playerPtn->getSTR() >= enemyHP->getDODGE()) 
	{
	enemyHP->setCurrentHP(enemyHP->getCurrentHP() - dmgTaken);
		// If the player is not dead display the amount of damage dealt on the console.
		if (enemyHP->getCurrentHP() > 0) 
		{
		display.setCursorBottom();
		cout << endl << "Enemy Hit for " << dmgTaken << "!!" << endl;
		}
	} 
	else 
	{
		display.setCursorBottom();
		cout << "Enemy dodged!" << endl;
	}

}

// Attempts to deal damage to the player. The 'enemyAttack' parameter defines which enemy is attacking.
void Encounter::attackPlayer(Enemy* enemyAttack) 
{
	// Declare local variable to store the amount of damage done to the player. 
	short dmgTaken = (enemyAttack->getSTR() + rand() % enemyPtn->getDEX());
	display.clearEncounter();
	// Check that the roll go over their dodge
	if (rollD20() + enemyPtn->getSTR() >= playerPtn->getDODGE()) 
	{
		damagePlayer(dmgTaken);
		display.setCursorBottom();
		cout << "Enemy dealt you " << dmgTaken << "!!" << endl;
	}
	else 
	{
		display.setCursorBottom();
		cout << "Dodge!!" << endl;
	}
	if (playerPtn->getCurrentHP() <= 0) 
	{
		display.setCursorBottom();
		cout << endl << "Died" << endl << endl;
		encounterInProcess = false;
	}
}

// Deals damage to the player. 'dmgDone' parameter defines how much damage is dealt to the player.
void Encounter::damagePlayer(short dmgDone) 
{
	playerPtn->setCurrentHP(playerPtn->getCurrentHP() - dmgDone);
	display.playerHPDisplay(playerPtn->displayLine(3));
	// Checks for playing dying to finish game loop
	if (playerPtn->getCurrentHP() < 0) 
	{
		encounterInProcess = false;
		winPtn[0] = true;
	}
}

#pragma endregion

 #pragma region Rolling functions

// Randomly generates a number from 1 to 20.
short Encounter::rollD20()
{
	return ((rand() % 20) + 1);
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

