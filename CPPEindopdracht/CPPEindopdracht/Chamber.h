#pragma once

#include "Map.h"
#include "Enemy.h"
#include "ItemType.h"

#include <vector>
#include <random>

class Chamber
{
public:
	Chamber(int _x, int _y, int floor_number);
	Chamber();
	Chamber(const Chamber& other);
	//Chamber(Chamber&& other);
	Chamber& operator=(const Chamber& other);
	//Chamber& operator=(Chamber&& other);
	virtual ~Chamber();

	void printEnemies();
	void hitEnemy(string enemyName, int damage);
	int enemyAttack(MapObject hero, int index);

	bool hasExitNorth();
	bool hasExitEast();
	bool hasExitSouth();
	bool hasExitWest();
	bool isVisited();
	bool isMarked();
	bool getTrap();
	bool hasStairsUp();
	bool hasStairsDown();
	bool hasEnemies();
	bool hasEnemy(string name);
	int getAmountOfEnemies();
	Enemy& getEnemy(string name);
	vector<Enemy*> getAllEnemies();

	string getDescription();
	vector<string> getItemTypes();

	void setTrap(bool noticed_trap);
	void setExitNorth();
	void setExitEast();
	void setExitSouth();
	void setExitWest();
	void setVisited();
	void setMarked();
	void setItemTypes(std::vector<string> new_list);

private:
	bool north, east, south, west;
	bool visited, marked, stairsUp, stairsDown, trap;
	int floorNumber, x, y;
	string description;
	std::vector<string> item_types;

	vector<Enemy*> enemies;
	const int MAXENEMIES = 3;

	int randomNumber(int min, int max);
	void generateRandomExits(int x, int y);
	void generateRandomEnemies();
	void generateRandomItems();
	void generateRandomTraps();
	void generateStairs();
	string generateRandomDescription();
	void generate();
};

