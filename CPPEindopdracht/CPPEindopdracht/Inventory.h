#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

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
	vector<string> getAllItems();
	bool hasItem(string itemName);
	void addItem(string item);
	string dropItem(string itemName);

	ItemType getItemType(string itemName);
	string getItemName(ItemType itemType);

private:
	const int TOTALSPACE = 10;
	vector<ItemType> items;
};