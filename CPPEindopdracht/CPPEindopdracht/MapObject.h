#pragma once

#include <string>

using namespace std;

class MapObject
{
public:
	MapObject();
	virtual ~MapObject();

	string getName();

protected:
	string name;
	int level;
	int currentHp;
	int maxHp;
	int attack;
	int defense;

	virtual void Hit();
	virtual void Attack();
};

