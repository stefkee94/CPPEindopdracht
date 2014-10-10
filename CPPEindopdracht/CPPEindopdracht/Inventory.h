#pragma once

#include "ItemType.h"

#include <vector>
#include <iostream>

using namespace std;

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	void printInventory();
	string addItem(string item);
	string dropItem(string itemName);

private:
	const int TOTALSPACE = 10;
	vector<ItemType> items;

	ItemType getItemType(string itemName);
};

