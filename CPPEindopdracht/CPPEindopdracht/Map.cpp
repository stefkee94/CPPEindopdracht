#include "Map.h"

int Map::horizontalMapSize = 0;
int Map::verticalMapSize = 0;

int Map::randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void Map::generateRandomMap(int floor_number)
{
	for (int y = 0; y < horizontalMapSize; ++y)
	{
		for (int x = 0; x < verticalMapSize; ++x)
		{
			int rand = randomNumber(0, 1);

			//the very first room (x:0, y:0) is the start position and thus has to be a room
			if (x == 0 && y == 0)
				rand = 1;

			//if rand == 1 make a new room here
			if (rand >= 1)
			{
				chamberList[y][x] = Chamber(x, y, floor_number);
			}
		}
	}

	//A new loop to check if every room has a neighbour else add a neighbour
	for (int y = 0; y < horizontalMapSize; y++)
	{
		for (int x = 0; x < verticalMapSize; x++)
		{
			Chamber current = chamberList[y][x];

			//if the room to the west has an exit to the east -> this room needs an exit to that neighbour
			if (x > 0 && chamberList[y][(x - 1)].hasExitEast() && !current.hasExitWest())
			{
				current.setExitWest();
			}

			//if the room to the east has an exit to the west -> this room needs an exit to that neighbour
			if (x < horizontalMapSize && chamberList[y][(x + 1)].hasExitWest() && !current.hasExitEast())
			{
				current.setExitEast();
			}

			//if the room to the nort has an exit to the south -> this room needs an exit to that neighbour
			if (y > 0 && chamberList[(y - 1)][x].hasExitSouth() && !current.hasExitNorth())
			{
				current.setExitNorth();
			}

			//if the room to the south has an exit to the north -> this room needs an exit to that neighbour
			if (y < verticalMapSize && chamberList[(y + 1)][x].hasExitNorth() && !current.hasExitSouth())
			{
				current.setExitSouth();
			}

			chamberList[x][y] = current;
		}
	}
}

list<string> Map::getExits(int x, int y)
{
	list<string> exits;
	Chamber chamber = chamberList[y][x];

	if (chamber.hasExitNorth())
		exits.push_back("north");
	if (chamber.hasExitEast())
		exits.push_back("east");
	if (chamber.hasExitSouth())
		exits.push_back("south");
	if (chamber.hasExitWest())
		exits.push_back("west");

	return exits;
}

bool Map::hasExit(int x, int y, string exit)
{
	Chamber chamber = chamberList[y][x];

	if (exit == "north")
	{
		return chamber.hasExitNorth();
	}
	if (exit == "east")
	{
		return chamber.hasExitEast();
	}
	if (exit == "south")
	{
		return chamber.hasExitSouth();
	}
	if (exit == "west")
	{
		return chamber.hasExitWest();
	}

	return false;
}

Map::Map(int horizontalSize, int verticalSize, int floor_number)
{
	//set the size with '- 1' because of the zero-based vector<vector<Chamber>> chamberList for further use
	horizontalMapSize = (horizontalSize - 1);
	verticalMapSize = (verticalSize - 1);

	//Use the real size once to make the vector<vector<Chamber>> chamberList
	chamberList.resize(verticalSize);

	for (int i = 0; i < verticalSize; i++)
	{
		chamberList[i].resize(horizontalSize);
	}

	generateRandomMap(floor_number);
}


Map::~Map()
{
}
