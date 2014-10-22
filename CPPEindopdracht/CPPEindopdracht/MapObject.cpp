#include "MapObject.h"

int MapObject::randomNumber(int min, int max)
{
	random_device dev;
	default_random_engine dre(dev());
	uniform_int_distribution<int> dist(min, max);
	return dist(dre);
}

int MapObject::Attack(MapObject other) 
{
	/*
	//calculate damage
	*/

	int damage = attack;

	//Loop as long as the defense is
	for (int i = 0; i < other.defense; i++)
	{
		//generate a random number between 1 and 200
		int random = randomNumber(1, 200);

		//if the number equals 5 * i the attack will fail
		if ((5 * i) == random)
			damage = 0;
		/*
		//Because the max defense is set to 40 the maximum that 5 * i can give is 200
		//and because you will max loop 40 times you have a chance of 200/40=5 with max def to get no damage from an attack
		*/
	}

	return damage;
}

void MapObject::Hit(int damage) 
{
	currentHp -= damage;

	if (currentHp < 0) currentHp = 0;
}

#pragma region gettersAndSetters
string MapObject::getName()
{
	return name;
}
int MapObject::getCurrentHp()
{
	return currentHp;
}
bool MapObject::isDead()
{
	if (currentHp == 0) return true;
	return false;
}
#pragma endregion gettersAndSetters

MapObject::MapObject()
{
}


MapObject::~MapObject()
{
}