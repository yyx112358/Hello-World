#pragma once
#include <vector>
#include "Points.h"

using namespace std;

class Enemy
{
public:
	vector<Points>EnemyState;
	int Enemynum = 0;
	Enemy();
	~Enemy();
	char RandomShape();
	void Enemytag(int i);
protected:
private:
};
