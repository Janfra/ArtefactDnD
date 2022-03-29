#include "Room.h"



 #pragma region Constructor & Destructor

Room::Room()
{
	srand(time(NULL));
	type[0] = "Spawn";
	type[1] = "Enemy";
	type[2] = "Trap";
	type[3] = "Item";
	type[4] = "Empty";
	roomWallsCheck(roomWalls);

	setType(0);
}

Room::Room(int numberType)
{
	srand(time(NULL));
	type[0] = "Spawn";
	type[1] = "Enemy";
	type[2] = "Trap";
	type[3] = "Item";
	type[4] = "Empty";
	roomWallsCheck(roomWalls);

	setType(numberType);
}
#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //

	void Room::setType(int typeNumber)
	{
		if (typeNumber > (TOTAL_TYPES * 3)) {
			roomType = (TOTAL_TYPES * 3);
		}
		else if (typeNumber < 0) {
			roomType = 0;
		}
		else {
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
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  -";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "-  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "---";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 8:
		case 9:
		case 10:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  *";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "*  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "***";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 11:
		case 12:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  `";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "`  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "```";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 13:
		case 14:
		case 15:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  ~";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "~  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "~~~";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		default:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  #";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "#  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
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

	// GETTERS //

	string Room::getType(int typeNumber)
	{
		return type[typeNumber];
	}

	string Room::getRoom(int x, int y)
	{
		return room[x][y];
	}

#pragma endregion

 #pragma region Room Functions

	// Sets the roomWalls array to the strings given to the walls to check them later to avoid the fillMap function reassigning a room.
	void Room::roomWallsCheck(string *giveWall)
	{
		for (int i = 0; i < TOTAL_TYPES; i++) {
			setType(i);
			for (int w = 0; w < 3; w++) {
				if (w == 0) {
					giveWall[((i * 3) + (w + 1)) - 1] = room[0][0];
				}
				else if (w == 1){
					giveWall[((i * 3) + (w + 1)) - 1] = room[(Width_SIZE - 1)][0];
				}
				else {
					giveWall[((i * 3) + (w + 1)) - 1] = room[1][0];
				}
			}
		}
	}

#pragma endregion

 #pragma region Outdated

	//switch (y)
//{
//case (Height_SIZE - Height_SIZE):
//case (Height_SIZE - 1):
//	room[y][x] = " ";
//	break;
//default:
//	room[y][x] = "#";
//	break;
//}
//switch (x)
//{
//case (Width_SIZE - Width_SIZE):
//case (Width_SIZE - 1):
//	room[y][x] = " ";
//	break;
//default:
//	break;
//}

	// for (int y = 0; y < Height_SIZE; y++) {
	/*for (int x = 0; x < Width_SIZE; x++) {
		if (x == (Width_SIZE - Width_SIZE)) {
			room[x][y] = "  #";
		}
		else if (x == (Width_SIZE - 1)) {
			room[x][y] = "#  ";
		}
		else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
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
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  -";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "-  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "---";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 2:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  *";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "*  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "***";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 3:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  `";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "`  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "```";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		case 4:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  ~";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "~  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
						room[x][y] = "~~~";
					}
					else {
						room[x][y] = "   ";
					}
				}
			}
			break;
		default:
			for (int y = 0; y < Height_SIZE; y++) {
				for (int x = 0; x < Width_SIZE; x++) {
					if (x == (Width_SIZE - Width_SIZE)) {
						room[x][y] = "  #";
					}
					else if (x == (Width_SIZE - 1)) {
						room[x][y] = "#  ";
					}
					else if (y == (Height_SIZE - 1) || y == (Height_SIZE - Height_SIZE)) {
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