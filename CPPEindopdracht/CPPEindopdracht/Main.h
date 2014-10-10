#pragma once

#include "MapObject.h"
#include "Map.h"
#include "Hero.h"

#include <iostream>
#include <string>

using namespace std;

class Main
{
public:
	Main();
	virtual ~Main();

private:
	Map* map;
	Hero* hero;
	bool playing;
	int horizontal = 10;
	int vertical = 10;
	int floorNumber = 5;

	bool checkCommand(string command);
	void printCommands();
	void printExits();
	void printMap();
	void printInventory();
	void goTo(string exit);
	void dropItem(string itemName);
	void doCommand(string command);
};

