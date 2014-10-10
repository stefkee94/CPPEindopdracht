#include "Map.h"

int Map::horizontalMapSize = 0;
int Map::verticalMapSize = 0;

int Map::randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void Map::generateRandomMap(int floor_number)
{
	for (int y = 0; y < verticalMapSize; ++y)
	{
		for (int x = 0; x < horizontalMapSize; ++x)
		{
			int rand = randomNumber(0, 1);

			//the very first room (x:0, y:0) is the start position and thus has to be a room
			if (x == 0 && y == 0)
			{
				chamberList[y][x] = Chamber(x, y, floor_number);
				chamberList[y][x].setVisited();
				continue;
			}

			//if rand == 1 make a new room here
			if (rand >= 1)
			{
				chamberList[y][x] = Chamber(x, y, floor_number);
			}
		}
	}

	//A new loop to check if every room has a neighbour else add a neighbour
	for (int y = 0; y < verticalMapSize; y++)
	{
		for (int x = 0; x < horizontalMapSize; x++)
		{
			Chamber current = chamberList[y][x];

			//if the room to the west has an exit to the east -> this room needs an exit to that neighbour
			if (x > 0 && chamberList[y][(x - 1)].hasExitEast() && !current.hasExitWest())
			{
				current.setExitWest();
			}

			//if the room to the east has an exit to the west -> this room needs an exit to that neighbour
			if (x < (horizontalMapSize - 1) && chamberList[y][(x + 1)].hasExitWest() && !current.hasExitEast())
			{
				current.setExitEast();
			}

			//if the room to the nort has an exit to the south -> this room needs an exit to that neighbour
			if (y > 0 && chamberList[(y - 1)][x].hasExitSouth() && !current.hasExitNorth())
			{
				current.setExitNorth();
			}

			//if the room to the south has an exit to the north -> this room needs an exit to that neighbour
			if (y < (verticalMapSize - 1) && chamberList[(y + 1)][x].hasExitNorth() && !current.hasExitSouth())
			{
				current.setExitSouth();
			}

			chamberList[y][x] = current;
		}
	}
}

//Get all the exits from a chamber
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

//Check if the chamber contains the given exit
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

void Map::setVisited(int x, int y)
{
	chamberList[y][x].setVisited();
}

void Map::printMap(int curXPos, int curYPos)
{
	vector<vector<string>> stringMap;

	stringMap.resize(verticalMapSize * 2);
	for (int i = 0; i < (verticalMapSize * 2); i++)
	{
		stringMap[i].resize(horizontalMapSize);
	}

	//Convert the map to a string vector
	for (int y = 0; y < verticalMapSize * 2; y = y + 2)
	{
		for (int x = 0; x < horizontalMapSize; ++x)
		{
			Chamber current = chamberList[y / 2][x];

			//If the current chamber has any exits it is a room
			if ((current.hasExitEast() || current.hasExitNorth() || current.hasExitSouth() || current.hasExitWest()) && current.isVisited())
			{
				//If the current has an exit to the south, on the next row there has to be shown a '|'
				if (current.hasExitSouth())
				{
					if (x != 0)
						stringMap[(y + 1)][x] = " |";
					else
						stringMap[(y + 1)][x] = "|";
				}
				//Else on the next row there has to be shown a ' '
				else
				{
					if (x != 0)
						stringMap[(y + 1)][x] = "  ";
					else
						stringMap[(y + 1)][x] = " ";
				}

				if (current.hasExitNorth())
				{
					if (x != 0)
						stringMap[(y - 1)][x] = " |";
					else
						stringMap[(y - 1)][x] = "|";
				}

				//Print a 'P' if the player is on this position else print a 'R'
				if (x == curXPos && y == (curYPos * 2))
				{
					//and if there is an exit to the east also print a '-'
					if (current.hasExitEast())
						stringMap[y][x] = "P-";
					else
						stringMap[y][x] = "P ";
				}
					
				else
				{
					//and if there is an exit to the east also print a '-'
					if (current.hasExitEast())
						stringMap[y][x] = "R-";
					else
						stringMap[y][x] = "R ";
				}
			}
			//Else the room has not been discovered yet
			else
			{
				stringMap[y][x] = ". ";

				if (x != 0)
					stringMap[(y + 1)][x] = "  ";
				else
					stringMap[(y + 1)][x] = " ";
			}
		}
	}

	//Print the legenda
	cout << endl << "Legenda:" << endl << "R : Ruimte" << endl << ". : Niet bezocht" << endl << "P : Speler" << endl;

	//print the map
	for (int y = 0; y < verticalMapSize * 2; ++y)
	{
		cout << endl;

		for (int x = 0; x < horizontalMapSize; ++x)
		{
			cout << stringMap[y][x];
		}
	}

	cout << endl;
}

Map::Map(int horizontalSize, int verticalSize, int floor_number)
{
	horizontalMapSize = horizontalSize;
	verticalMapSize = verticalSize;

	chamberList.resize(verticalMapSize);

	for (int i = 0; i < verticalMapSize; i++)
	{
		chamberList[i].resize(horizontalMapSize);
	}

	generateRandomMap(floor_number);
}


Map::~Map()
{
}
