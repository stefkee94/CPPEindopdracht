#pragma once
#include "MapObject.h"
#include "Inventory.h"
#include <string>
class Hero : public MapObject
{
public:
	Hero(std::string name, int level, double current_hp, double max_hp, double attack, double defense, int notice, Inventory inventory );
	virtual ~Hero();
private:
	virtual void Hit();
	virtual void Attack();
};

