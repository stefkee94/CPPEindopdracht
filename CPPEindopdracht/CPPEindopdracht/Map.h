#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

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
	static int mapAmountOfStairs;

	vector<vector<Chamber>> chamberList;

	list<string> getExits(int x, int y);
	bool hasExit(int x, int y, string exit);
	bool hasEnemies(int x, int y);
	bool hasEnemy(int x, int y, string name);
	bool hasStairsDown(int x, int y);
	bool hasStairsUp(int x, int y);
	Enemy& getEnemy(int x, int y, string name);
	int getAmountOfEnemies(int x, int y);

	bool hasItem(int x, int y, string itemName);

	int enemyAttack(int x, int y, MapObject hero, int index);
	void hitEnemy(int x, int y, string enemyName, int damage);
	void setVisited(int x, int y);
	void printMap(int curXPos, int curYPos);
	void printEnemies(int x, int y);
	vector<Enemy*> getAllEnemies(int x, int y);

	int getAmountOfEnemiesToKill();
	void setAmountOfEnemiesToKill(int amount);
	

private:
	int amountOfChambers;
	int enemiesNeedToKill;

	int randomNumber(int min, int max);
	void generateRandomMap(int floor_number);
	void linkNeighbours();
	void setAmountOfChambers();
	void markChambers(int x, int y);
	void linkAllChambers(int x, int y);
};

