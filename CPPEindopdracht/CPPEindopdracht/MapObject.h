#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

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
	void setCurrentHp(int amount);
	int getMaxHp();
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

