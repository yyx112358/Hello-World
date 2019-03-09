#include "Enemy.h"
#include <vector>


Enemy::Enemy()
{}
Enemy::~Enemy()
{}
char Enemy::RandomShape()
{
	vector<char> RandomLibrary{ 'q','r','e' };
	char rs = (RandomLibrary[rand() % 3]);
	return rs;
}
void Enemy::Enemytag(int i)
{
	switch (EnemyState[i].shape)
	{
	case 'q':(EnemyState[i].x)--; (EnemyState[i].y)--; break;
	case 'e':(EnemyState[i].x)--; break;
	case 'r':(EnemyState[i].x)--; (EnemyState[i].y)++; break;
	default:
		break;
	}
}
