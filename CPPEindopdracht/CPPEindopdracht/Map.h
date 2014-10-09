#pragma once

#include "Chamber.h"

#include <string>
#include <vector>
#include <list>

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
	Map(int horizontalSize, int verticalSize, int floorNumber);
	~Map();

private:
	int randomNumber(int min, int max);
	void generateRandomMap(int floor_number);
};

