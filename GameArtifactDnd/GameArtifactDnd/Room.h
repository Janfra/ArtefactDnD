// Includes for randomizing with srand
#include <iostream>
#include <time.h>
#include "Encounter.h"
// Defines set the size of the rooms
#define Height_SIZE 4
#define Width_SIZE 4
// Define set the total amount of types for rooms.
#define TOTAL_TYPES 5
// Total types: 5 multiplied by top, left and right 3
#define TOTAL_WALLS (TOTAL_TYPES * 3) 
// Not having to use std::
using namespace std;

#pragma once
class Room
{
public:
	// Functions explained in cpp file.
 #pragma region Constructor & Destructor

	Room();

	Room(int numberType);

	~Room();

#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //
	string setType(int typeNumber);

	// GETTERS //
	string getType(int typeNumber);
	string getRoom(int x, int y);

#pragma endregion

 #pragma region Room Functions

	void roomWallsCheck(string *giveWalls);
	void wallsStoring(int roomType);

#pragma endregion

 #pragma region Outdated

#pragma endregion

	// Testing
	string roomWalls[TOTAL_WALLS];
	Encounter* encounters;
protected:
	// Define the type of room, it will change the middle icon when discovered
	string type[TOTAL_TYPES];
	short roomType;

	// Creates the room visually, they will be squares. It is 5x4 to leave room for the room connectors (halls?)
	string room[Width_SIZE][Height_SIZE];
};

