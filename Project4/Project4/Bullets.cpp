#include "Bullets.h"

using namespace std;


// Bullets::Bullets(int x, int y) :Points(x, y)
// {
// 	Bu[0].x = x;
// 	Bu[0].y = y;
// }

Bullets::~Bullets()
{}
void Bullets::BulletsPush_back(int x,int y)
{
	Bu.push_back(Points(x,y));
}

int Bullets::BulletsSize()
{
	return Bu.size();
}

Points Bullets::BulletsValue(int i)
{
	return Bu[i];
}

void Bullets::BulletsTag(int i)
{
	Bu[i].x++;
	Bu[i].y;
}

void Bullets::Bulletsearse(int i)
{
	Bu.erase(Bu.begin() + i);
}