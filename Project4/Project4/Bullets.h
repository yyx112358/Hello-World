#pragma once
#include<vector>
#include "Points.h"

using namespace std;

class Bullets:public Points
{
public:
	Bullets(int x, int y):Points(x, y)//////????
	{
		Bu.push_back(Points(x, y));
	}
	~Bullets();
	void BulletsPush_back(int x,int y); 
	int BulletsSize();
	Points BulletsValue(int i);
	void BulletsTag(int i);
	void Bulletsearse(int i);
protected:
private:
	vector<Points>Bu;
};
