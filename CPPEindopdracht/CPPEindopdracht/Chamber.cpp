#include "Chamber.h"

int Chamber::randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void Chamber::generateRandomExits(int x, int y)
{
	int numberOfExits = 1;
	//Standard all the exits are false
	north = false;
	east = false;
	south = false;
	west = false;

	//Max exits = 2 (corners)
	if ((x == 0 && y == 0) || (x == 0 && y == (Map::verticalMapSize - 1)) || (x == (Map::horizontalMapSize - 1) && y == 0) || (x == (Map::horizontalMapSize - 1) && y == (Map::verticalMapSize - 1)))
	{
		numberOfExits = randomNumber(1, 2);
	}
	//Max exits = 3 (sides)
	else if ((x > 0 && x < (Map::horizontalMapSize - 1) && y == 0) || (y > 0 && y < (Map::verticalMapSize - 1) && x == 0) || (y > 0 && y < (Map::verticalMapSize - 1) && x == (Map::horizontalMapSize - 1)) || (x > 0 && x < (Map::horizontalMapSize - 1) && y == (Map::verticalMapSize - 1)))
	{
		numberOfExits = randomNumber(1, 3);
	}
	//Max exits = 4 (rest)
	else
	{
		numberOfExits = randomNumber(1, 4);
	}

	//Calculate random directions
	/*
		Corners
	*/
	if (x == 0 && y == 0)
	{
		//if numberOfExits = 2 there is no choice
		if (numberOfExits >= 2)
		{
			east = true;
			south = true;
		}
		//else randomly choose east or south
		else
		{
			int random = randomNumber(1, 2);
			if (random == 1)
			{
				east = true;
			}
			else
			{
				south = true;
			}
		}
	}
	else if (x == (Map::horizontalMapSize - 1) && y == 0)
	{
		//if numberOfExits = 2 there is no choice
		if (numberOfExits >= 2)
		{
			west = true;
			south = true;
		}
		//else randomly choose east or south
		else
		{
			int random = randomNumber(1, 2);
			if (random == 1)
			{
				west = true;
			}
			else
			{
				south = true;
			}
		}
	}
	else if (x == (Map::horizontalMapSize - 1) && y == (Map::verticalMapSize - 1))
	{
		//if numberOfExits = 2 there is no choice
		if (numberOfExits >= 2)
		{
			west = true;
			north = true;
		}
		//else randomly choose east or south
		else
		{
			int random = randomNumber(1, 2);
			if (random == 1)
			{
				west = true;
			}
			else
			{
				north = true;
			}
		}
	}
	else if (x == 0 && y == (Map::verticalMapSize - 1))
	{
		//if numberOfExits = 2 there is no choice
		if (numberOfExits >= 2)
		{
			east = true;
			north = true;
		}
		//else randomly choose east or south
		else
		{
			int random = randomNumber(1, 2);
			if (random == 1)
			{
				east = true;
			}
			else
			{
				north = true;
			}
		}
	}
	/*
		Sides
	*/
	//Top side
	else if (x > 0 && x < (Map::horizontalMapSize - 1) && y == 0)
	{
		//if numberOfExits = 3 there is no choice
		if (numberOfExits >= 3)
		{
			west = true;
			south = true;
			east = true;
		}
		else
		{
			int i = 0;
			while (i < numberOfExits)
			{
				int random = randomNumber(1, 3);
				if (random == 1)
				{
					west = true;
				}
				else if (random == 2)
				{
					south = true;
				}
				else
				{
					east = true;
				}

				i++;
			}
		}
	}
	//west side
	else if (y > 0 && y < (Map::verticalMapSize - 1) && x == 0)
	{
		//if numberOfExits = 3 there is no choice
		if (numberOfExits >= 3)
		{
			north = true;
			east = true;
			south = true;
		}
		else
		{
			int i = 0;
			while (i < numberOfExits)
			{
				int random = randomNumber(1, 3);
				if (random == 1)
				{
					north = true;
				}
				else if (random == 2)
				{
					east = true;
				}
				else
				{
					south = true;
				}

				i++;
			}
		}
	}
	//east side
	else if (y > 0 && y <(Map::verticalMapSize - 1) && x == (Map::horizontalMapSize - 1))
	{
		//if numberOfExits = 3 there is no choice
		if (numberOfExits >= 3)
		{
			north = true;
			west = true;
			south = true;
		}
		else
		{
			int i = 0;
			while (i < numberOfExits)
			{
				int random = randomNumber(1, 3);
				if (random == 1)
				{
					north = true;
				}
				else if (random == 2)
				{
					west = true;
				}
				else
				{
					south = true;
				}

				i++;
			}
		}
	}
	//bottom side
	else if (x > 0 && x < (Map::horizontalMapSize - 1) && y == (Map::verticalMapSize - 1))
	{
		//if numberOfExits = 3 there is no choice
		if (numberOfExits >= 3)
		{
			west = true;
			north = true;
			east = true;
		}
		else
		{
			int i = 0;
			while (i < numberOfExits)
			{
				int random = randomNumber(1, 3);
				if (random == 1)
				{
					west = true;
				}
				else if (random == 2)
				{
					north = true;
				}
				else
				{
					east = true;
				}

				i++;
			}
		}
	}
	/*
		Rest
	*/
	else
	{
		//if numberOfExits = 4 there is no choice
		if (numberOfExits >= 4)
		{
			west = true;
			north = true;
			east = true;
			south = true;
		}
		else
		{
			int i = 0;
			while (i < numberOfExits)
			{
				int random = randomNumber(1, 3);
				if (random == 1)
				{
					west = true;
				}
				else if (random == 2)
				{
					north = true;
				}
				else if (random == 3)
				{
					east = true;
				}
				else
				{
					south = true;
				}

				i++;
			}
		}
	}
}

void Chamber::generateRandomEnemies()
{
	enemies.resize(randomNumber(0, MAXENEMIES));

	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		//TODO make random enemy
		enemies.push_back(new Enemy(EnemyType::RAT, floorNumber));
	}
}

void Chamber::generateRandomItems()
{

}

void Chamber::generateRandomTraps()
{

}

void Chamber::printEnemies()
{
	cout << endl << "Tegenstanders in de kamer:";

	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		cout << endl;
		cout << enemies[i]->getName();
	}

	cout << endl;
}

#pragma region gettersAndSetters
bool Chamber::hasExitNorth()
{
	return north;
}

bool Chamber::hasExitEast()
{
	return east;
}

bool Chamber::hasExitSouth()
{
	return south;
}

bool Chamber::hasExitWest()
{
	return west;
}

bool Chamber::hasEnemies()
{
	if (enemies.size() > 0)
		return true;
	return false;
}

bool Chamber::isVisited()
{
	return visited;
}

void Chamber::setExitNorth()
{
	north = true;
}

void Chamber::setExitEast()
{
	east = true;
}

void Chamber::setExitSouth()
{
	south = true;
}

void Chamber::setExitWest()
{
	west = true;
}

void Chamber::setVisited()
{
	visited = true;
}
#pragma endregion gettersAndSetters

void Chamber::generate()
{
	generateRandomExits(x, y);
	generateRandomEnemies();
	generateRandomItems();
	generateRandomTraps();
}

Chamber::Chamber(int _x, int _y, int floor_number)
{
	floorNumber = floor_number;
	x = _x;
	y = _y;

	visited = false;

	generate();
}

Chamber::Chamber()
{
	north = false;
	east = false;
	south = false;
	west = false;
	visited = false;
}

Chamber::~Chamber()
{
	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		delete enemies[i];
	}
}
