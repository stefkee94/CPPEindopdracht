#pragma once

#include "Map.h"
#include "Enemy.h"

class Chamber
{
public:
	Chamber(int x, int y, int floor_number);
	Chamber();
	~Chamber();

	bool hasExitNorth();
	bool hasExitEast();
	bool hasExitSouth();
	bool hasExitWest();
	bool isVisited();

	void setExitNorth();
	void setExitEast();
	void setExitSouth();
	void setExitWest();
	void setVisited();

private:
	bool north, east, south, west;
	bool visited;
	int floorNumber;

	int randomNumber(int min, int max);
	void generateRandomChamber(int x, int y);
	void generateRandomEnemy();
};

