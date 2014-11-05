#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "MapObject.h"
#include "Map.h"
#include "Hero.h"

#include <iostream>
#include <string>
#include <Windows.h>

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
	bool inCombat, hasNoticed;
	int horizontal = 10;
	int vertical = 10;
	int floorNumber = 1;
	const int FINALFLOOR = 5;
	string lastRoomDirection;
	vector<Map*> floors;

	string hero_name;
	bool hero_name_set = false;

	string start_item;
	bool start_item_selected = false;

	bool checkCommand(string command);

	void printCommands();
	void printExits();
	void printRoomInformation();
	void printMap();
	void printInventory();
	void printSkills();
	void printRest();
	void printItem();
	void printNotice();
	void printEnemies();
	void climbStairs(string side);
	void setDescriptionOfRoom(int x, int y);

	std::vector<string> printAvailableItems();

	void addSkills();
	void goTo(string exit);
	void dropItem(string itemName);
	void useItem(string itemName);
	void pickItem(string itemName);
	void engage();
	void attackEnemy(string enemyName);
	void attackEnemyWithGrenade(int damage);
	void flee();
	void doCommand(string command);
	void saveFile();
	void lastBreath();
};

