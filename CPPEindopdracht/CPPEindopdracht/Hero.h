#pragma once

#include "MapObject.h"
#include "Inventory.h"

#include <string>
#include <iostream>

class Hero : public MapObject
{
public:
	Hero(std::string name, int level, double current_hp, double max_hp, double attack, double defense, int notice, Inventory inventory );
	virtual ~Hero();

	int getXPos();
	int getYPos();
	void setXPos(int x);
	void setYPos(int y);

private:
	int xPos;
	int yPos;

	virtual void Hit();
	virtual void Attack();
};

