#pragma once

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
	bool inCombat;
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
	void printMap();
	void printInventory();
	void printSkills();
	void printEnemies();
	void climbStairs();

	std::vector<string> printAvailableItems();

	void addSkills();
	void goTo(string exit);
	void dropItem(string itemName);
	void useItem(string itemName);
	void engage();
	void attackEnemy(string enemyName);
	void attackEnemyWithGrenade(int damage);
	void flee();
	void doCommand(string command);
};

