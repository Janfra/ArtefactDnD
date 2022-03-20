#include <iostream>
#include <string>
#define Height_SIZE 4
#define Width_SIZE 4
using namespace std;

#pragma once
class Room
{
public:
 #pragma region Constructor & Destructor

	Room();

#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //
	void setType();
	void setGrid(string type);

	// GETTERS //
	string getType();
	string getRoom(int x, int y);

#pragma endregion

 #pragma region Room Functions

#pragma endregion

 #pragma region Outdated

#pragma endregion

protected:
	// Define the type of room, it will change the middle icon when discovered
	string type[4];
	
	// Creates the room visually, they will be squares. It is 5x4 to leave room for the room connectors (halls?)
	string room[Width_SIZE][Height_SIZE];
};

