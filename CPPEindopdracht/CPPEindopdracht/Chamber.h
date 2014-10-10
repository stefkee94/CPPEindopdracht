#pragma once

#include "Map.h"
#include "Enemy.h"

#include <vector>

class Chamber
{
public:
	Chamber(int _x, int _y, int floor_number);
	Chamber();
	virtual ~Chamber();

	void printEnemies();

	bool hasExitNorth();
	bool hasExitEast();
	bool hasExitSouth();
	bool hasExitWest();
	bool isVisited();
	bool hasEnemies();

	void setExitNorth();
	void setExitEast();
	void setExitSouth();
	void setExitWest();
	void setVisited();

private:
	bool north, east, south, west;
	bool visited;
	int floorNumber, x, y;

	vector<Enemy*> enemies;
	const int MAXENEMIES = 3;

	int randomNumber(int min, int max);
	void generateRandomExits(int x, int y);
	void generateRandomEnemies();
	void generateRandomItems();
	void generateRandomTraps();
	void generate();
};

