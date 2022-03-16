#include "Room.h"

#pragma region Constructor & Destructor

Room::Room()
{
	for (int y = 0; y < Height_SIZE; y++) {
		for (int x = 0; x < Width_SIZE; x++) {
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
			room[x][y] = " ~ ";
			room[1][1] = "   ";
			room[1][2] = "   ";
			room[2][1] = "   ";
			room[2][2] = "   ";
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


