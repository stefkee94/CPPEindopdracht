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
	string dropItem(string itemName);

	int getXPos();
	int getYPos();
	void setXPos(int x);
	void setYPos(int y);

private:
	const int MAXLEVEL = 10;
	int experience;
	int notice;
	Inventory inventory;

	int xPos;
	int yPos;

	virtual void Hit();
	virtual void Attack();
};

