#include "Map.h"

#include <string>

void Map::generateRandomMap()
{
	for (int x = 0; x < horizontalMapSize; x++)
	{
		for (int y = 0; y < verticalMapSize; y++)
		{
			chamberList[x][y] = new Chamber(x, y);
		}
	}
}

Map::Map(int horizontalSize, int verticalSize, int floorNumber)
{
	horizontalMapSize = horizontalSize;
	verticalMapSize = verticalSize;
	chamberList.resize(verticalMapSize);

	for (int i = 0; i < verticalMapSize; i++)
	{
		chamberList[i].resize(horizontalMapSize);
	}

	generateRandomMap();
}


Map::~Map()
{
}
