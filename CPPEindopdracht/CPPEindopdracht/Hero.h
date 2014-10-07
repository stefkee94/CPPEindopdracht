#pragma once
#include "MapObject.h"
class Hero : public MapObject
{
public:
	Hero();
	virtual ~Hero();
private:
	virtual void Attack();
};

