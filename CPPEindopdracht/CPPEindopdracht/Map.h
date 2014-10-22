#pragma once

#include "Chamber.h"
#include "Enemy.h"

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <random>

class Chamber;

using namespace std;

class Map
{
public:
	Map(int horizontalSize, int verticalSize, int floorNumber);
	virtual ~Map();

	static int horizontalMapSize;
	static int verticalMapSize;
	vector<vector<Chamber>> chamberList;

	list<string> getExits(int x, int y);
	bool hasExit(int x, int y, string exit);
	bool hasEnemies(int x, int y);
	bool hasEnemy(int x, int y, string name);
	Enemy& getEnemy(int x, int y, string name);
	int getAmountOfEnemies(int x, int y);

	int enemyAttack(int x, int y, MapObject hero, int index);
	void hitEnemy(int x, int y, string enemyName, int damage);
	void setVisited(int x, int y);
	void printMap(int curXPos, int curYPos);
	void printEnemies(int x, int y);

private:
	int amountOfChambers;

	int randomNumber(int min, int max);
	void generateRandomMap(int floor_number);
	void linkNeighbours();
	void setAmountOfChambers();
	void markChambers(int x, int y);
	void linkAllChambers(int x, int y);
};

