#pragma once

#include "Chamber.h"

#include <vector>

using namespace std;

class Map
{
public:
	static int horizontalMapSize;
	static int verticalMapSize;
	vector<vector<Chamber*>> chamberList;

	Map(int horizontalSize, int verticalSize, int floorNumber);
	~Map();

private:
	void generateRandomMap(int floor_number);
};

