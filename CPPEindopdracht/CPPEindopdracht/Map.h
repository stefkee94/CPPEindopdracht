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
	Map(int horizontalSize, int verticalSize, int floorNumber);
	virtual ~Map();

	static int horizontalMapSize;
	static int verticalMapSize;
	vector<vector<Chamber>> chamberList;

	list<string> getExits(int x, int y);
	bool hasExit(int x, int y, string exit);

	void setVisited(int x, int y);
	void printMap(int curXPos, int curYPos);

private:
	int randomNumber(int min, int max);
	void generateRandomMap(int floor_number);
};

