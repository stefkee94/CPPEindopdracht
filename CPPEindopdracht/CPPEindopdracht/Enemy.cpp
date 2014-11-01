#include "Enemy.h"

int Enemy::randomNumber(int min, int max)
{
	random_device dev;
	default_random_engine dre(dev());
	uniform_int_distribution<int> dist(min, max);
	return dist(dre);
}

string Enemy::getEnemyName(EnemyType type)
{
	if (type == EnemyType::RAT)
		return "rat";
	if (type == EnemyType::DRAGON)
		return "dragon";
	if (type == EnemyType::BOSS)
		return "boss";

	return "Unknown enemy";
}

int Enemy::getEnemyLevel()
{
	return level;
}

Enemy::Enemy(EnemyType eType, int floorNumber, int number)
{
	type = eType;

	std::ostringstream oss;
	oss << getEnemyName(type) << number;
	name = oss.str();

	level = randomNumber(1 , 2) * floorNumber;
	currentHp = maxHp = (5 * level);
	attack = (1 * level);
	defense = (1 * level);
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}