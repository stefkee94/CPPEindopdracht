#pragma once
#include "Map.h"
#include "MapObject.h"
#include <string>

using namespace std;

class Main
{
public:
	Main();
	~Main();

private:
	Map* map;
	MapObject map_object;
	bool playing;
	int horizontal = 10;
	int vertical = 10;
	int floorNumber = 5;

	bool checkCommand(string command);
	void printCommands();
	void doCommand(string command);
};

