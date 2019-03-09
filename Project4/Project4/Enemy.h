#pragma once
#include <vector>
#include "OneEnemy.h"

using namespace std;

class Enemy
{
public:
	vector<OneEnemy>EnemyState;
	int Enemynum = 0;
	Enemy();
	~Enemy();
	char RandomShape();
	void Enemytag(int i);
protected:
private:
};
