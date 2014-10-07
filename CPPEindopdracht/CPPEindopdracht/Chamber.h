#pragma once
#include <vector>

class Chamber
{
public:
	Chamber(int x, int y);
	~Chamber();

private:
	bool north, east, south, west;
	int randomNumber(int min, int max);
	void generateRandomChamber(int x, int y);
};

