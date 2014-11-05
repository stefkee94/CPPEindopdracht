#include "Hero.h"

void Hero::printInventory()
{
	inventory.printInventory();
}

void Hero::printSkills()
{
	cout << endl << "Level: " << level;
	cout << endl << "Hitpoints: " << currentHp << "/" << maxHp;
	cout << endl << "Experience: " << experience;
	cout << endl << "Attack: " << attack ;
	cout << endl << "Defense: " << defense;
	cout << endl << "Notice: " << notice;
	cout << endl << "Killed enemies: " << killed_enemies << endl << endl;
}

//Returns true if level up
bool Hero::addExperience(int addExperience)
{
	experience += addExperience;

	if (experience >= (10 * level))
	{
		int left = experience % (10 * level);

		level++;
		experience = left;

		return true;
	}

	return false;
}

string Hero::dropItem(string itemName)
{
	return inventory.dropItem(itemName);
}

void Hero::useItem(string itemName)
{
	ItemType itemType = inventory.getItemType(itemName);
	if (itemType != ItemType::NOITEM)
	{
		switch (itemType)
		{
		case ItemType::BEER: case ItemType::POTION:
			fillHp(5);
			break;
		case ItemType::SWORD:
			equipSword(2);
			break;
		default:
			break;
		}

		//After item is used remove from inventory
		removeItemFromInventory(itemName);
	}
	else
		cout << itemName << " is not a valid item to use" << endl;
}

#pragma region gettersAndSetters
int Hero::getXPos()
{
	return xPos;
}

int Hero::getYPos()
{
	return yPos;
}

void Hero::setXPos(int x)
{
	xPos = x;
}

void Hero::setYPos(int y)
{
	yPos = y;
}

int Hero::getExp()
{
	return experience;
}

int Hero::getExpNeeded()
{
	return (10 * level);
}

int Hero::getLevel()
{
	return level;
}

int Hero::getKilledEnemies()
{
	return killed_enemies;
}

void Hero::setKilledEnemies(int amount)
{
	if (amount == 0)
		killed_enemies = 0;
	else
		killed_enemies += amount;
}

void Hero::addAttack()
{
	attack++;
	cout << endl << "Attack raised by 1 -> current attack: " << attack << endl;
}

void Hero::addDefense()
{
	defense++;
	cout << endl << "defense raised by 1 -> current defense: " << defense << endl;
}

void Hero::addNotice()
{
	notice++;
	cout << endl << "notice raised by 1 -> current notice: " << notice << endl;
}

void Hero::addHp()
{
	currentHp = maxHp = maxHp + 5;
	cout << endl << "Hp raised by 5 -> current Hp: " << maxHp << endl;
}

void Hero::addCurrentHp(int amount)
{
	if (getCurrentHp() == getMaxHp())
	{
		cout << "Rest is not needed because hp is full" << endl;
		return;
	}
	else if ((getCurrentHp() + amount) > getMaxHp())
	{
		amount = getMaxHp() - getCurrentHp();
	}

	currentHp += amount;
	cout << getName() << " took some rest, the Hp is healed by " << amount << " and is now " << getCurrentHp() << " from a total of " << getMaxHp() << endl;
}

int Hero::getNotice()
{
	return notice;
}

void Hero::addItem(string itemName)
{
	inventory.addItem(itemName);
}

ItemType Hero::getItemType(string itemName)
{
	return inventory.getItemType(itemName);
}

void Hero::fillHp(int amount)
{
	if (currentHp + amount >= maxHp)
	{
		amount = maxHp - currentHp;
		currentHp = maxHp;
	}
	else
		currentHp += amount;

	cout << endl << "current Hp raised by " << amount << " current Hp is : " << currentHp << " and maximum Hp is : " << maxHp << endl;
}

void Hero::equipSword(int extra_attack)
{
	attack += extra_attack;
	cout << endl << "You equipped your sword, your attack is gained by " << extra_attack << " and is now : " << attack << endl;
}

void Hero::removeItemFromInventory(string itemName)
{
	inventory.dropItem(itemName);
}

#pragma endregion gettersAndSetters

Hero::Hero(string hero_name, string start_item)
{
	//Start position
	xPos = 0;
	yPos = 0;

	//Start values
	name = hero_name;
	level = 1;
	currentHp = maxHp = 5;
	experience = 0;
	attack = 4;
	defense = 2;
	notice = 1;
	killed_enemies = 0;

	inventory.addItem(start_item);
}

Hero::~Hero()
{
}