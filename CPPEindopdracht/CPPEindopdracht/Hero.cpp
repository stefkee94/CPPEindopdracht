#include "Hero.h"

void Hero::Hit()
{

}

void Hero::Attack()
{

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

Hero::Hero(std::string name, int level, double current_hp, double max_hp, double attack, double defense, int notice, Inventory inventory)
{
	xPos = 0;
	yPos = 0;
}

Hero::~Hero()
{
}