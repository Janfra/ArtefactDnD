#include <iostream>
#include <string>
#include <time.h>
#define Height_SIZE 4
#define Width_SIZE 4
#define TOTAL_TYPES 5
// Total types: 5 multiplied by top left and right 3
#define TOTAL_WALLS (TOTAL_TYPES * 3) 

using namespace std;

#pragma once
class Room
{
public:
 #pragma region Constructor & Destructor

	Room();

	Room(int numberType);

#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //
	void setType(int typeNumber);

	// GETTERS //
	string getType(int typeNumber);
	string getRoom(int x, int y);

#pragma endregion

 #pragma region Room Functions

	void roomWallsCheck(string *giveWalls);

#pragma endregion

 #pragma region Outdated

#pragma endregion

	// Testing
	string roomWalls[TOTAL_WALLS];
protected:
	// Define the type of room, it will change the middle icon when discovered
	string type[TOTAL_TYPES];
	short roomType;

	
	// Creates the room visually, they will be squares. It is 5x4 to leave room for the room connectors (halls?)
	string room[Width_SIZE][Height_SIZE];
};

