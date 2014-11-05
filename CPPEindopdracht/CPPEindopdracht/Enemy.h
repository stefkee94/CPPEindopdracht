#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "MapObject.h"
#include "EnemyType.h"

#include <random>
#include <sstream>

class Enemy : public MapObject
{
public:
	Enemy(EnemyType eType, int floorNumber, int number);
	Enemy();

	Enemy(const Enemy& other);
	Enemy& operator=(const Enemy& other);

	virtual ~Enemy();

	int randomNumber(int min, int max);

	int getEnemyLevel();

private:
	EnemyType type;

	string getEnemyName(EnemyType type);
};

