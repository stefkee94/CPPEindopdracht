#include "Chamber.h"
#include <string>

bool forward, right, backwards, left;
int numberOfExits;

int randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void generateRandomChamber(int maxNumberOfExits)
{
	numberOfExits = randomNumber(1, maxNumberOfExits);
}

Chamber::Chamber(int maxNumberOfExits)
{
	generateRandomChamber(maxNumberOfExits);
}


Chamber::~Chamber()
{
}
