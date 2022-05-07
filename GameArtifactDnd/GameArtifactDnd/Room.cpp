#include "Room.h"



 #pragma region Constructor & Destructor
	// CONSTRUCTOR //
Room::Room()
{
	// Set a random seed for the randomizer
	srand(time(NULL));
	// Initialize the variables
	type[0] = "Spawn";
	type[1] = "Enemy";
	type[2] = "Trap";
	type[3] = "Item";
	type[4] = "Empty";
	roomWallsCheck(roomWalls);
	encounters = new Encounter();

	setType(0);
}
// Overloaded constructor that lets you choose the room type //
Room::Room(int numberType)
{
	// Set a random seed for the randomizer
	srand(time(NULL));
	// Initialize Variables //
	type[0] = "Spawn";
	type[1] = "Enemy";
	type[2] = "Trap";
	type[3] = "Item";
	type[4] = "Empty";
	roomWallsCheck(roomWalls);
	encounters = new Encounter();

	setType(numberType);
}
	// DESTRUCTOR //
Room::~Room()
{
	// Clears space in the heap and prevents hanging pointers //
	delete encounters;
	encounters = NULL;
}


#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //

// Sets the 'room' array, to the type define in the switch using the parameter 'typeNumber'
string Room::setType(int typeNumber)
{
	if (typeNumber > (TOTAL_TYPES * 3)) 
	{
		roomType = (TOTAL_TYPES * 3);
	}
	else if (typeNumber < 0) 
	{
		roomType = 0;
	}
	else 
	{
		roomType = typeNumber;
	}
	switch (roomType)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		for (int y = 0; y < HEIGHT_SIZE; y++) 
		{
			for (int x = 0; x < WIDTH_SIZE; x++) 
			{
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) 
				{
					room[x][y] = "  -";
				}
				else if (x == (WIDTH_SIZE - 1)) 
				{
					room[x][y] = "-  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) 
				{
					room[x][y] = "---";
				}
				else 
				{
					room[x][y] = "   ";
				}
			}
		}
		return type[1];
		break;
	case 8:
	case 9:
	case 10:
		for (int y = 0; y < HEIGHT_SIZE; y++) 
		{
			for (int x = 0; x < WIDTH_SIZE; x++) 
			{
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) 
				{
					room[x][y] = "  *";
				}
				else if (x == (WIDTH_SIZE - 1)) 
				{
					room[x][y] = "*  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) 
				{
					room[x][y] = "***";
				}
				else {
					room[x][y] = "   ";
				}
			}
		}
		return type[2];
		break;
	case 11:
	case 12:
		for (int y = 0; y < HEIGHT_SIZE; y++) 
		{
			for (int x = 0; x < WIDTH_SIZE; x++) 
			{
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) 
				{
					room[x][y] = "  '";
				}
				else if (x == (WIDTH_SIZE - 1)) 
				{
					room[x][y] = "'  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) 
				{
					room[x][y] = "'''";
				}
				else 
				{
					room[x][y] = "   ";
				}
			}
		}
		return type[3];
		break;
	case 13:
	case 14:
	case 15:
		for (int y = 0; y < HEIGHT_SIZE; y++) 
		{
			for (int x = 0; x < WIDTH_SIZE; x++) 
			{
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) 
				{
					room[x][y] = "  ~";
				}
				else if (x == (WIDTH_SIZE - 1)) 
				{
					room[x][y] = "~  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) 
				{
					room[x][y] = "~~~";
				}
				else 
				{
					room[x][y] = "   ";
				}
			}
		}
		return type[4];
		break;
	default:
		for (int y = 0; y < HEIGHT_SIZE; y++) 
		{
			for (int x = 0; x < WIDTH_SIZE; x++) {
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) 
				{
					room[x][y] = "  #";
				}
				else if (x == (WIDTH_SIZE - 1)) 
				{
					room[x][y] = "#  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) 
				{
					room[x][y] = "###";
				}
				else 
				{
					room[x][y] = "   ";
				}
			}
		}
		return type[0];
		break;
	}
}

	// GETTERS //
// Returns room type name using the 'typeNumber' parameter.
string Room::getType(int typeNumber)
{
	return type[typeNumber];
}

// Returns value assigned to the 2D array using parameters 'x' and 'y' for the coordinates.
string Room::getRoom(int x, int y)
{
	return room[x][y];
}

#pragma endregion

 #pragma region Room Functions

// Sets the roomWalls array to the strings given to the walls of each room type to check for encounters.
void Room::roomWallsCheck(string *giveWall)
{
	for (int i = 0; i < TOTAL_TYPES; i++) {
		wallsStoring(i);
		for (int w = 0; w < 3; w++) {
			if (w == 0) {
				giveWall[((i * 3) + (w + 1)) - 1] = room[0][0];
			}
			else if (w == 1){
				giveWall[((i * 3) + (w + 1)) - 1] = room[(WIDTH_SIZE - 1)][0];
			}
			else {
				giveWall[((i * 3) + (w + 1)) - 1] = room[1][0];
			}
		}
	}
}

// Sets the room type using 'roomType' parameter. Similar to setType(), however this version has no probability to it. 
void Room::wallsStoring(int roomType) {
	switch (roomType)
	{
	case 1:
		for (int y = 0; y < HEIGHT_SIZE; y++) {
			for (int x = 0; x < WIDTH_SIZE; x++) {
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
					room[x][y] = "  -";
				}
				else if (x == (WIDTH_SIZE - 1)) {
					room[x][y] = "-  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
					room[x][y] = "---";
				}
				else {
					room[x][y] = "   ";
				}
			}
		}
		break;
	case 2:
		for (int y = 0; y < HEIGHT_SIZE; y++) {
			for (int x = 0; x < WIDTH_SIZE; x++) {
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
					room[x][y] = "  *";
				}
				else if (x == (WIDTH_SIZE - 1)) {
					room[x][y] = "*  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
					room[x][y] = "***";
				}
				else {
					room[x][y] = "   ";
				}
			}
		}
		break;
	case 3:
		for (int y = 0; y < HEIGHT_SIZE; y++) {
			for (int x = 0; x < WIDTH_SIZE; x++) {
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
					room[x][y] = "  '";
				}
				else if (x == (WIDTH_SIZE - 1)) {
					room[x][y] = "'  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
					room[x][y] = "'''";
				}
				else {
					room[x][y] = "   ";
				}
			}
		}
		break;
	case 4:
		for (int y = 0; y < HEIGHT_SIZE; y++) {
			for (int x = 0; x < WIDTH_SIZE; x++) {
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
					room[x][y] = "  ~";
				}
				else if (x == (WIDTH_SIZE - 1)) {
					room[x][y] = "~  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
					room[x][y] = "~~~";
				}
				else {
					room[x][y] = "   ";
				}
			}
		}
		break;
	default:
		for (int y = 0; y < HEIGHT_SIZE; y++) {
			for (int x = 0; x < WIDTH_SIZE; x++) {
				if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
					room[x][y] = "  #";
				}
				else if (x == (WIDTH_SIZE - 1)) {
					room[x][y] = "#  ";
				}
				else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
					room[x][y] = "###";
				}
				else {
					room[x][y] = "   ";
				}
			}
		}
		break;
	}
}

#pragma endregion

 #pragma region Outdated

	//switch (y)
//{
//case (HEIGHT_SIZE - HEIGHT_SIZE):
//case (HEIGHT_SIZE - 1):
//	room[y][x] = " ";
//	break;
//default:
//	room[y][x] = "#";
//	break;
//}
//switch (x)
//{
//case (WIDTH_SIZE - WIDTH_SIZE):
//case (WIDTH_SIZE - 1):
//	room[y][x] = " ";
//	break;
//default:
//	break;
//}

	// for (int y = 0; y < HEIGHT_SIZE; y++) {
	/*for (int x = 0; x < WIDTH_SIZE; x++) {
		if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
			room[x][y] = "  #";
		}
		else if (x == (WIDTH_SIZE - 1)) {
			room[x][y] = "#  ";
		}
		else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
			room[x][y] = "###";
		}
		else {
			room[x][y] = "   ";
		}
	}
	}*/

	/*void Room::setRandomType()
	{
		randomNumber = (rand() % 4) + 1;
		roomType = randomNumber;
		switch (randomNumber)
		{
		case 1:
			for (int y = 0; y < HEIGHT_SIZE; y++) {
				for (int x = 0; x < WIDTH_SIZE; x++) {
					if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
						room[x][y] = "  -";
					}
					else if (x == (WIDTH_SIZE - 1)) {
						room[x][y] = "-  ";
					}
					else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
						room[x][y] = "---";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 2:
			for (int y = 0; y < HEIGHT_SIZE; y++) {
				for (int x = 0; x < WIDTH_SIZE; x++) {
					if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
						room[x][y] = "  *";
					}
					else if (x == (WIDTH_SIZE - 1)) {
						room[x][y] = "*  ";
					}
					else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
						room[x][y] = "***";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 3:
			for (int y = 0; y < HEIGHT_SIZE; y++) {
				for (int x = 0; x < WIDTH_SIZE; x++) {
					if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
						room[x][y] = "  `";
					}
					else if (x == (WIDTH_SIZE - 1)) {
						room[x][y] = "`  ";
					}
					else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
						room[x][y] = "```";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 4:
			for (int y = 0; y < HEIGHT_SIZE; y++) {
				for (int x = 0; x < WIDTH_SIZE; x++) {
					if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
						room[x][y] = "  ~";
					}
					else if (x == (WIDTH_SIZE - 1)) {
						room[x][y] = "~  ";
					}
					else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
						room[x][y] = "~~~";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		default:
			for (int y = 0; y < HEIGHT_SIZE; y++) {
				for (int x = 0; x < WIDTH_SIZE; x++) {
					if (x == (WIDTH_SIZE - WIDTH_SIZE)) {
						room[x][y] = "  #";
					}
					else if (x == (WIDTH_SIZE - 1)) {
						room[x][y] = "#  ";
					}
					else if (y == (HEIGHT_SIZE - 1) || y == (HEIGHT_SIZE - HEIGHT_SIZE)) {
						room[x][y] = "###";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		}
	}*/

#pragma endregion