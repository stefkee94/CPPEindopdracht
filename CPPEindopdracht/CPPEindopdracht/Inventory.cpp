#include "Inventory.h"

//Print the items in your inventory
void Inventory::printInventory()
{
	if (checkIfInventoryIsEmpty())
	{
		cout << endl << "Your inventory is empty" << endl;
		return;
	}

	cout << endl << "Your inventory contains:" << endl;
	
	for (int i = 0; i < TOTALSPACE; ++i)
	{
		if (items[i] == ItemType::GRENADE)
			cout << "grenade" << endl;
		if (items[i] == ItemType::SWORD)
			cout << "sword" << endl;
		if (items[i] == ItemType::BEER)
			cout << "beer" << endl;
		if (items[i] == ItemType::POTION)
			cout << "potion" << endl;
	}

	cout << endl;
}

bool Inventory::checkIfInventoryIsEmpty()
{
	bool temp_cond;
	for (int i = 0; i < TOTALSPACE; ++i)
	{
		if (items[i] == ItemType::NOITEM)
			temp_cond = true;
		else
			return false;
	}
	return temp_cond;
}

bool Inventory::hasItem(string itemName)
{
	ItemType itemType = getItemType(itemName);
	for (int i = 0; i < TOTALSPACE; ++i)
	{
		if (items[i] == itemType)
			return true;
	}
	return false;
}

//return if the item is added or if the inventory is full
void Inventory::addItem(string itemName)
{
	ItemType item = getItemType(itemName);
	if (!(item == ItemType::NOITEM))
	{
		for (int i = 0; i < TOTALSPACE; ++i)
		{
			if (items[i] == ItemType::NOITEM)
			{
				items[i] = item;
				cout << "Item " << itemName << " added to your inventory." << endl;
				return;
			}
		}
		cout << "Item " << itemName << " couldn't be added because the inventory is full" << endl;
	}
	else 
	{
		cout << "Cannot add item " << itemName << "it's invalid" << endl;
	}
}

string Inventory::dropItem(string itemName)
{
	ItemType item = getItemType(itemName);

	for (int i = 0; i < TOTALSPACE; ++i)
	{
		if (items[i] == item)
		{
			items[i] = ItemType::NOITEM;
			return "Item dropped.";
		}
	}

	return "Item not found.";
}

ItemType Inventory::getItemType(string itemName)
{
	if (itemName == "grenade")
		return ItemType::GRENADE;
	if (itemName == "sword")
		return ItemType::SWORD;
	if (itemName == "beer")
		return ItemType::BEER;
	if (itemName == "potion")
		return ItemType::POTION;

	return ItemType::NOITEM;
}

Inventory::Inventory()
{
	items.resize(TOTALSPACE);
	for (int i = 0; i < TOTALSPACE; ++i)
	{
		items[i] = ItemType::NOITEM;
	}
}

Inventory::~Inventory()
{

}