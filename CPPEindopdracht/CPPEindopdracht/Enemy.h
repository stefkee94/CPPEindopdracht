#pragma once

#include "MapObject.h"
#include "EnemyType.h"

class Enemy : public MapObject
{
public:
	Enemy(EnemyType eType, int floorNumber);
	Enemy();
	virtual ~Enemy();

	int randomNumber(int min, int max);

	virtual void Attack();
	virtual void Hit();

private:
	EnemyType type;

	string getEnemyName(EnemyType type);
};

