#include "Hero.h"

void Hero::Hit()
{

}

void Hero::Attack()
{

}

void Hero::printInventory()
{
	inventory.printInventory();
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
	attack = 2;
	defense = 1;
	notice = 1;

	inventory.addItem("beer");
}

Hero::~Hero()
{
}