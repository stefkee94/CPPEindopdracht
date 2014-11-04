#pragma once

#include "ItemType.h"

#include <vector>
#include <iostream>
#include <regex>

using namespace std;

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	void printInventory();
	bool checkIfInventoryIsEmpty();
	void addItem(string item);
	string dropItem(string itemName);

	ItemType getItemType(string itemName);

private:
	const int TOTALSPACE = 10;
	vector<ItemType> items;
};