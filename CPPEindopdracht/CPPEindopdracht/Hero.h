#pragma once

#include "MapObject.h"
#include "Inventory.h"

#include <iostream>

class Hero : public MapObject
{
public:
	Hero(string hero_name, string start_item);
	virtual ~Hero();

	void printInventory();
	void printSkills();
	bool addExperience(int addExperience);

	string dropItem(string itemName);
	void useItem(string itemName);
	void removeItemFromInventory(string itemName);

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

	void fillHp(int amount);
	void equipSword(int extra_attack);

private:
	const int MAXLEVEL = 10;
	int experience;
	int notice;
	Inventory inventory;

	int xPos;
	int yPos;
};

