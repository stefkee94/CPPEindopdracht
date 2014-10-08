#include "Map.h"

#include <string>

int Map::horizontalMapSize = 0;
int Map::verticalMapSize = 0;

void Map::generateRandomMap(int floor_number)
{
	for (int x = 0; x < horizontalMapSize; x++)
	{
		for (int y = 0; y < verticalMapSize; y++)
		{
			chamberList[y][x] = new Chamber(x, y, floor_number);
		}
	}
}

Map::Map(int horizontalSize, int verticalSize, int floor_mumber)
{
	horizontalMapSize = horizontalSize;
	verticalMapSize = verticalSize;
	chamberList.resize(verticalMapSize);

	for (int i = 0; i < verticalMapSize; i++)
	{
		chamberList[i].resize(horizontalMapSize);
	}

	generateRandomMap(floor_mumber);
}


Map::~Map()
{
}
