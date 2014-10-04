#include "Chamber.h"
#include <string>
#include <vector>

bool forward, right, backwards, left;
int numberOfExits;
std::vector<std::string> randomDirections;

int randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void generateRandomChamber(int maxNumberOfExits, std::vector<std::string> directions)
{
	numberOfExits = randomNumber(1, maxNumberOfExits);
	int numberOfDirections = randomNumber(1, directions.size());
	for (int i = 0; i < numberOfDirections; i++) {
		randomDirections.push_back(directions[i]);
	}
}

Chamber::Chamber(int maxNumberOfExits, std::vector<std::string> directions)
{
	generateRandomChamber(maxNumberOfExits, directions);
}

Chamber::~Chamber()
{
}
