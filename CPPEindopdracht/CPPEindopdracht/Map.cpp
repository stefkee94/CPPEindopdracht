#include "Map.h"

int Map::horizontalMapSize = 0;
int Map::verticalMapSize = 0;
int Map::mapAmountOfStairs = 0;

int Map::randomNumber(int min, int max)
{
	random_device dev;
	default_random_engine dre(dev());
	uniform_int_distribution<int> dist(min, max);
	return dist(dre);
}

#pragma region MapGeneratingMethods
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

	linkNeighbours();
}

void Map::linkNeighbours()
{
	//A new loop to check if every room is connected to its neighbour
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

	setAmountOfChambers();
}

void Map::setAmountOfChambers()
{
	//A new loop to check how many chambers there are
	for (int y = 0; y < verticalMapSize; y++)
	{
		for (int x = 0; x < horizontalMapSize; x++)
		{
			if (chamberList[y][x].hasExitEast() || chamberList[y][x].hasExitNorth() || chamberList[y][x].hasExitSouth() || chamberList[y][x].hasExitWest())
				amountOfChambers++;
		}
	}

	//Check if all the chambers are linked else link them (start check from start room)
	linkAllChambers(0, 0);
}

void Map::markChambers(int x, int y)
{
	//keep marking untill amountOfChambers = 0 (all the rooms are marked and linked)
	chamberList[y][x].setMarked();
	amountOfChambers--;

	//Check if there is an unmarked room to the south
	if (y < (verticalMapSize - 1))
	{
		if (!chamberList[(y + 1)][x].isMarked() && chamberList[y][x].hasExitSouth() && chamberList[(y + 1)][x].hasExitNorth())
		{
			markChambers(x, (y + 1));
		}
	}
	//check if there is an unmarked room to the west
	if (x > 0)
	{
		if (!chamberList[y][(x - 1)].isMarked() && chamberList[y][x].hasExitWest() && chamberList[y][(x - 1)].hasExitEast())
		{
			markChambers((x - 1), y);
		}
	}
	//check if there is an unmarked room to the north
	if (y > 0)
	{
		if (!chamberList[(y - 1)][x].isMarked() && chamberList[y][x].hasExitNorth() && chamberList[(y - 1)][x].hasExitSouth())
		{
			markChambers(x, (y - 1));
		}
	}
	//check if there is an unmarked room to the east
	if (x < (horizontalMapSize - 1))
	{
		if (!chamberList[y][(x + 1)].isMarked() && chamberList[y][x].hasExitEast() && chamberList[y][(x + 1)].hasExitWest())
		{
			markChambers((x + 1), y);
		}
	}
}

void Map::linkAllChambers(int x, int y)
{
	markChambers(x, y);
	bool doneRight = false;

	//As long as amountOfchambers <= 0 there are still unlinked rooms, so continue linking
	while (!(amountOfChambers <= 0))
	{
		//Start looking to the right if there is room for a chamber add one
		if (x < (horizontalMapSize - 1) && !doneRight)
		{
			if (x == (horizontalMapSize - 2))
				doneRight = true;

			if (chamberList[y][(x + 1)].isMarked())
			{
				x++;
			}
			else
			{
				chamberList[y][x].setExitEast();
				x++;
				chamberList[y][x].setExitWest();
				markChambers(x, y);
			}
		}
		//Else go back to x = 0
		else if (x > 0)
		{
			if (chamberList[y][(x - 1)].isMarked())
			{
				x--;
			}
			else
			{
				chamberList[y][x].setExitWest();
				x--;
				chamberList[y][x].setExitEast();
				markChambers(x, y);
			}
		}
		//else go down
		else if (y < (verticalMapSize - 1))
		{
			//if went 1 down try right again
			doneRight = false;

			if (chamberList[(y + 1)][x].isMarked())
			{
				y++;
			}
			else
			{
				chamberList[y][x].setExitSouth();
				y++;
				chamberList[y][x].setExitNorth();
				markChambers(x, y);
			}
		}
		////if everything else failed try going up again
		//else if (y > 0)
		//{
		//	if (chamberList[(y - 1)][x].isMarked())
		//	{
		//		y--;
		//	}
		//	else
		//	{
		//		y--;
		//		newRoom = true;
		//	}
		//}
	}
}
#pragma endregion MapGeneratingMethods

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

bool Map::hasEnemies(int x, int y)
{
	return chamberList[y][x].hasEnemies();
}

vector<Enemy*> Map::getAllEnemies(int x, int y)
{
	return chamberList[y][x].getAllEnemies();
}

bool Map::hasEnemy(int x, int y, string name)
{
	return chamberList[y][x].hasEnemy(name);
}

bool Map::hasStairsDown(int x, int y)
{
	return chamberList[y][x].hasStairsDown();
}

bool Map::hasStairsUp(int x, int y)
{
	return chamberList[y][x].hasStairsUp();
}

Enemy& Map::getEnemy(int x, int y, string name)
{
	return chamberList[y][x].getEnemy(name);
}

int Map::getAmountOfEnemies(int x, int y)
{
	return chamberList[y][x].getAmountOfEnemies();
}

int Map::enemyAttack(int x, int y, MapObject hero, int index)
{
	return chamberList[y][x].enemyAttack(hero, index);
}

void Map::hitEnemy(int x, int y, string enemyName, int damage)
{
	chamberList[y][x].hitEnemy(enemyName, damage);
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
			//if ((current.hasExitEast() || current.hasExitNorth() || current.hasExitSouth() || current.hasExitWest()) && current.isVisited())
			if ((current.hasExitEast() || current.hasExitNorth() || current.hasExitSouth() || current.hasExitWest()))
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

				if (current.hasExitWest())
				{
					if (x != 0)
					{
						if (stringMap[y][(x - 1)].find("R") != string::npos)
							stringMap[y][(x - 1)] = "R-";
						else if (stringMap[y][(x - 1)].find("P") != string::npos)
							stringMap[y][(x - 1)] = "P-";
						else if (stringMap[y][(x - 1)].find("L") != string::npos)
							stringMap[y][(x - 1)] = "L-";
						else if (stringMap[y][(x - 1)].find("H") != string::npos)
							stringMap[y][(x - 1)] = "H-";
						else
							stringMap[y][(x - 1)] = " -";
					}

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
				else if (current.hasStairsDown())
				{
					//and if there is an exit to the east also print a '-'
					if (current.hasExitEast())
						stringMap[y][x] = "L-";
					else
						stringMap[y][x] = "L ";
				}
				else if (current.hasStairsUp())
				{
					if (current.hasExitEast())
						stringMap[y][x] = "H-";
					else
						stringMap[y][x] = "H ";
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
	cout << endl << "Legenda:" << endl << "R : Ruimte" << endl << ". : Niet bezocht" << endl << "P : Speler" << endl << "L : Ladder omlaag" << endl << "H : Ladder omhoog" << endl;

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
void Map::printEnemies(int x, int y)
{
	chamberList[y][x].printEnemies();
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
