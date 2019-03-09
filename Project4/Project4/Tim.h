#pragma once
#include <ctime>

class Tim
{
public:
	Tim();
	~Tim();
	bool EnemyTime();
	bool MoveTime();
protected:
private:
	int StartTime1 = 0;
	int StartTime2 = 0;
	bool EnemyTim = false;
	bool MoveTim = false;
};
