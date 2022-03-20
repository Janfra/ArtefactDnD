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

	setType(numberType);
}
#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //

	void Room::setType(int typeNumber)
	{
		if (typeNumber > 5) {
			roomType = 5;
		}
		else if (typeNumber < 0) {
			roomType = 0;
		}
		else {
			roomType = typeNumber;
		}
		switch (typeNumber)
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