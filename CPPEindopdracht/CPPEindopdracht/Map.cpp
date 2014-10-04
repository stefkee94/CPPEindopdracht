#include "Map.h"
#include "Chamber.h"
#include <string>
#include <vector>

using namespace std;

int horizontalMapSize;
int verticalMapSize;
vector<vector<Chamber*>> chamberList;
vector<std::string> directions;

void generateRandomMap()
{
	int mapsize = horizontalMapSize * verticalMapSize;
	for (int x = 0; x < mapsize; x++)
	{
		for (int y = 0; y < mapsize; y++)
		{
			if (x == 0 && y == 0) {
				directions.push_back("east");
				directions.push_back("south");
			}
			else if (x == horizontalMapSize && y == 0) {
				directions.push_back("west");
				directions.push_back("south");
			}
			else if (x == verticalMapSize && y == 0) {
				directions.push_back("north");
				directions.push_back("east");
			}
			if (x == verticalMapSize && y == horizontalMapSize) 
			{
				directions.push_back("north");
				directions.push_back("west");
			}
			else if ((x > 0 && x < horizontalMapSize && y == 0) || (y > 0 && y < verticalMapSize && x == 0) || (x > 0 && x < horizontalMapSize && y == verticalMapSize) || (y > 0 && y < verticalMapSize && x == horizontalMapSize)) 
			{
				//maxNumberOfExits = 3;
			}
			else 
			{
				//maxNumberOfExits = 4;
			}

			chamberList[x][y] = new Chamber(directions.size(), directions);
			directions.clear();
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
