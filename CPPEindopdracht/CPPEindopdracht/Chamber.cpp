#include "Chamber.h"
#include "Map.h"

#include <string>
#include <vector>

int Chamber::randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void Chamber::generateRandomChamber(int x, int y)
{
	int numberOfExits = 1;

	//Max exits = 2 (corners)
	if ((x == 0 && y == 0) || (x == 0 && y == Map::verticalMapSize) || (x == Map::horizontalMapSize && y == 0) || (x == Map::horizontalMapSize && y == Map::verticalMapSize))
	{
		numberOfExits = randomNumber(1, 2);
	}
	//Max exits = 3 (sides)
	else if ((x > 0 && x < Map::horizontalMapSize && y == 0) || (y > 0 && y < Map::verticalMapSize && x == 0) || (y > 0 && y < Map::verticalMapSize && x == Map::horizontalMapSize) || (x > 0 && x < Map::horizontalMapSize && y == Map::verticalMapSize))
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
	else if (x == Map::horizontalMapSize && y == 0)
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
	else if (x == Map::horizontalMapSize && y == Map::verticalMapSize)
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
	else if (x == 0 && y == Map::verticalMapSize)
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
	else if (x > 0 && x < Map::horizontalMapSize && y == 0)
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
	else if (y > 0 && y < Map::verticalMapSize && x == 0)
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
	else if (y > 0 && y < Map::verticalMapSize && x == Map::horizontalMapSize)
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
	else if (x > 0 && x < Map::horizontalMapSize && y == Map::verticalMapSize)
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

Chamber::Chamber(int x, int y)
{
	generateRandomChamber(x, y);
}

Chamber::~Chamber()
{
}
