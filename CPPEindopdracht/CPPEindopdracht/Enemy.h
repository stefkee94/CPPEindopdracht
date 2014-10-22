#pragma once

#include "MapObject.h"
#include "EnemyType.h"

#include <random>
#include <sstream>

class Enemy : public MapObject
{
public:
	Enemy(EnemyType eType, int floorNumber, int number);
	Enemy();
	virtual ~Enemy();

	int randomNumber(int min, int max);

	int getEnemyLevel();

private:
	EnemyType type;

	string getEnemyName(EnemyType type);
};

