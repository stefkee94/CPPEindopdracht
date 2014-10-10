#pragma once

#include "Chamber.h"

#include <string>
#include <vector>
#include <list>
#include <iostream>

class Chamber;

using namespace std;

class Map
{
public:
	static int horizontalMapSize;
	static int verticalMapSize;
	vector<vector<Chamber>> chamberList;

	list<string> getExits(int x, int y);
	bool hasExit(int x, int y, string exit);

	void setVisited(int x, int y);
	void printMap(int curXPos, int curYPos);

	Map(int horizontalSize, int verticalSize, int floorNumber);
	~Map();

private:
	int randomNumber(int min, int max);
	void generateRandomMap(int floor_number);
};

