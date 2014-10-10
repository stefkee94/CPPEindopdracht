#pragma once

#include "MapObject.h"
#include "Inventory.h"

#include <string>
#include <iostream>

using namespace std;

class Hero : public MapObject
{
public:
	Hero();
	virtual ~Hero();

	void printInventory();
	string dropItem(string itemName);

	int getXPos();
	int getYPos();
	void setXPos(int x);
	void setYPos(int y);

private:
	string name;
	int level;
	const int MAXLEVEL = 10;
	int current_hp;
	int max_hp;
	int experience;
	int attack;
	int defense;
	int notice;
	Inventory inventory;

	int xPos;
	int yPos;

	virtual void Hit();
	virtual void Attack();
};

