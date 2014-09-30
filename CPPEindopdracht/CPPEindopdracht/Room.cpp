#include "Room.h"
#include <string>

bool forward, right, backwards, left;
int numberOfExits;

int randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void generateRandomRoom()
{
	numberOfExits = randomNumber(1, 4);

}

Room::Room()
{
	generateRandomRoom();
}


Room::~Room()
{
}
