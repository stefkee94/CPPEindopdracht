#pragma once
#include "MapObject.h"
#include "EnemyType.h"
#include <string>
class Enemy : public MapObject
{
public:
	Enemy(std::string name, EnemyType type, int level, double current_hp, double max_hp, double attack, double defense);
	virtual ~Enemy();
	virtual void Attack();
	virtual void Hit();
};

