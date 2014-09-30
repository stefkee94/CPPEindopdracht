#include "Map.h"
#include "Room.h"
#include <string>

using namespace std;

const int MAPSIZE = 10;
Room* map[MAPSIZE][MAPSIZE];

void generateRandomMap()
{
	for (int x = 0; x < MAPSIZE; x++)
	{
		for (int y = 0; y < MAPSIZE; y++)
		{
			map[x][y] = new Room();
		}
	}
}

Map::Map()
{
	generateRandomMap();
}


Map::~Map()
{
}
