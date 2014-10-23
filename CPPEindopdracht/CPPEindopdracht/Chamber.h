#pragma once

#include "Map.h"
#include "Enemy.h"

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
	bool hasStairsUp();
	bool hasStairsDown();
	bool hasEnemies();
	bool hasEnemy(string name);
	int getAmountOfEnemies();
	Enemy& getEnemy(string name);

	void setExitNorth();
	void setExitEast();
	void setExitSouth();
	void setExitWest();
	void setVisited();
	void setMarked();

private:
	bool north, east, south, west;
	bool visited, marked, stairsUp, stairsDown;
	int floorNumber, x, y;

	vector<Enemy*> enemies;
	const int MAXENEMIES = 3;

	int randomNumber(int min, int max);
	void generateRandomExits(int x, int y);
	void generateRandomEnemies();
	void generateRandomItems();
	void generateRandomTraps();
	void generateStairs();
	void generate();
};

