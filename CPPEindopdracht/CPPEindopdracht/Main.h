#pragma once
#include "Map.h"

class Main
{

public:
	Main();
	~Main();

private:
	Map* map;
	bool playing;
	int horizontal = 10;
	int vertical = 10;
	int floorNumber = 5;
};

