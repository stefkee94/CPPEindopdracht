#include "Hero.h"

void Hero::printInventory()
{
	inventory.printInventory();
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
#pragma endregion gettersAndSetters

Hero::Hero()
{
	//Start position
	xPos = 0;
	yPos = 0;

	//Start values
	name = "The one";
	level = 1;
	currentHp = maxHp = 10;
	experience = 0;
	attack = 4;
	defense = 2;
	notice = 1;

	inventory.addItem("beer");
}

Hero::~Hero()
{
}