#include "Chamber.h"

int Chamber::randomNumber(int min, int max)
{
	random_device dev;
	default_random_engine dre(dev());
	uniform_int_distribution<int> dist(min, max);
	return dist(dre);
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
	int numberOfEnemies = randomNumber(0, MAXENEMIES);

	for (int i = 0; i < numberOfEnemies; ++i)
	{
		//TODO make random enemy
		enemies.push_back(new Enemy(EnemyType::RAT, floorNumber, i));
	}
}

void Chamber::generateRandomItems()
{

}

void Chamber::generateRandomTraps()
{

}

void Chamber::generateStairs()
{
	//on floor 1 there is only a stairs up
	if (floorNumber == 1)
	{
		if (y == (Map::verticalMapSize - 1))
		{
			stairsUp = true;
			Map::mapAmountOfStairs++;
		}
	}
	//on floor 5 (max) there is only a stairs down
	else if (floorNumber == 5)
	{
		if (x == 0 && y == 0)
		{
			stairsDown = true;
			Map::mapAmountOfStairs++;
		}
	}
	else
	{
		if (x == 0 && y == 0)
		{
			stairsDown = true;
			Map::mapAmountOfStairs++;
		}

		if (y == (Map::verticalMapSize - 1))
		{
			stairsUp = true;
			Map::mapAmountOfStairs++;
		}
	}
}

void Chamber::printEnemies()
{
	cout << endl << "Tegenstanders in de kamer:";

	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		cout << endl;
		cout << enemies[i]->getName() << " -> Level: " << enemies[i]->getEnemyLevel() << " -> HP: " << enemies[i]->getCurrentHp();
	}

	cout << endl << endl;
}

void Chamber::hitEnemy(string enemyName, int damage)
{
	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		Enemy* e = enemies.at(i);

		if (e->getName() == enemyName)
		{
			e->Hit(damage);
			if (e->isDead())
			{
				enemies.erase(enemies.begin() + i);
				cout << endl << e->getName() << " died" << endl;
			}
		}
	}
}

int Chamber::enemyAttack(MapObject hero, int index)
{
	int damage = enemies.at(index)->Attack(hero);

	if (damage > 0)
		cout << enemies.at(index)->getName() << " succesfully hit you with " << damage << " damage" << endl;
	else
		cout << enemies.at(index)->getName() << " failed to hit you" << endl;

	return damage;
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

bool Chamber::hasEnemy(string name)
{
	for (Enemy* e : enemies)
	{
		if (e->getName() == name)
			return true;
	}
	return false;
}

int Chamber::getAmountOfEnemies()
{
	return enemies.size();
}

Enemy& Chamber::getEnemy(string name)
{
	for (Enemy* e : enemies)
	{
		if (e->getName() == name)
			return *e;
	}

	//This one is never called because first a check is done if the given enemyName exists
	//(Just to remove warning)
	return Enemy();
}

bool Chamber::isVisited()
{
	return visited;
}

bool Chamber::isMarked()
{
	return marked;
}

bool Chamber::hasStairsDown()
{
	return stairsDown;
}

bool Chamber::hasStairsUp()
{
	return stairsUp;
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

void Chamber::setMarked()
{
	marked = true;
}
#pragma endregion gettersAndSetters

void Chamber::generate()
{
	generateRandomExits(x, y);
	generateRandomEnemies();
	generateRandomItems();
	generateRandomTraps();

	//Check if there is already a stairs up and/ or down in the map
	if (floorNumber == 1 || floorNumber == 5)
	{
		if (Map::mapAmountOfStairs == 0)
			generateStairs();
	}
	else if (Map::mapAmountOfStairs <= 2)
	{
		generateStairs();
	}
}

Chamber::Chamber(int _x, int _y, int floor_number)
{
	floorNumber = floor_number;
	x = _x;
	y = _y;

	visited = false;
	marked = false;
	stairsUp = false;
	stairsDown = false;

	generate();
}

Chamber::Chamber()
{
	north = false;
	east = false;
	south = false;
	west = false;
	visited = false;
	marked = false;
	stairsUp = false;
	stairsDown = false;

	x = -1;
	y = -1;
	floorNumber = -1;
}

Chamber::Chamber(const Chamber& other)
{
	north = other.north;
	east = other.east;
	south = other.south;
	west = other.west;

	visited = other.visited;
	marked = other.marked;
	stairsUp = other.stairsUp;
	stairsDown = other.stairsDown;

	floorNumber = other.floorNumber;
	x = other.x;
	y = other.y;

	for (Enemy* e : other.enemies)
	{
		Enemy* clone = new Enemy(*e);
		enemies.push_back(clone);
	}
}

//Chamber::Chamber(Chamber&& other)
//{
//
//}

Chamber& Chamber::operator=(const Chamber& other)
{
	if (this != &other)
	{
		for (Enemy* e : enemies)
		{
			delete e;
		}
		enemies.clear();

		north = other.north;
		east = other.east;
		south = other.south;
		west = other.west;

		visited = other.visited;
		marked = other.marked;
		stairsUp = other.stairsUp;
		stairsDown = other.stairsDown;

		floorNumber = other.floorNumber;
		x = other.x;
		y = other.y;

		for (Enemy* e : other.enemies)
		{
			Enemy* clone = new Enemy(*e);
			enemies.push_back(clone);
		}
	}
	return *this;
}

//Chamber& Chamber::operator=(Chamber&& other)
//{
//	if (this != &other)
//	{
//		
//	}
//	return *this;
//}

Chamber::~Chamber()
{
	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		delete enemies[i];
	}
}
