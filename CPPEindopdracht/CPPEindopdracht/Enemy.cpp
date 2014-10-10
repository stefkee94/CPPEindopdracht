#include "Enemy.h"

int Enemy::randomNumber(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

void Enemy::Attack()
{

}

void Enemy::Hit()
{

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

Enemy::Enemy(EnemyType eType, int floorNumber)
{
	type = eType;
	name = getEnemyName(type);
	level = randomNumber(1 , floorNumber);
	currentHp = maxHp = (10 * level);
	attack = (2 * level);
	defense = (1 * level);
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}