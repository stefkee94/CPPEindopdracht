#pragma once

#include "MapObject.h"
#include "Inventory.h"

#include <iostream>

class Hero : public MapObject
{
public:
	Hero();
	virtual ~Hero();

	void printInventory();
	bool addExperience(int addExperience);
	string dropItem(string itemName);

	int getXPos();
	int getYPos();
	void setXPos(int x);
	void setYPos(int y);

	int getExp();
	int getExpNeeded();
	int getLevel();

	void addAttack();
	void addDefense();
	void addNotice();
	void addHp();

private:
	const int MAXLEVEL = 10;
	int experience;
	int notice;
	Inventory inventory;

	int xPos;
	int yPos;
};

