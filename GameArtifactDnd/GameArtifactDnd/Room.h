// Room has encounters
#include "Encounter.h"
// Defines set the size of the rooms
#define HEIGHT_SIZE 4
#define WIDTH_SIZE 4
// Define set the total amount of types for rooms.
#define TOTAL_TYPES 5
// Total types: 5 multiplied by top, left and right 3
#define TOTAL_WALLS (TOTAL_TYPES * 3) 
// Not having to use std::

#pragma once
class Room
{
public:
	// Functions explained in cpp file.
 #pragma region Constructor & Destructor
	// CONSTRUCTOR //
	Room();
	Room(int numberType);

	// DESTRUCTOR //
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

	// Stores all the possible displays of all the type of rooms.
	string roomWalls[TOTAL_WALLS];
	Encounter* encounters;
protected:
	// Define the type of room
	string type[TOTAL_TYPES];
	// This number defines which room type the room is.
	short roomType;

	// Stores the room format. It will be given to the grid to draw the current room type stored in it. 
	string room[WIDTH_SIZE][HEIGHT_SIZE];
};

