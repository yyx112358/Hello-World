#include "Tim.h"

Tim::Tim()
	:StartTime1(0)
{}
Tim::~Tim()
{}
bool Tim:: EnemyTime()
{
	if (clock() - StartTime1 > 500)
	{
		StartTime1 = clock();
		return  true;
	}
	else
		return false;
	}
bool Tim:: MoveTime()
{
	if (clock() - StartTime2 > 1000)
	{
		StartTime2 = clock();
		return true;
	}
	else
		return false;
	}

