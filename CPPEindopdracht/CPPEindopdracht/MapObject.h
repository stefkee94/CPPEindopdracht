#pragma once

#include <string>

class MapObject
{
public:
	MapObject();
	virtual ~MapObject();

protected:
	std::string name;
	int level;
	double current_hp;
	double max_hp;
	double attack;
	double defense;

	virtual void Hit();
	virtual void Attack();
};

