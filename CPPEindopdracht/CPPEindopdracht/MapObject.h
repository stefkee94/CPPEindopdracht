#pragma once

#include <string>
#include <random>

using namespace std;

class MapObject
{
public:
	MapObject();
	virtual ~MapObject();

	string getName();
	int getCurrentHp();
	bool isDead();

	virtual void Hit(int damage);
	virtual int Attack(MapObject other);

private:
	int randomNumber(int min, int max);

protected:
	string name;
	int level;
	int currentHp;
	int maxHp;
	int attack;
	int defense;
	const int MAXDEFENSE = 40;
};

