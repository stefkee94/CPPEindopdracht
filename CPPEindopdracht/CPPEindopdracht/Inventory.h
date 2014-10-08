#pragma once
#include <vector>
#include "ItemType.h"
class Inventory
{
public:
	Inventory(int totalSpace, std::vector<ItemType> item_types);
	virtual ~Inventory();
};

