#pragma once
#include <vector>

class Chamber
{
public:
	Chamber(int x, int y, int floor_number);
	~Chamber();

private:
	bool north, east, south, west;
	int randomNumber(int min, int max);
	void generateRandomChamber(int x, int y);
	void generateRandomEnemy(int floor_number);
};

