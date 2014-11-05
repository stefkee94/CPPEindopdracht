#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

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
	int getNotice();
	ItemType getItemType(string itemName);

	void addAttack();
	void addDefense();
	void addNotice();
	void addItem(string itemName);
	void addHp();
	void addCurrentHp(int amount);

	void fillHp(int amount);
	void equipSword(int extra_attack);

	int getKilledEnemies();
	void setKilledEnemies(int amount);
	void loadHeroInfo();
	void saveHeroInfo();
	
private:
	const int MAXLEVEL = 10;
	int experience;
	int notice;
	int killed_enemies;

	Inventory inventory;

	int xPos;
	int yPos;

	
};

