#include "Room.h"

 #pragma region Constructor & Destructor

Room::Room()
{
	for (int y = 0; y < Height_SIZE; y++) {
		for (int x = 0; x < Width_SIZE; x++) {
			if (x == (Width_SIZE - Width_SIZE) || y == (Height_SIZE - Height_SIZE) || x == (Width_SIZE - 1) || y == (Height_SIZE - 1)) {
				room[x][y] = " ~ ";
			}
			else {
				room[x][y] = "   ";
			}
		}
	}
}
#pragma endregion

 #pragma region Setters & Getters
	// SETTERS //

	void Room::setType()
	{
	}

	void Room::setGrid(string type)
	{
	}

	// GETTERS //

	string Room::getType()
	{
		return string();
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

#pragma endregion